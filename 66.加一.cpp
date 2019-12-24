/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> tmp_array = digits;
        char is_carry = 1;
        int tmp = 0;
        for (int i = digits.size()-1; i >=0; i--)
        {
            tmp =  is_carry + digits[i];
            is_carry = tmp>=10 ? 1 : 0;
            tmp_array[i] = is_carry == 1? tmp%10 : tmp;
        }
        if(is_carry)
        {
            tmp_array.resize(digits.size()+1);
            for (int i = digits.size()-1; i >0; i--)
            {
                tmp_array[i+1] = tmp_array[i];
            }
            tmp_array[0] = 1;
        }
        return tmp_array;
    }
};
// @lc code=end

