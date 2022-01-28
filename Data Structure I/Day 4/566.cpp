class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int row = mat.size();
        int col = mat[0].size();
        if(row*col != r*c){
            return mat;
        }
        vector<vector<int>>Ans;
        int p = 0, q = 0;
        vector<int>vec;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                vec.push_back(mat[i][j]);
                q++;
                if(q == c){
                    Ans.push_back(vec);
                    vec.clear();
                    q = 0;
                }
            }
        }
        return Ans;
    }
};