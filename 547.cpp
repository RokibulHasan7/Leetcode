class Solution {
public:
    vector<int>adj[201];
    int vis[201] = {0};
  
    void dfs(int u){
        vis[u] = 1;
        for(auto v: adj[u]){
            if(vis[v] == 0){
                dfs(v);
            }
        }
    }
  
    int findCircleNum(vector<vector<int>>& isConnected) {
        for(int i = 0; i < isConnected.size(); i++){
            for(int j = 0; j < isConnected.size(); j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < isConnected.size(); i++){
            if(vis[i] == 0){
                dfs(i);
                ans++;
            }
        }
        return ans;
    }
};
