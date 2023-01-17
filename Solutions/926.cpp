class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int cnt = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0'){
                cnt++;
            }
        }
        int Ans = cnt;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1'){
                cnt++;
            }
            else{
                cnt--;
                Ans = min(Ans, cnt);
            }
        }
        return Ans;
    }
};
