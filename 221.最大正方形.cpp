/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        vector<vector<int> > dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        int res = 0;
        for (int i = 0; i < dp.size(); i++)
            for (int j = 0; j < dp[0].size(); j++) {
                if (i == 0 || j == 0 || matrix[i][j] == '0') dp[i][j] = matrix[i][j] - '0';
                else if (matrix[i][j] == '1') {
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                }
                if (dp[i][j] > res) res = dp[i][j];
            }
        return res*res;
    }
};
// @lc code=end

