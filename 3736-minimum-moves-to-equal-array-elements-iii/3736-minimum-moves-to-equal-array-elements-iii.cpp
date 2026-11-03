class Solution {
public:
    int minMoves(vector<int>& nums) {
        int res = INT_MIN;
        for(auto  i : nums) if(i>res)  res = i;
        int cnt = 0;
        for(auto i:nums){
            while(i<res) {
                cnt++;
                i++;
            }
        }
        return cnt;
    }
};