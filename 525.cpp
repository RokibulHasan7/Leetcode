class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int arr[nums.size() + 1];
        int zero = 0, one = 0, ans = 0;
        unordered_map<int, int> umap;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                zero++;
            }
            else{
                zero--;
            }
            
            if(zero == 0){
                ans = i + 1;
            }
            
            if(umap.find(zero) == umap.end()){
                umap[zero] = i;
            }
            else{
                //cout<< - 1<<endl;
                ans = max(ans, i - umap[zero]);
            }
            //cout<<zero<<endl;
        }
        return ans;
    }
};

