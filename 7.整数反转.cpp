/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        long sum = 0;
        int tmp = x;
        while(tmp!=0)
        {
            sum = sum*10 + tmp%10; 
            if((sum > INT_MAX) || (sum < INT_MIN))
            {
                return 0;
            }
            tmp = tmp/10;
        }
        return (int)sum;

    }
};
// @lc code=end

