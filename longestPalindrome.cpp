class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 1)
		{
			return "";
		}
        int len = s.length();
        
        int len1,len2,len3;
        int start=0;
        int end = 0;
        for(int i=0;i < len;i++)
        {
            len1 = expandAroundMid(s,i,i);
            len2 = expandAroundMid(s,i,i+1);
            len3 = max(len1,len2);
            if(len3 > end-start)
            {
                start = i - (len3-1)/2;
                end = i + (len3/2);
            }
        }
        
        return s.substr(start,end-start+1);
    }
    
    
    int expandAroundMid(string s,int left,int right)
    {
        int L = left;
        int R = right;
        int len = s.length();
        while(L >= 0 && right < len && s[L]==s[R])
        {
            //if(s.at(L) == s.at(R))
            
                L--;
                R++;
            
        }
        return R-L-1;
    }
};