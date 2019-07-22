//#include <algorithm>
/*

关键是如何判断32位整数反转后有没有溢出

 */
class Solution {
public:
    int reverse(int x) {
        
        int ans = 0;
        while (x != 0) {
            int pop = x % 10;
            //这里如果大于，乘10后肯定溢出
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && pop > 7)) 
                return 0;
            if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && pop < -8)) 
                return 0;
            ans = ans * 10 + pop;
            x /= 10;
        }
        return ans;

    }
    
    

    //沙雕方法，代价太高
    /*string strrev(string str,int len)
    {
        //int len = str.length();
        for (int i = 0; i<len/2; i++)
        {
            //前后交换
            char temp = str[i];
            str[i] = str[len-i-1];
            str[len-i-1] = temp;
        }
        return str;
    }*/
};