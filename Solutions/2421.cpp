class DSU {
public:
    vector<int> rank;
    vector<int> parent;
    DSU(int n){
        rank.resize(n);
        parent.resize(n);
        for(int i = 0; i < n; i++){
            rank[i] = 0;
            parent[i] = i;
        }
    }

    int findParent(int x){
        if(x == parent[x]){
            return x;
        }
        return parent[x] = findParent(parent[x]);
    }

    void makeUnion(int x, int y){
        int p1 = findParent(x);
        int p2 = findParent(y);
        if(p1 != p2){
            if(rank[p1] > rank[p2]){
                parent[p2] = p1;
                rank[p1] += rank[p2];
            }
            else{
                parent[p1] = p2;
                rank[p2] += rank[p1];
            }
        }
    }
};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<int> adj[n];
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        DSU dsu(n);
        map<int, vector<int>> valToNode;
        for(int i = 0; i < n; i++){
            valToNode[vals[i]].push_back(i); // 3:[1,4]
        }

        int Ans = 0;
        for(auto[value, nodes]: valToNode){
            for(auto node: nodes){
                for(auto neighbour: adj[node]){
                    if(vals[neighbour] <= vals[node]){
                        dsu.makeUnion(node, neighbour);
                    }
                }
            }

            unordered_map<int, int> freqOfParent;
            for(auto node: nodes){
                freqOfParent[dsu.findParent(node)]++;
            }
            for(auto it: freqOfParent){
                int cnt = it.second * (it.second + 1) / 2;
                Ans += cnt;
            }
        }

        return Ans;
    }
};

// Time complexity: O(NlogN);
// Space complexity: O(N)

/*
1. Least value
2. adj node (<= val)
3. freq of parent
4. (n*(n+1))/2 where n = freq of parent
*/
