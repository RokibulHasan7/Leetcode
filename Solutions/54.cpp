class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> Ans;
        int n = matrix.size();
        int m = matrix[0].size();
        int p = 0, q = 0;
        while(p < n && q < m){
            for(int i = q; i < m; i++){
                Ans.push_back(matrix[p][i]);
            }
            p++;
            
            for(int i = p; i < n; i++){
                Ans.push_back(matrix[i][m - 1]);
            }
            m--;
            
            if(p < n){
                for(int i = m - 1; i >= q; i--){
                    Ans.push_back(matrix[n - 1][i]);
                }
                n--;
            }
            
            if(q < m){
                for(int i = n - 1; i >= p; i--){
                    Ans.push_back(matrix[i][q]);
                }
                q++;
            }
        }
        
        return Ans;
    }
};
