class Solution {
public:
    bool isValid(int indx, int indy, int n, int m){
        if(indx >= n || indy >=m || indx<0 || indy<0) return false;
        return true;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m =grid[0].size();
        deque <pair<int, int>> dq;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        dq.push_front({0, 0});
        dist[0][0] = grid[0][0];

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        while(!dq.empty()){
            auto [i, j] = dq.front();
            dq.pop_front();

            if(vis[i][j]) continue;
            vis[i][j] = true;

            for(int k = 0; k<4; k++){
                int indx = i+dx[k], indy = j+dy[k];

                if(isValid(indx, indy, n, m) && !vis[indx][indy]){
                    int newCost = grid[indx][indy]  +  dist[i][j];
                    if(newCost < health && dist[indx][indy] > newCost){
                        // we can safely travel to this cell
                        dist[indx][indy] = newCost; // we do not push all valid only once that follow this condition beacuse
                        // we need to reduce the affect on health 
                        if(grid[indx][indy] == 0) dq.push_front({indx, indy});
                        else dq.push_back({indx, indy});
                    }
                }
            }
        }
        return dist[n-1][m-1] < health;

    }
};