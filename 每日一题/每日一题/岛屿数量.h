#include<iostream>
#include<vector>
using namespace std;

//class Solution {
//public:
//	int numIslands(vector<vector<char>>& grid) {
//		int m = grid.size(),n=grid[0].size(),res=0;
//		if (grid.empty() || grid[0].empty()) {
//			return 0;
//		}
//		vector<vector<bool>> visited(m, vector<bool>(n,false));
//
//		for (size_t i = 0; i < grid.size(); i++)
//		{
//			for (size_t j = 0; j < grid[i].size(); j++)
//			{
//				if (grid[i][j] == '1' && !visited[i][j]) {
//					numIslandsDFS(grid,visited,i,j);
//				}
//				res++;
//			}
//		}
//		return res;
//	}
//	void numIslandsDFS(vector<vector<char>>& grid,vector<vector<bool>> visited, int x, int y)
//	{
//		if (x<0 || x>= grid.size()) return;
//		if (y < 0 || y >= grid[0].size()) return;
//		if (grid[x][y] !='1' && visited[x][y]) return;
//		grid[x][y] = true;
//		numIslandsDFS(grid, visited, x - 1, y);
//		numIslandsDFS(grid, visited, x + 1, y);
//		numIslandsDFS(grid, visited, x, y - 1);
//		numIslandsDFS(grid, visited, x, y + 1);
//	}
//};


class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty() || grid[0].empty()) return 0;
		int m = grid.size(), n = grid[0].size(), res = 0;
		vector<vector<bool>> visited(m, vector<bool>(n,false));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == '0' || visited[i][j]) continue;
				numIslandsDFS(grid, visited, i, j);
				++res;
			}
		}
		return res;
	}
	void numIslandsDFS(vector<vector<char>> & grid, vector<vector<bool>> & visited, int x, int y) {
		if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == '0' || visited[x][y]) return;
		visited[x][y] = true;
		numIslandsDFS(grid, visited, x - 1, y);
		numIslandsDFS(grid, visited, x + 1, y);
		numIslandsDFS(grid, visited, x, y - 1);
		numIslandsDFS(grid, visited, x, y + 1);
	}
};