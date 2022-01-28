class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int row_num = -1;
        for(int i = 0; i < row; i++){
            if(matrix[i][0] <= target && matrix[i][col-1]>= target){
                row_num = i;
                break;
            }
        }
        bool ok = false;
        if(row_num == -1){
            return false;
        }
        else{
            for(int i = 0; i < col; i++){
                if(matrix[row_num][i] == target){
                    ok = true;
                    break;
                }
            }
            return ok;
        }
    }
};