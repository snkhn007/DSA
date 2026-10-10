class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> adj(n+1);
        vector<int> by(n+1, 0);
        for(auto i: trust){
            adj[i[0]].push_back(i[1]);
            by[i[1]]++;
            // by[i[1]].push_back(i[0]);
        }
        // i -> null is the judge
        for(int i=1; i<=n; i++){
            int cnt = 0;
            for(auto j: adj[i]){
                cnt++;
            }
            if(!cnt && by[i]==n-1) return i;
        }

        return -1;
    }
};