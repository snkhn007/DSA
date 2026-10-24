class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();

        vector<int> temp = arr;
        sort(temp.begin(), temp.end());

        // set<int> st(temp.begin(), temp.end());
        // temp.assign(st.begin(), st.end());
        temp.erase(unique(temp.begin(), temp.end()), temp.end());

        map<int, int> mp;
        for(int i=0; i<temp.size(); i++)  mp[temp[i]] = i + 1;

        vector<int> res;
        for(auto i: arr){
            res.push_back(mp[i]);
        }
        return res;
        
    }
};