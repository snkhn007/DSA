class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int last = INT_MIN;
        int longest = 0;
        int cnt = 0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            if( last == nums[i]) continue;
            if(last != nums[i]-1){
                cnt = 1;
                 last = nums[i];
            }
            else {
                cnt++;
                last = nums[i];
            }
            longest = max(longest, cnt);
        }
        return longest;
        
    }
};