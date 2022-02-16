class Solution {
public:
    typedef pair<int, int> iPair;
    #define INF 1e9 + 7
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, int>> adj[n];
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }
        
        priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
 
        int src = 0; // Taking vertex 0 as source
 
        // Create a vector for keys and initialize all
        // keys as infinite (INF)
        vector<int> key(n, INF);
 
        // To store parent array which in turn store MST
        vector<int> parent(n, -1);
 
        // To keep track of vertices included in MST
        vector<bool> inMST(n, false);
 
        // Insert source itself in priority queue and initialize its key as 0.
        pq.push(make_pair(0, src));
        key[src] = 0;
 
        
        while (!pq.empty()){
            // The first vertex in pair is the minimum key vertex, extract it from priority queue.
            // vertex label is stored in second of pair (it has to be done this way to keep the vertices
            // sorted key (key must be first item  in pair)
            
            int u = pq.top().second;
            pq.pop();
 
            //Different key values for same vertex may exist in the priority queue.
            //The one with the least key value is always processed first.
            //Therefore, ignore the rest.
            if(inMST[u] == true){
                continue;
            }
       
            inMST[u] = true; // Include vertex in MST
 
            // Traverse all adjacent of u
            for (auto x : adj[u]){
                // Get vertex label and weight of current adjacent of u.
                int v = x.first;
                int weight = x.second;
 
                // If v is not in MST and weight of (u,v) is smaller than current key of v.
                
                if (inMST[v] == false && key[v] > weight){
                    // Updating key of v
                    key[v] = weight;
                    pq.push(make_pair(key[v], v));
                    parent[v] = u;
                }
            }
        }
        
        // Calculate total weight of MST
        int Ans = 0;
        for(int i = 0; i < n; i++){
            Ans += key[i];
        }
        
        return Ans;
    }
};
