class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>Ans;
        for(int i=1;i<=numRows;i++){
            vector<int>vec;
            for(int j=1;j<=i;j++){
                if(j==1 || j==i){
                    vec.push_back(1);
                }
                else{
                    if(i>2){
                        vec.push_back(Ans[i-2][j-1]+Ans[i-2][j-2]);
                    }
                }
            }
            Ans.push_back(vec);
        }
        return Ans;
    }
};