class Solution {
public:
    int dRow[4] = { 0, 1, 0, -1 };
    int dCol[4] = { -1, 0, 1, 0 };
    bool vis[51][51];
    int Ans = 0;
    int cnt = 0;
    
    void dfs(vector<vector<int>>& grid, int sr, int sc){
        cnt++;
        vis[sr][sc] = true;
        for(int i = 0; i < 4; i++){
            int x = dRow[i] + sr;
            int y = dCol[i] + sc;
            if(x < grid.size() && y < grid[0].size() && vis[x][y] == false && grid[x][y] == 1){
                dfs(grid, x, y);
            }
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        memset(vis, false, sizeof(vis));
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1 && vis[i][j] == false){
                    cnt = 0;
                    dfs(grid, i, j);
                    Ans = max(Ans, cnt);
                }
            }
        }
        
        return Ans;
    }
};