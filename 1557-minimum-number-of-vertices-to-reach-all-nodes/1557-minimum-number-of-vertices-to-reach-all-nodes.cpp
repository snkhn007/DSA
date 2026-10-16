class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // unordered_map <int, int> mp;
        vector<int> res, mp(n);
        // for(int i=0; i<n; i++) mp[i] = 0;
        for(auto i : edges){
            // mp[i[1]]++;
            mp[i[1]] = 1;
        }
        // for(auto i : mp){
            // if(i.second == 0) res.push_back(i.first);
        // }
        for(int i=0; i<n; i++) if(mp[i] == 0) res.push_back(i);
        return res;



    }
};