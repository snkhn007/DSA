class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int dist = INT_MAX, res = -1;
        for(int i=0; i<nums.size(); i++){
            if(dist > abs(nums[i]-0)  || (dist == abs(nums[i]- 0) && nums[i] > res)){
                dist = abs(nums[i]-0);
                res = nums[i];
            }
        }
        return res;
    }
};