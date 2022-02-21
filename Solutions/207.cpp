class Solution {
public:
    vector<int> adj[100005];
    int vis[100005];
    bool dfs(vector<vector<int>>& prerequisites, int u){
        if(vis[u] == 1){
            return true;
        }
        if(vis[u] == -1){
            return false;
        }
        
        vis[u] = -1;
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
            if(dfs(prerequisites, v) == false){
                return false;
            }
        }
        
        vis[u] = 1;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < numCourses; i++){
            if(dfs(prerequisites, i) == false){
                return false;
            }
        }
        
        return true;
    }
};
