class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> ind(numCourses);
        vector<bool> vis(numCourses, false);
        vector<int> res;
        for(auto i: prerequisites){
            adj[i[1]].push_back(i[0]);
            ind[i[0]]++;
        }
        queue <int> q;
        for(int i=0; i<numCourses; i++){
            if(ind[i] == 0) {
                q.push(i);
                vis[i] = true;
                res.push_back(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            // res.push_back(node);
            for(auto i : adj[node]){
                ind[i]--;
                if(ind[i] == 0){
                    res.push_back(i);
                    q.push(i);
                    vis[i] = true;
                }
            }
        }
        if(res.size() != numCourses) return {}; //do not return res directly kyuki res me toposort h 
        return res;
    }
};