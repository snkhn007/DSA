
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans=INT_MAX;
        for(int i = 0; i<nums.size(); i++) {
            int sum = 0, cnt = 0;
            for(int j = i; j< nums.size(); j++) {
                cnt++;
                if(cnt > r) break;
                sum += nums[j];
                if(cnt >= l && sum > 0) ans = min(ans, sum);
        }
        }

        if(ans == INT_MAX) return -1;
        return ans; 
    }
};
