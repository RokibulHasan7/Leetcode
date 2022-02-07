class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        bool ok = false;
        string t = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                reverse(t.begin(), t.end());
                ans += t;
                ans += " ";
                t.clear();
            }
            else{
                t += s[i];
            }
        }
        reverse(t.begin(), t.end());
        ans += t;
        return ans;
    }
};