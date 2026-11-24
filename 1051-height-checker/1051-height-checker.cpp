class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        int maxel = INT_MIN;
        for(auto i : heights){
            maxel = max(maxel, i);
        }
        vector<int> res(n, -5);
        vector<int> freq(maxel+1, 0);

        for(auto i: heights){
            freq[i]++;
        }
        for(int i =1; i<=maxel; i++){
            freq[i] = freq[i]+freq[i-1];
        }
        for(int i=maxel; i>0; i--){
            freq[i] = freq[i-1];
        }
        freq[0] = 0;

        for(int i=0; i<=maxel; i++){
            res[freq[i]] = i;
        }
        for(int i =0; i<n; i++){
            if(res[i] == -5) res[i] = res[i-1];
        }
        // for(int i=0; i<n; i++){
        //     cout<<res[i]<<" ";
        // }
        int cnt = 0;
        for(int i =0; i<n; i++){
            if(res[i] != heights[i]) cnt++;
        }
        return cnt;
    }
};