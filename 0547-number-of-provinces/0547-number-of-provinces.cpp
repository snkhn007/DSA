class Solution {
public:
    void bfs(int node, vector<bool>& vis, vector<vector<int>> & mat, queue<int> & q){
        vis[node] = true;
        q.push(node);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int i=0; i<mat[curr].size(); i++){
                if(mat[curr][i] && !vis[i]){
                    q.push(i);
                    vis[i] = true;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, false);

        queue<int> q;

        int cnt = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                bfs(i, vis, isConnected, q);
                cnt++;
            }
        }

        return cnt;
    }
};