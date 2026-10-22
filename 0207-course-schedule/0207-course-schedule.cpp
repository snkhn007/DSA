class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> ind(numCourses);
        for(auto i: prerequisites){
            adj[i[0]].push_back(i[1]);
            // adj[i[1]].push_back(i[0]);
            ind[i[1]]++;
        }

        // for(int i=0; i<numCourses; i++){
        //     for(auto x: adj[i]){
        //         ind[x]++;
        //     }
        // }

        queue<int>q;
        for(int i = 0; i<numCourses; i++){
            if(ind[i] == 0) q.push(i);
        }
        int cnt = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            cnt++;
            for(auto i : adj[curr]){
                ind[i]--;
                if(ind[i] == 0) q.push(i);
            }
        }

        return cnt == numCourses;
    }
};