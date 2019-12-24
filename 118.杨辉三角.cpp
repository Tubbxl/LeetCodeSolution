/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        vector<int> tmp(numRows);
        for (int i = 1; i <= numRows; i++)
        {
            tmp.resize(i);
            if(i<3)
            {
                for (int j = 0; j < i; j++)
                {
                    tmp.push_back(1);
                }           
            }
            else
            {
                tmp.push_back(1);
                for (int j = 1; j < i-2; j++)
                {
                   tmp[j] = result[i-1][j]+result[i-1][j+1];
                }                
            }
            result.push_back(tmp);
        }
        return result;
    }
};
// @lc code=end

