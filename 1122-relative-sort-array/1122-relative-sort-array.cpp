class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int maxel = *max_element(arr1.begin(), arr1.end());
        vector<int> freq(maxel+1, 0);
        vector<int> res;
        for(auto i : arr1) freq[i]++;
        for(auto x : arr2){
            while(freq[x] > 0){
                res.push_back(x);
                freq[x]--;
            }
        }
        for(int i =0; i<=maxel; i++){
            while(freq[i] != 0){
                res.push_back(i);
                freq[i]--;
            }
        }
        return res;
    }
};