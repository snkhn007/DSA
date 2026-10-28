class Solution {
public:
    // bool isValid(int i, int j, int n, int m, vector<vector<bool>> &vis){
    //     if(i<0 || j<0 || i>=n ||j>= m) return false;
    //     if(vis[i][j]) return false;
    //     return true;
    // }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
        vector<vector<int>> res(n , vector<int> (m, -1));
        // vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue <pair<pair<int, int>, int>> q;

        // populating q, vis, res
        for(int i=0; i<n; i++){
            for(int j =0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({{i, j}, 0});
                    res[i][j] = 0;
                    // vis[i][j] = true;
                }
            }
        }

        while(!q.empty()){
            int i = q.front().first.first, j = q.front().first.second, dist = q.front().second;
            q.pop();
            for(int k=0; k<4; k++){
                int indx = i+dx[k];
                int indy = j+dy[k];

                // if(isValid(indx, indy, n, m, vis) && mat[indx][indy  ] == 1){
                if(indx >= 0 && indy >= 0 && indx < n && indy < m && res[indx][indy] == -1){
                    q.push({{indx, indy}, dist+1});
                    res[indx][indy] = dist+1;
                    // vis[indx][indy] = true;
                }
                
            }
        }
        return res;
    }
};