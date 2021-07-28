#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

void markIslands (vector<vector<int>> &grid, int i, int j, int rows, int cols) {
  if(i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] != 1) {
    return;
  } 
  grid[i][j] = 2;
  markIslands(grid, i+1, j, rows, cols);
  markIslands(grid, i, j+1, rows, cols);
  markIslands(grid, i-1, j, rows, cols);
  markIslands(grid, i, j-1, rows, cols);
} 

int solution (vector<vector<int>> &grid) {
  int rows = grid.size();
  int cols = grid[0].size();
  int count = 0;
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      if(grid[i][j] == 1) {
        markIslands(grid, i, j, rows, cols);
        count = count + 1;
      }
    }
  }
  return count;
}

int main() {
  vector<vector<int>> grid = {{1, 1, 0, 0}, {1, 1, 0, 1}, {0, 0, 0, 0}, {1, 0, 0, 1}};
  cout << solution(grid);
  return 0;
}