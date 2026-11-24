class Solution {
public:
    bool isValid(int indx, int indy, int n, int m){
        if(indx >= n || indx <0 || indy >= m || indy < 0) return false;
        return true;
    }
    int minimumObstacles(vector<vector<int>>& grid) {
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist (n, vector<int>(m, INT_MAX)); // stores the amount of health lost to reach this particular cell


        int dx[]={1, -1, 0, 0};
        int dy[]={0, 0, 1, -1};

        pq.push({grid[0][0], {0, 0}}); // dist, {i, j}
        dist[0][0] = grid[0][0];

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int i = curr.second.first;
            int j = curr.second.second;
            int d = curr.first;

            if(d > dist[i][j]) continue;

            for(int k = 0; k<4; k++){
                int indx = i + dx[k], indy = j + dy[k];
                if(isValid(indx, indy, n, m) && d + grid[indx][indy] < dist[indx][indy]){
                    int newDist = d + grid[indx][indy];
                    pq.push({newDist, {indx, indy}});
                    dist[indx][indy] = newDist;
                }
            }
        }
        return dist[n-1][m-1];        
    }
};