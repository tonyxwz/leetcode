
class File
{
public:
  File();
  void open();

private:
  const char* name;
};

// virtual inheriance of File
// this tells the compiler that only one copy of members from file is needed.
class InputFile : virtual public File
{
public:
  InputFile()
    : File()
  {}
  void read(char*);
};

class OutputFile : virtual public File
{
public:
  OutputFile()
    : File()
  {}
  void write(const char*);
};

class IOFile
  : public InputFile
  , OutputFile
{
public:
  // question: how should IOFile be initialized?
  // answer: to initializing virtual base class should be the responsibility of
  // the end class, in this case IOFile. InputFile and OutputFile initialization
  // of File are ignored.
  IOFile()
    : File()
    , InputFile()
    , OutputFile()
  {}
};
