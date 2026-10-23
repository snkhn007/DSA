class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        for(int i =0; i<n; i++){
            for(auto j: graph[i]){
                adj[j].push_back(i);
            }
        }
        vector<int> ind(n);
        for(int i=0; i<n; i++){
            for(auto j : adj[i]) ind[j]++;
        }
        vector<int> res;
        queue<int>q;
        for(int i=0; i<n; i++){
            if(ind[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            res.push_back(curr);
            for(auto i : adj[curr]){
                ind[i]--;
                if( ind[i] == 0) q.push(i);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};