class Solution {
public:
    void BFS(vector<vector<int>>& mat, vector<vector<int>>& dist, queue<pair<int, int>> &q, int row, int col){
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        
        while(!q.empty()){
            pair<int, int> tmp = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int x = tmp.first + dir[i][0];
                int y = tmp.second + dir[i][1];
                
                if(x >= 0 && y >= 0 && x < row && y < col){
                    if(dist[x][y] > dist[tmp.first][tmp.second] + 1){
                        dist[x][y] = dist[tmp.first][tmp.second] + 1;
                        q.push({x, y});
                    }
                }
            }
        }
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        
        vector<vector<int>> dist(row, vector<int>(col, INT_MAX));
        queue<pair<int, int>> q;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(mat[i][j] == 0){
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        BFS(mat, dist, q, row, col);
        
        return dist;
    }
};