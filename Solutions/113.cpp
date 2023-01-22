class Solution {
public:
    bool isPalindrome(string str, int i, int j){
        while(i < j){
            if(str[i] != str[j]){
                return false;
            }
            i++; j--;
        }
        return true;
    }
    void backtrack(vector<vector<string>> &Ans, vector<string> curr, string s, int ind){
        if(ind >= s.size()){
            Ans.push_back(curr);
            return;
        }
        for(int i = ind; i < s.size(); i++){
            if(isPalindrome(s, ind, i)){
                curr.push_back(s.substr(ind, i - ind + 1));
                backtrack(Ans, curr, s, i + 1);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> Ans;
        vector<string> curr;
        backtrack(Ans, curr, s, 0);
        return Ans;
    }
};
