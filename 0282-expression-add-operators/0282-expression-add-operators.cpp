class Solution {
public:
    vector<string> ans;

    void solve(string num, int target, int index,
               string path, long long value, long long prev) {

        if(index == num.size()) {
            if(value == target) {
                ans.push_back(path);
            }
            return;
        }

        for(int i = index; i < num.size(); i++) {

            // Avoid leading zeros
            if(i > index && num[index] == '0')
                break;

            string str = num.substr(index, i - index + 1);

            long long curr = stoll(str);

            // First number
            if(index == 0) {
                solve(num, target, i + 1, str, curr, curr);
            }

            else {

                // Addition
                solve(num, target, i + 1,
                      path + "+" + str,
                      value + curr, curr);

                // Subtraction
                solve(num, target, i + 1,
                      path + "-" + str,
                      value - curr, -curr);

                // Multiplication
                solve(num, target, i + 1,
                      path + "*" + str,
                      value - prev + prev * curr,
                      prev * curr);
            }
        }
    }

    vector<string> addOperators(string num, int target) {

        solve(num, target, 0, "", 0, 0);

        return ans;
    }
};