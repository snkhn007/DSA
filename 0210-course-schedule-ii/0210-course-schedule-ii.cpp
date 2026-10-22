class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> ind(numCourses);
        for(auto i: prerequisites){
            adj[i[1]].push_back(i[0]);
            ind[i[0]]++;
        }
        queue<int> q;
        for(int i =0; i<numCourses; i++){
            cout<<ind[i]<<endl;
            if(ind[i] == 0) q.push(i); 
        }
        // if(q.empty()) return {};
        vector<int> res;

        while(!q.empty()){
            int currNode = q.front();
            q.pop();
            res.push_back(currNode);
            for(auto i : adj[currNode]){
                ind[i]--;
                if(ind[i] == 0) q.push(i);
            }
        }

        if (res.size() != numCourses) return {};
        return res;
        
    }
};