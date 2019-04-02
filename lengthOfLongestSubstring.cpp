class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int sLen = s.length();
        int len = 0;
        string ans = "";
        int val = 0;
        for(int i = 0;i < sLen;i++)
            for(int j = i;j < sLen;j++)
            {
                if(ans.find(s[j]) == string::npos) 
                {
                    ans = ans + s[j];
                    len = ans.length();
                    if(len > val)
                        val = len;
                }
                else
                {
                    ans = "";
                    break;
                }
            }
        return val;
    }
};