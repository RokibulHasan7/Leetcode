class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>mx,mn;
        int mnn,mxx;
        for(int i = 0; i < prices.size(); i++){
            if(i==0){
                mn.push_back(prices[i]);
                mnn = prices[i];
                continue;
            }
            mnn = min(mnn, prices[i]);
            mn.push_back(mnn);
        }
        for(int i = prices.size()-1; i >= 0; i--){
            if(i==prices.size()-1){
                mx.push_back(prices[i]);
                mxx = prices[i];
                continue;
            }
            mxx = max(mxx, prices[i]);
            mx.push_back(mxx);
        }
        reverse(mx.begin(),mx.end());
        int ans = 0;
        for(int i = 0; i < prices.size(); i++){
            int diff = mx[i]-mn[i];
            ans = max(ans, diff);
        }
        return ans;
    }
};