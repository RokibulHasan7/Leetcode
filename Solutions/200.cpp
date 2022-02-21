class Solution {
public:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void DFS(vector<vector<char>>& grid, vector<vector<bool>>& vis, int i, int j){
        vis[i][j] = true;
        
        for(int p = 0; p < 4; p++){
            int x = i + dir[p][0];
            int y = j + dir[p][1];
            if(x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && 
               grid[x][y] == '1' && vis[x][y] == false){
                DFS(grid, vis, x, y);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' && vis[i][j] == false){
                    DFS(grid, vis, i, j);
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};
