class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> ind(numCourses, 0);
        vector<int> res;

        for(auto i: prerequisites){
            // adj[i[0]].push_back(i[1]); //bi first if you want to take course ai ie bi is dependent of ai
            adj[i[1]].push_back(i[0]);
            ind[i[0]]++;
        }

        // USING KAHN'S ALGO
        queue<int>q;
        for(int i=0; i<ind.size(); i++){
            if(ind[i] == 0) q.push(i);
        }

        // if(q.empty()) return false; //cycle exists
        // int nodesProcessed = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            // nodesProcessed++;
            res.push_back(node);
            for(auto i: adj[node]){
                ind[i]--;
                if(ind[i] == 0) q.push(i);
            }
        }
        // return (nodesProcessed == numCourses);
        return res.size() == numCourses;
    }
};