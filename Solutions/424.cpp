class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        map<char, int> mp;
        int Ans = 1; int mx = 0;
        int j = 0;
        for(int i = 0; i < n; i++){
            mp[s[i]]++;
            for(auto x: mp){
                mx = max(mx, x.second);
            }
            if((i - j + 1) - mx > k){
                while((i - j + 1) - mx > k){
                    mp[s[j]]--;
                    j++;
                }
            }
            else{
                Ans = max(Ans, (i - j + 1));
            }
        }
        
        return Ans;
    }
};
