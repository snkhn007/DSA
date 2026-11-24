class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxel = *max_element(costs.begin(), costs.end());
        vector<int> freq(maxel +1, 0);
        int n = costs.size();

        for(auto x : costs) freq[x]++;
        for(int i=1; i<= maxel; i++) freq[i] += freq[i-1];

        vector<int> sorted(n);
        for(int i=n-1; i>=0; i--){
            sorted[freq[costs[i]]-1 ] = costs[i];
            freq[costs[i]]--;
        }

        int res = 0;
        for(auto x: sorted){
            if(coins <= 0 || coins-x < 0) break;
            coins -= x;
            res++;
        }

        return res;
    }
};