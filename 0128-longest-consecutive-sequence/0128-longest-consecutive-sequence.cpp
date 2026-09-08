class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());

        int longest = 1, cnt = 1;

        for(int i=0; i< nums.size()-1; i++){
            if(nums[i] == nums[i+1]) continue;
            else if(nums[i] == nums[i+1]-1) {
                cnt++;
            }
            else cnt = 1;
            longest = max(cnt, longest);
        }
        return longest;
    }
};