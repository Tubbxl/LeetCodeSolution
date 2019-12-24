/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (32.56%)
 * Total Accepted:    97.9K
 * Total Submissions: 294.3K
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 * 
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 示例：
 * 
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/* 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
 */


//1563/1563 cases passed (36 ms)
//Your runtime beats 36.95 % of cpp submissions
//Your memory usage beats 89.22 % of cpp submissions (10.3 MB)


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *ret = new ListNode(-1);
        ListNode *tmp = ret;
        ListNode *tmp_l1 = l1;
        ListNode *tmp_l2 = l2;
        int len1 = getListLen(l1);
        int len2 = getListLen(l2);
        int carry = 0;
        int len = len1>len2 ? len1 : len2;
        for (int i = 0; i < len; i++)
        {
            if((tmp_l1)&&(tmp_l2))
            {
                int sum = tmp_l1->val+tmp_l2->val+carry;
                carry =  (sum)>9 ? 1 : 0;
                tmp->val = carry ? sum%10 : sum;

            }
            else if(tmp_l1)
            {
                int sum = tmp_l1->val+carry;
                carry = (sum)>9 ? 1 : 0;
                tmp->val = carry ? sum%10 : sum;                
            }
            else if(tmp_l2)
            {
                int sum = tmp_l2->val+carry;
                carry = (sum)>9 ? 1 : 0;
                tmp->val = carry ? sum%10 : sum;
            }
            if((i==(len-1))&&(carry)) 
            {
                tmp->next = new ListNode(-1);
                tmp->next->val = carry;
            }
            if(i!=len-1)
            {
                tmp->next = new ListNode(-1);
                tmp = tmp->next;
                if(tmp_l1)
                    tmp_l1 = tmp_l1->next;
                if(tmp_l2)
                    tmp_l2 = tmp_l2->next;

            }

        }
        return ret;
        
    }
    int getListLen(ListNode* l)
    {
        int i = 0;
        ListNode *tmp=l;
        while (tmp)
        {
            tmp = tmp->next;
            i++;
        }
        return i;
    }

};


/*
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *ret = new ListNode(-1);
        ListNode *tmp = ret;
        ListNode *tmp_l1 = l1;
        ListNode *tmp_l2 = l2;
        int carry = 0;
        while((tmp_l1)&&(tmp_l2))
        {
            if((tmp_l1)&&(tmp_l2))
            {
                int sum = tmp_l1->val+tmp_l2->val+carry;
                carry =  (sum)>9 ? 1 : 0;
                tmp->val = carry ? sum%10 : sum;

            }
            else if(tmp_l1)
            {
                int sum = tmp_l1->val+carry;
                carry = (sum)>9 ? 1 : 0;
                tmp->val = carry ? sum%10 : sum;                
            }
            else if(tmp_l2)
            {
                int sum = tmp_l2->val+carry;
                carry = (sum)>9 ? 1 : 0;
                tmp->val = carry ? sum%10 : sum;
            }
            if(((tmp_l1->next==NULL)&&(tmp_l2->next==NULL))&&(carry)) 
            {
                tmp->next = new ListNode(-1);
                tmp->next->val = carry;
            }
            if(tmp_l1 || tmp_l2)
            {
                if(tmp_l1)
                    tmp_l1 = tmp_l1->next;
                if(tmp_l2)
                    tmp_l2 = tmp_l2->next;
                if(tmp_l1 || tmp_l2)
                {
                    tmp->next = new ListNode(-1);
                    tmp = tmp->next;
                }

            }

        }
        return ret;
        
    }

};
*/

