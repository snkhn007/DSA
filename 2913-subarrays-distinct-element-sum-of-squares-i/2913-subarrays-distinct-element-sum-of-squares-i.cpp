class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int res = 0;
        for(int i=0; i<nums.size(); i++){
            unordered_map<int, int> mp;
            for(int j=i; j<nums.size();j++){
                mp[nums[j]]++;
                int cnt = mp.size();
                res += cnt * cnt;
            }

        }
        return res;
    }
};