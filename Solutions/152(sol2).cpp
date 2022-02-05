class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_soFar = INT_MIN;
        int max_endingHere = 1;
        
        for(int i = 0; i < nums.size(); i++){
            max_endingHere = max_endingHere * nums[i];
            max_soFar = max(max_soFar, max_endingHere);
            if(max_endingHere == 0){
                max_endingHere = 1;
            }
        }
        
        max_endingHere = 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            max_endingHere = max_endingHere * nums[i];
            max_soFar = max(max_soFar, max_endingHere);
            if(max_endingHere == 0){
                max_endingHere = 1;
            }
        }
        
        return max_soFar;
    }
};
