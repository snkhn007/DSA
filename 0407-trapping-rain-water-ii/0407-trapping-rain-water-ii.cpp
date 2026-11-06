class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {

        int m = heightMap.size();
        int n = heightMap[0].size();

        if(m < 3 || n < 3) return 0;

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        // Add all boundary cells
        for(int i = 0; i < m; i++) {

            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][n-1], i, n-1});

            vis[i][0] = true;
            vis[i][n-1] = true;
        }

        for(int j = 1; j < n-1; j++) {

            pq.push({heightMap[0][j], 0, j});
            pq.push({heightMap[m-1][j], m-1, j});

            vis[0][j] = true;
            vis[m-1][j] = true;
        }

        int ans = 0;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while(!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int h = curr[0];
            int x = curr[1];
            int y = curr[2];

            for(int k = 0; k < 4; k++) {

                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;

                if(vis[nx][ny])
                    continue;

                vis[nx][ny] = true;

                // Water trapped
                if(heightMap[nx][ny] < h) {
                    ans += h - heightMap[nx][ny];
                }

                // Push effective height
                pq.push({
                    max(h, heightMap[nx][ny]),
                    nx,
                    ny
                });
            }
        }

        return ans;
    }
};