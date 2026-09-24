class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int color, int val){
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size() || image[i][j] != val) return;
        if(image[i][j] == color) return;
        image[i][j] = color;
        dfs(image, i+1, j, color, val);
        dfs(image, i-1, j, color, val);
        dfs(image, i, j+1, color, val);
        dfs(image, i, j-1, color, val);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int val = image[sr][sc];
        dfs(image, sr, sc, color, val);
        return image;
    }
};