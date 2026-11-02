class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> ind(numCourses);
        // vector<bool> vis(numCourses, false);  Kahn's Algorithm already tracks processed nodes through indegree and the result vector
        vector<int> res;
        for(auto i: prerequisites){
            adj[i[1]].push_back(i[0]);
            ind[i[0]]++;
        }
        queue <int> q;
        for(int i=0; i<numCourses; i++){
            if(ind[i] == 0) {
                q.push(i);
                // res.push_back(i); push the nodes in res that are alreafy processed
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node); //nodes which are already processed
            for(auto i : adj[node]){
                ind[i]--;
                if(ind[i] == 0){
                    // res.push_back(i); 
                    q.push(i);
                }
            }
        }
        if(res.size() != numCourses) return {}; //do not return res directly kyuki res me toposort h 
        return res;
    }
};