class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_map <int, int> mp;
        vector<int> res;
        for(int i=0; i<n; i++) mp[i] = 0;
        for(auto i : edges){
            mp[i[1]]++;
        }
        for(auto i : mp){
            if(i.second == 0) res.push_back(i.first);
        }
        return res;



    }
};