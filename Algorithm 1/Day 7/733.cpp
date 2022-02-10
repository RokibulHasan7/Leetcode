class Solution {
public:
    int dRow[4] = { 0, 1, 0, -1 };
    int dCol[4] = { -1, 0, 1, 0 };
    bool vis[51][51];
    int Ans[51][51];
    
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor){
        vis[sr][sc] = true;
        Ans[sr][sc] = newColor;
        for(int i = 0; i < 4; i++){
            int x = dRow[i] + sr;
            int y = dCol[i] + sc;
            if(x < image.size() && y < image[0].size() && vis[x][y] == false && image[x][y] == image[sr][sc]){
                dfs(image, x, y, newColor);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        memset(vis, false, sizeof vis);
        dfs(image, sr, sc, newColor);
        for(int i = 0; i < image.size(); i++){
            for(int j = 0; j < image[i].size(); j++){
                if(Ans[i][j] == newColor){
                    image[i][j] = newColor;
                }
            }
        }
        
        return image;
    }
};