class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int cnt = 0;
        vector<int> res;
        for(int i=0; i<nums.size()-1; i++){
            if(res.empty()) res.push_back(nums[i]);
            else if(res.back() != nums[i]) res.push_back(nums[i]);
        }
        res.push_back(nums[nums.size()-1]);
        // for(int i=0; i<res.size(); i++){
        //     cout<<res[i]<<" ";
        // }

        for(int i=1; i<res.size()-1 ; i++){
            // cout<<res[i]<<" ";
            if(res[i-1]<res[i] && res[i] > res[i+1]) cnt++;
            else if(res[i+1]>res[i] && res[i]< res[i-1]) cnt++;
        }

        return cnt;
    }
};