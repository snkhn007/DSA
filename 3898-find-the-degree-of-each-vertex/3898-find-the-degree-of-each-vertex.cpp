class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        //  i = 0 pr saare 0s will be degree of i = 0;
        // vector<int> res;
        vector<int> res(matrix.size());
        for(int i=0; i<matrix.size(); i++){
            // int cnt = 0;
            for(int j = 0; j<matrix[0].size(); j++){
                // if(matrix[i][j] == 1) cnt++;
                res[i] += matrix[i][j];
            }
            // res.push_back(cnt);
        }
        return res;
    }
};