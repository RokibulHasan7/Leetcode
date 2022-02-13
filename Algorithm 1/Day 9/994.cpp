class Solution {
public:
    int Ans = 0;
    void BFS(vector<vector<int>>& grid, vector<vector<int>>& level, queue<pair<int, int>>& q, int row, int col){
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        
        while(!q.empty()){
            pair<int, int> tmp = q.front();
            q.pop();
            Ans = max(Ans, level[tmp.first][tmp.second]);
            
            for(int i = 0; i < 4; i++){
                int x = tmp.first + dir[i][0];
                int y = tmp.second + dir[i][1];
                
                if(x >= 0 && y >= 0 && x < row && y < col && grid[x][y] != 0){
                    if(level[x][y] > level[tmp.first][tmp.second] + 1){
                        level[x][y] = level[tmp.first][tmp.second] + 1;
                        q.push({x, y});
                    }
                }
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int>>level(row, vector<int> (col, INT_MAX));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                    level[i][j] = 0;
                }
            }
        }
        
        BFS(grid, level, q, row, col);
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                //cout<<level[i][j]<<" ";
                if(level[i][j] == INT_MAX && grid[i][j] == 1){
                    return -1;
                }
            }
            //cout<<endl;
        }
        return Ans;
        
    }
};