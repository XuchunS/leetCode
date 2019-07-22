/*

将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

关键是决定何时从上往下遍历矩阵，何时从下往上遍历矩阵

可以设置哨兵flag

 */

class Solution {
public:
    string convert(string s, int numRows) {
        
        if(s.empty() || numRows==1)
            return s;
        
        int len = s.length();
        string result = "";
        vector<string> matrix(numRows);
        int curRow = 0;
        //flag标志
        bool goDown = false;
        
        for(int i=0; i < len; i++)
        {
            matrix[curRow] += s[i];
            if(curRow == 0  ||  curRow == numRows-1)    
                goDown = !goDown;
            curRow = (goDown) ? (curRow+1) : (curRow-1);
        }
        
        for(string sr : matrix)
            result += sr;
        
        return result;
    }
};