class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int, int>> q;
        int n = image.size(), m = image[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        q.push({sr, sc});
        vis[sr][sc] = true;

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            int currColor = image[i][j];
            image[i][j] = color;
            // Down
            if(i+1 < n && image[i+1][j] == currColor && !vis[i+1][j]){
                q.push({i+1, j});
                vis[i+1][j] = true;
            }
            // Up
            if(i-1 >= 0 && image[i-1][j] == currColor && !vis[i-1][j]){
                q.push({i-1, j});
                vis[i-1][j] = true;
            }
            // Right
            if(j+1 < m && image[i][j+1] == currColor && !vis[i][j+1]){
                q.push({i, j+1});
                vis[i][j+1] = true;
            }
            // Left
            if(j-1 >= 0 && image[i][j-1] == currColor && !vis[i][j-1]){
                q.push({i, j-1});
                vis[i][j-1] = true;
            }
        }
        return image;
    }
};