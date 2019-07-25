
/*

编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。


 */


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.empty()) return "";
        string rev = strs[0];
        int len = strs.size();
        //vector<string>::iterator itr = strs.begin();
        //vetcor<string>::iterator end = strs.end();
        for(int i=1; i < len; i++)
        {
            if(strs[i].empty()) return "";
            for(int j=0; j<strs[i].length() && j<rev.length(); j++)
            {
                if(rev[j] == strs[i][j])
                {
                    if(j+1 == strs[i].length())
                    { 
                        rev = rev.substr(0,j+1);
                        break;
                    }
                    else if(j+1 == rev.length())
                    {
                        break;
                    }
                    else
                        continue;
                }
                else
                {
                    
                    rev.erase(j);
                    break;
                }
                
            }
        }
        return rev;
    }
};