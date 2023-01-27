class Solution {
public:
    bool dfs(string &str, unordered_map<string, int> &mp, int idx){
        if(idx == str.size()){
            return true;
        }
        string tmp = "";
        for(int i = idx; i < str.size(); i++){
            tmp += str[i];
            if(mp[tmp] > 0 && dfs(str, mp, i + 1)){
                return true;
            }
        }

        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_map<string, int> mp;
        for(auto str: words){
            mp[str]++;
        }
        vector<string> Ans;
        for(auto str: words){
            mp[str]--;
            if(dfs(str, mp, 0)){
                Ans.push_back(str);
            }
            mp[str]++;
        }

        return Ans;
    }
};

/*
Time complexity:
- size of words = N
- size of word = M
- To generate all substring of a string = M^3
- So total time complexity = O(N * m^3)


Space complexity: O(N*M)
*/
