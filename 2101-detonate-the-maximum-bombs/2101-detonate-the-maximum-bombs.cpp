class Solution {
public:
    bool dist(vector<int>&i, vector<int> &j){
        long long dx = i[0] - j[0];
        long long dy = i[1] - j[1];
        return(
            dx*dx + dy*dy <= 1LL*i[2]*i[2]
            // (i[0]-j[0])*(i[0]-j[0]) + (i[1]-j[1])*(i[1]-j[1]) <= i[2]*i[2] // j is reachable by i
        );
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j) continue;
                if(dist(bombs[i], bombs[j])) adj[i].push_back(j);
            }
        }

        int res =0, node = 0;
        for(int i=0; i<n; i++){
            vector<int> vis(n, false);
            queue<int> q;
            q.push(i);
            vis[i] = true;
            while(!q.empty()){
                node++;
                int curr = q.front();
                q.pop();
                for(auto i : adj[curr]){
                    if(!vis[i]){
                        q.push(i);
                        vis[i] = true;
                    }
                }
            }
            res = max(res, node);
            node = 0;
        }
        return res;
    }
};