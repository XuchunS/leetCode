/*

给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

示例 1:

输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"
示例 2:

输入: ")()())"
输出: 4
解释: 最长有效括号子串为 "()()"



 */
 //栈
class Solution {
public:
    int longestValidParentheses(string s) {
        
        stack<int> str;
        str.push(-1);
        int count = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')     str.push(i);
            else
            {
                str.pop();
                if(str.empty())
                {
                    str.push(i);
                }
                else
                {
                    count = max(count, i-str.top());
                }
            }
        }
        return count;
    }
};
//左右扫描
class Solution {
public:
    int longestValidParentheses(string s) {
        
        int left = 0, right = 0;
        int count = 0;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
                left++;
            else
                right++;
            
            if(left == right)
                count = max(count, 2*right);
            else if(right > left)
            {
                left = 0;
                right = 0;
            }
        }
        left = right = 0;
        for(int i = s.length()-1; i >= 0; i--)
        {
            if(s[i] == '(')
                left++;
            else
                right++;
            
            if(left == right)
                count = max(count, 2*left);
            else if(right < left)
            {
                left = 0;
                right = 0;
            }
        }
        
        return count;
    }
};