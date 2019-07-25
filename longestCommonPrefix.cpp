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