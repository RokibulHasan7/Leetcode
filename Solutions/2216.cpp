class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int cnt = 0;
        while(1){
            bool ok = false;
            int flag = 0;
            for(int i = 0; i < nums.size(); i++){
                if(i + 1 < nums.size() && (i - flag) % 2 == 0 && nums[i] == nums[i + 1]){
                    nums[i] = -1;
                    cnt++; flag++;
                    ok = true;
                }
            }
            vector<int>vec;
            for(auto x: nums){
                if(x != -1){
                    vec.push_back(x);
                }
            }
            
            nums = vec;
            if(!ok){
                break;
            }
        }
        
        if(nums.size() % 2 == 0){
            return cnt;
        }
        return cnt + 1;
    }
};
