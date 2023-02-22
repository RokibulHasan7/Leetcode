class Solution {
public:
    bool check(vector<int>& weights, int mid, int days){
        int reqDays = 1;
        int sum = 0;
        for(auto x: weights){
            if(sum + x > mid){
                reqDays++;
                sum = 0;
            }
            sum += x;
        }

        if(reqDays > days){
            return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int ans = 0;
        int sum = 0;
        for(auto x: weights){
            ans = max(ans, x);
            sum += x;
        }
        int left = ans, right = sum;
        while(left <= right){
            int mid = (left + right) / 2;
            if(check(weights, mid, days)){
                ans = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return ans;
    }
};
