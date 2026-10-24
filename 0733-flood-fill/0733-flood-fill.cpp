class Solution {
public:
    bool isValid(int i, int j, vector<vector<int>>& image, vector<vector<bool>>& vis, int n, int m){
        if( i< 0 || j<0 || i >= n|| j>= m) return false;
        if(vis[i][j]) return false;
        // if(image[i][j] != color) return false;
        return true;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();
        int dx[]= {0, 0, 1, -1};
        int dy[]={1, -1, 0, 0};

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        q.push({sr, sc});
        vis[sr][sc] = true;

        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();
            int curr = image[i][j];
            image[i][j] = color;

            for(int k=0; k<4; k++){
                int indx = i + dx[k];
                int indy = j + dy[k];

                if(isValid(indx, indy, image, vis, n, m) && image[indx][indy] == curr){
                    vis[indx][indy] = true;
                    q.push({indx, indy});
                }
            }
        }
        return image;
    }
};