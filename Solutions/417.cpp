class Solution {
public:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    void DFS(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int i, int j, int prev){
        if(i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size()) return;
        if(heights[i][j] < prev || ocean[i][j] == true) return;
        
        ocean[i][j] = true;
        for(int p = 0; p < 4; p++){
            DFS(heights, ocean, i + dir[p][0], j + dir[p][1], heights[i][j]);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> pacific(n, vector<bool> (m, false));
        vector<vector<bool>> atlantic(n, vector<bool> (m, false));
        
        for(int i = 0; i < n; i++){
            DFS(heights, pacific, i, 0, INT_MIN);
            DFS(heights, atlantic, i, m - 1, INT_MIN);
        }
        
        for(int i = 0; i < m; i++){
            DFS(heights, pacific, 0, i, INT_MIN);
            DFS(heights, atlantic, n - 1, i, INT_MIN);
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(atlantic[i][j] && pacific[i][j]){
                    ans.push_back({i, j});
                }
            }
        }
        
        return ans;
    }
};
