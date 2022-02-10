class Solution {
public:
    bool check(vector<int>& position, int m, int mid){
        int n = position.size();
        int last = position[0];
        int cnt = 1;
        for(int i = 1; i < n && cnt < m; i++){
            if(position[i] >= (mid + last)){
                last = position[i];
                cnt++;
            }
        }
        if(cnt == m){
            return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int l = 0, r = position[n - 1], mid;
        int ans = 0;
        while(l < r){
            mid = (l + r) / 2;
            if(check(position, m, mid)){
                ans = max(ans, mid);
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        return ans;
    }
};
