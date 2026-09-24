class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        queue <pair<int, int>> q;

        q.push({sr, sc});
        vis[sr][sc] = true;
        int currPixel = image[sr][sc];

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int i = curr.first;
            int j = curr.second;

            image[i][j] = color;
            if(i+1<n && !vis[i+1][j] &&image[i+1][j]==currPixel){
                image[i+1][j] = color;
                vis[i+1][j] = true;
                q.push({i+1, j});
            }

            if(i-1>=0 && !vis[i-1][j] &&image[i-1][j]==currPixel){
                image[i-1][j] = color;
                vis[i-1][j] = true;
                q.push({i-1, j});
            }

            if(j+1<m && !vis[i][j+1] &&image[i][j+1]==currPixel){
                image[i][j+1] = color;
                vis[i][j+1] = true;
                q.push({i, j+1});
            }

            if(j-1>=0 && !vis[i][j-1] &&image[i][j-1]==currPixel){
                image[i][j-1] = color;
                vis[i][j-1] = true;
                q.push({i, j-1});
            }
        }
        return image;
    }
};