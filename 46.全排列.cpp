// @before-stub-for-debug-begin
#include <vector>
#include <string>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (74.53%)
 * Likes:    628
 * Dislikes: 0
 * Total Accepted:    106.5K
 * Total Submissions: 142.4K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */

// @lc code=start

class Solution {
public:
    vector<vector<int> > ans;
    vector<int> used;
    void backtrace(int depth, vector<int> rec, vector<int> nums) {
        if (depth >= nums.size()) {
            ans.push_back(rec);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == 1) continue;
            // if (i > 0 && nums[i] == nums[i-1] && used[i-1] == 0) continue;
            used[i] = 1;
            rec.push_back(nums[i]);
            backtrace(depth+1, rec, nums);
            rec.pop_back();
            used[i] = 0;
        }
    }
    vector<vector<int> > permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) used.push_back(0);
        backtrace(0, vector<int>(), nums);
        return ans;
    }
};
// @lc code=end

