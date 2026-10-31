class Solution {
public:
    bool isValid(int i, int j, int n, int m, vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=n || j>=m) return false;
        if(grid[i][j] == 1) return false;
        return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;

        int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
        int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};

        queue <pair<int, int>> q;
        q.push({0, 0});
        int lvl = 1;
        grid[0][0] = 1;

        while(!q.empty()){
            int size = q.size();
            while(size > 0){
                auto [i, j] = q.front();
                if( i == n-1 && j == m-1) return lvl;
                q.pop();

                for(int k=0; k<8; k++){
                    int indx = i+dx[k], indy= j+dy[k];
                    if(isValid(indx, indy, n, m, grid)){
                        q.push({indx, indy});
                        grid[indx][indy] = 1;
                    }
                }
                size--;
            }
            lvl++;
        }

        return -1;

    }
};