class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn =INT_MAX, mx= INT_MIN;
        for(auto i : nums){
            if(i > mx) mx = i;
            if(i < mn) mn = i;
        }
        for(int i=mn; i>=1; i--){
            if(mn%i == 0 && mx%i == 0) return i;
        }
        return 1;
    }
};