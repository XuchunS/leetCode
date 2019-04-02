class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int sLen = s.length();
        string ans = "";
        int val = 0;
        int j = 0;
        int len = 0;
            
        while(j < sLen)
        {
            if(ans.find(s[j]) == string::npos)
            {
                ans = ans + s[j];
                j++;
                len = ans.length();
                if(len > val)
                    val = len;
            }
            else
            {
                ans = ans.substr(1);
            }
        }
        return val;
    }
};