class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            unordered_map<char, int> mp;
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    continue;
                }
                if(mp[board[i][j]]){
                    return false;
                }
                mp[board[i][j]]++;
            }
        }
        
        for(int j = 0; j < 9; j++){
            unordered_map<char, int> mp;
            for(int i = 0; i < 9; i++){
                if(board[i][j] == '.'){
                    continue;
                }
                if(mp[board[i][j]]){
                    return false;
                }
                mp[board[i][j]]++;
            }
        }
       
        for(int i = 0; i < 9; i += 3){
            for(int j = 0; j < 9; j += 3){
                unordered_map<char, int> mp;
                for(int p = i; p < i + 3; p++){
                    for(int q = j; q < j + 3; q++){
                         if(board[p][q] == '.'){
                             continue;
                         }
                         if(mp[board[p][q]]){
                             return false;
                         }
                         mp[board[p][q]]++;
                    }
                }
            }
        }
        return true;
    }
};