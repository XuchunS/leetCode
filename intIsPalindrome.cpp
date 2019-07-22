/*
计算int变量x是不是回文数
（1）直接计算x反转后的数字
（2）计算一半数字，然后比较，更高效

 */

class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x < 0 || (x%10==0 && x!=0))
            return false;
        
        int temp = 0;
        //计算x反转后的数字，不高效
        //int pop = temp % 10;
        //int ret = 0;
        //while(temp != 0)
        //{
        //    if (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && pop > 7)) 
        //        return false;
        //    
        //    ret = ret * 10 + pop;
        //    temp = temp / 10;
        //    pop = temp % 10; 
        //}
        //只计算一半数字
        int pop = 0;
        while(x > temp)
        {
            pop = x%10;
            temp = temp*10 + pop;
            if (temp > INT_MAX / 10 || (temp == INT_MAX / 10 && pop > 7)) 
                return false;
            x /= 10;
                
        }
        //这里后面的是因为遇到12321这种关于中间数字对称
        return temp==x || temp/10 == x;
    }
};