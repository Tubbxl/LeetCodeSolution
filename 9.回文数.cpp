/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        char char_buf[16] = {0};
        if(x<0) return false;
        sprintf(char_buf,"%d",x);
        char i = 0;
        char j = strlen(char_buf)-1;
        do
        {
            if(char_buf[i]!=char_buf[j]) return false;
            j--;
            i++;
        }while(i<j);
        return true;

    }
};
// @lc code=end

