class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> vec;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = n - 1;  j >= 0; j--){
                if(grid[i][j] == 1){
                    break;
                }
                cnt++;
            }
            vec.push_back(cnt);
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            int curr = i;
            int req = n - 1 - i;
            while(curr < n && vec[curr] < req){
                curr++;
            }
            
            if(curr == n){
                return -1;
            }
            
            ans += curr - i;
            
            while(curr){
                vec[curr] = vec[curr - 1];
                curr--;
            }
        }
        
        return ans;
    }
};
