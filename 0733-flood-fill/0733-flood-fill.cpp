class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>> & vis, vector<vector<int>>& image, int color){
        vis[i][j] = true;
        int currColor = image[i][j];

        image[i][j] = color;

        int n = image.size();
        int m = image[0].size();

        if(i+1 < n  &&  !vis[i+1][j]  &&  image[i+1][j] == currColor) dfs(i+1, j, vis, image, color);
        if(i-1 >=  0  &&  !vis[i-1][j]  &&  image[i-1][j] == currColor) dfs(i-1, j, vis, image, color);
        if(j+1 < m  &&  !vis[i][j+1]  &&  image[i][j+1] == currColor) dfs(i, j+1, vis, image, color);
        if(j-1 >=  0  &&  !vis[i][j-1]  &&  image[i][j-1] == currColor) dfs(i, j-1, vis, image, color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        int n = image.size();
        int m = image[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        dfs(sr , sc, vis, image, color);
        return image;
    }
};