class Solution {
public:
    bool isValid(int indx,int indy, int n, int m){
        if(indx >= n || indy>= m || indx<0 || indy <0) return false;
        return true;
    }
    int minimumEffortPath(vector<vector<int>>& grid) {
         priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        
        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int i = curr.second.first;
            int j = curr.second.second;
            int d = curr.first;

            for(int k=0; k<4; k++){
                int indx = i+dx[k], indy = j+dy[k];
                if(isValid(indx, indy, n, m)){
                    int newDiff = max(d, abs(grid[indx][indy] - grid[i][j]));
                    // int newDiff = abs(grid[indx][indy] - grid[i][j]);
                    if(newDiff < dist[indx][indy]){
                        pq.push({newDiff, {indx, indy}});
                        dist[indx][indy] = newDiff;
                    }

                }
            }

        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout<<dist[i][j]<<" ";
            }
            cout<<endl;
        }
        return dist[n-1][m-1];
    }
};