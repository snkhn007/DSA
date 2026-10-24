class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> alt;
        alt.push_back(0);
        for(auto i: gain){
            alt.push_back(alt.back() + i);
        }
        int res = alt[0];
        for(int i =0; i<alt.size(); i++){
            if(alt[i] > res) res = alt[i];
        }
        return res;
    }
};