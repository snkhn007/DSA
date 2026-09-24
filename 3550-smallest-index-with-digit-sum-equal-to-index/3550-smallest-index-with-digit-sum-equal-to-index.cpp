class Solution {
public:
    int sum(int num){
        if(num == 0) return 0;
        int sum = 0;
        while(num>0){
            sum+= num%10;
            num= num/10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            // cout<<sum(nums[i])<<" ";
            if(sum(nums[i]) == i) return i;
        }
        return -1;
    }
};