#include <queue>
#include <vector>
using namespace std;
class Solution
{
public:
  bool canVisitAllRooms(vector<vector<int>>& rooms)
  {
    vector<bool> visited(rooms.size(), false);
    dfs(0, rooms, visited);
    for(auto b:visited)
      if(!b)
        return false;
    return true;
  }

private:
  void dfs(int room,
           vector<vector<int>>& rooms,
           vector<bool>& visited)
  {
    if(visited[room])
      return;
    visited[room] = true;
    for (int i : rooms[room])
      dfs(i, rooms, visited);
  }
};
