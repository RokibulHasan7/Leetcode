class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>ans;
        int i=0,j=0,k=0;
        if(m==0){
            nums1.push_back(1000000001);
        }
        if(n==0){
            nums2.push_back(1000000001);
        }
        while(i<m || j<n || k<m+n){
            if(i==m){
                if(nums1.size()>m){
                    nums1[i]= 1000000001; 
                }
                else{
                    nums1.push_back(1000000001);
                }
            }
            if(j==n){
                if(nums2.size()>n){
                    nums2[j]= 1000000001; 
                }
                else{
                    nums2.push_back(1000000001);
                }
            }
            if(nums1[i] < nums2[j]){
                ans.push_back(nums1[i]);
                i++; k++;
            }
            else if(nums1[i] > nums2[j]){
                ans.push_back(nums2[j]);
                j++; k++;
            }
            else{
                ans.push_back(nums1[i]);
                i++; k++;
                if(k<m+n){
                    ans.push_back(nums2[j]);
                    j++; k++;
                }
            }
        }
        nums1 = ans;
    }
};