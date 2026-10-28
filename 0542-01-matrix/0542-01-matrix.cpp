class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return {};
        int n = mat.size(), m = mat[0].size();
        int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
        vector<vector<int>> res(n , vector<int> (m, -1));
        queue <pair<int, int>> q;

        // populating q, vis, res
        for(int i=0; i<n; i++){
            for(int j =0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    res[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();
            for(int k=0; k<4; k++){
                int indx = i+dx[k];
                int indy = j+dy[k];

                if(indx >= 0 && indy >= 0 && indx < n && indy < m && res[indx][indy] == -1){
                    q.push({indx, indy});
                    res[indx][indy] = res[i][j]+1;
                }
                
            }
        }
        return res;
    }
};