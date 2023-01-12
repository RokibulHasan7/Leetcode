class Solution {
public:
    vector<int> dfs(int currNode, int parentNode, string &labels, vector<vector<int>> &adj, vector<int> &Ans){
        vector<int> parentLabel(26);
        parentLabel[labels[currNode]- 'a'] = 1;
        for(int i = 0; i < adj[currNode].size(); i++){
            int child = adj[currNode][i];
            if(child == parentNode){
                continue;
            }
            vector<int> childLabel = dfs(child, currNode, labels, adj, Ans);
            for(int i = 0; i < 26; i++){
                parentLabel[i] += childLabel[i];
            }
        }
        Ans[currNode] = parentLabel[labels[currNode] - 'a'];
        return parentLabel;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        vector<int> Ans(n, 0);
        
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0, -1, labels, adj, Ans);
        return Ans;
    }
};
