class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> left;
        left.push_back(0);
        for(int i=0; i<n-1; i++){
            left.push_back(left.back()+nums[i]);
        }

        vector<int> right(n);
        right[n-1] = 0;
        for(int i=n-1; i>0; i--){
            right[i-1] = right[i]+ nums[i];
        }

        // for(auto i: left) cout<<i<<" ";
        // cout<<endl;
        // for(auto i: right) cout<<i<<" ";
        vector<int> res;
        for(int i =0; i<n; i++) res.push_back(abs(left[i]-right[i]));
        return res;
        // return {};
    }
};