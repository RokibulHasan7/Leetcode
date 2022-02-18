class Solution {
public:
    int maxArea(vector<int>& height) {
        int Ans = 0;
        int l = 0, r = height.size() - 1;
        while(l < r){
            int tmp = min(height[l], height[r]) * (r - l);
            Ans = max(Ans, tmp);
            if(height[l] > height[r]){
                r--;
            }
            else{
                l++;
            }
        }
        
        return Ans;
    }
};
