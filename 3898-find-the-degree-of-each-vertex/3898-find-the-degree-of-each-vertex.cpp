class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        //  i = 0 pr saare 0s will be degree of i = 0;
        // vector<int> res;
        int n = matrix.size();
        vector<int> res(n);
        for(int i=0; i<n; i++){
            // int cnt = 0;
            for(int j = 0; j<n; j++){
                // if(matrix[i][j] == 1) cnt++;
                res[i] += matrix[i][j];
            }
            // res.push_back(cnt);
        }
        return res;
    }
};