class FindSumPairs {
public:
    map<int, int> mp1, mp2;
    vector<int> vec1, vec2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        vec1 = nums1;
        vec2 = nums2;
        for(auto x: nums1){
            mp1[x]++;
        }
        
        for(auto x: nums2){
            mp2[x]++;
        }
    }
    
    void add(int index, int val) {
        mp2[vec2[index]]--;
        vec2[index] += val;
        mp2[vec2[index]]++;
    }
    
    int count(int tot) {
        int cnt = 0;
        for(int i = 0; i < vec1.size(); i++){
            if(mp2[tot - vec1[i]] != 0){
                cnt += mp2[tot - vec1[i]];
            }
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
