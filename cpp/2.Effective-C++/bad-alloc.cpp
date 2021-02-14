#include <iostream>
#include <exception>
#include <cstdlib>


int main() {
	unsigned int count = 0;
	int ** pGiantArray = new int*[1000]();
	// int** pGiantArray = (int**) calloc(1000, sizeof(int*));
	for(int i = 0; i < 1000; ++i)
		pGiantArray[i] = nullptr;

	while (1) {
		try {
			pGiantArray[count] = new int[10000000L];
			++count;
		} catch (std::exception &e) {
			std::cout << "standard exception:" << e.what() << std::endl;
			std::cout << "abort after allocating " << count << " giant arrays.\n";
			count--;
			for(; count >= 0; --count) {
				delete [] pGiantArray[count];
				std::cout << "deleted giant array: " << count << std::endl;
			}
			// segmentation fault
			delete [] pGiantArray;
			std::cout << "freed giant array holder\n";
			return -1;
		}
	}
	for(; count >= 0; --count)
		delete [] pGiantArray[count];
	// free(pGiantArray);
	delete [] pGiantArray;
	return 0;
}

