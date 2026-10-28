class Solution {
public:
    bool isValid(vector<vector<bool>>& vis, int i, int j, int n, int m ){
        if( i<0 ||j<0 || i>=n || j>=m) return false;
        if(vis[i][j] == true) return false;
        return true;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        queue<pair<int, int>>q;
        q.push({sr, sc});
        vis[sr][sc] = true;

        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();
            int curr = image[i][j];
            image[i][j] = color;

            for(int k=0; k<4; k++){
                int indx = i+dx[k];
                int indy = j+dy[k];
                if(isValid(vis, indx, indy, n, m) && curr == image[indx][indy]){
                    vis[indx][indy]  = true;
                    q.push({indx, indy});
                }
            }
        }    
        return image;    
    }
};