class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int sz1 = nums1.size();
        int sz2 = nums2.size();
        map<int,int>mp1, mp2;
        for(int i = 0; i < sz1; i++){
            mp1[nums1[i]]++;
        }
        for(int i = 0; i < sz2; i++){
            mp2[nums2[i]]++;
        }
        vector<int>ans;
        for(int i = 0; i <= 1000; i++){
            if(mp1[i] > 0 && mp2[i] > 0){
                int tmp = min(mp1[i],mp2[i]);
                for(int j = 0; j < tmp; j++){
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};