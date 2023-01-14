class Solution {
public:
    void dfs(int u, vector<char> &st, vector<int> &visited, vector<vector<int>> adj){
        visited[u] = 1;
        st.push_back(char(u + 'a'));
       
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
            if(visited[v] == 0){
                dfs(v, st, visited, adj);
            }
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        string Ans = "";
        vector<vector<int>> adj(26);
        vector<int> visited(26, 0);
        map<int, int> mp;

        for(int i = 0; i < s1.size(); i++){
            int u = s1[i] - 'a';
            int v = s2[i] - 'a';
            mp[u]++; mp[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u); 
        }

        map<char, char> dfsMap;
        for(int i = 0; i < 26; i++){
            if(mp[i] > 0 && visited[i] == 0){
                vector<char> st;
                dfs(i, st, visited, adj);
                for(int j = 0; j < st.size(); j++){   
                    dfsMap[st[j]] = st[0];
                }
            }
        }

        for(int i = 0; i < baseStr.size(); i++){
            if(dfsMap[baseStr[i]] == 0){
                Ans += baseStr[i];
            }
            else{
                Ans += dfsMap[baseStr[i]];
            }
        }
        return Ans;
    }
};
