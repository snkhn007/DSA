class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n+2);
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        int nodes = adj.size();
        for(int i =1; i<nodes; i++){
            int cnt = 0;
            for(auto j: adj[i]){
                cnt++;
            }
            if(cnt == n) return i;
        }

        return -1;
    }
};