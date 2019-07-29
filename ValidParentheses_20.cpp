class Solution {
public:
    bool isValid(string s) {
        stack<char> str;
        
        for(int i=0; i < s.length(); i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                str.push(s[i]);
            else
            {
                if(!str.empty())
                {
                    char t = str.top();
                    str.pop();
                    if(!((t=='(' && s[i]==')') || (t=='[' && s[i]==']') || (t=='{' && s[i]=='}')))
                        return false;
                }
                else
                    return false;
            }
        }
        if(str.empty()) return true;
        else return false;
    }
};