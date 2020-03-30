/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
class Solution {
public:
    int sum = 0;
    void backtrace(int amount, int index, vector<int>& coins, int count) {
        if (index >= coins.size()) return;
        int tmp = amount / coins[index];
        for (int i = tmp; i >= 0; i--) {
            amount -= i * coins[index];
            count += i;
            if (amount == 0) {
                sum ++;
                amount += i * coins[index];
                count -= i;
                continue;
            }
            backtrace(amount, index+1, coins, count);
            amount += i * coins[index];
            count -= i;
        }
    }
    int change(int amount, vector<int>& coins) {
        if (amount == 0) return 1;
        sort(coins.rbegin(), coins.rend());
        backtrace(amount, 0, coins, 0);
        return sum;
    }
};
// @lc code=end

