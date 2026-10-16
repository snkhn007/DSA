class Solution {
public:
    void bfs(vector<vector<int>>&adj, vector<int>& color, int node){
        queue<int> q;
        q.push(node);
        // color[node] = 1;
        while(!q.empty()){
            int currNode = q.front();
            q.pop();
            vector<int> taken(5, 0);
            for(auto i: adj[currNode]){
                if(color[i] != -1){
                    // color this node accordingly -> WRONG
                    // find all the colors which are already occupied by neigbours
                    // taken.push_back(color[i]);
                    taken[color[i]] = 1;
                    // q.push(i);
                }else{
                    q.push(i);
                }
            }
            // /choose colro for currNode not its neighbours
            for(int i=1; i<5; i++){ 
                if(taken[i] == 0){
                    color[currNode] = i; 
                    break;
                }
            }
        }
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n);
        for(auto i: paths){
            adj[i[0] - 1].push_back(i[1] - 1);
            adj[i[1] - 1].push_back(i[0] - 1);
            // adj[i[0]].push_back(i[1]);
            // adj[i[1]].push_back(i[0]);
        }

        vector<int> color(n, -1);
        for(int i=0; i<n; i++){
            if(color[i] == -1){
                bfs(adj, color, i);
            }
        }

        return color;
    }
};