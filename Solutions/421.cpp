class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, mask = 0;
        
        unordered_set<int> st;
        for(int i = 31; i >= 0; i--){
            mask |= (1 << i);
            int tmp = ans | (1 << i);
            for(int j = 0; j < n; j++){
                int num = nums[j] & mask;
                if(st.find(num ^ tmp) != st.end()){
                    ans = tmp;
                }
                st.insert(num);
            }
            st.clear();
        }
        
        return ans;
    }
};
