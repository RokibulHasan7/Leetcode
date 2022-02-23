class Solution {
public:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool ok = false;
    void DFS(vector<vector<char>>& board, string word, int idx, int i, int j, int n, int m){
        board[i][j] = '#';
        if(idx >= word.size() - 1){
            ok = true;
            return;
        }
        
        for(int p = 0; p < 4; p++){
            int x = i + dir[p][0];
            int y = j + dir[p][1];
            if(x >= 0 && y >= 0 && x < n && y < m && 
               board[x][y] == word[idx + 1]){
                DFS(board, word, idx + 1, x, y, n, m);
            }
        }
        board[i][j] = word[idx];
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0]){
                    ok = false;
                    DFS(board, word, 0, i, j, n, m);
                    
                    if(ok){
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};
