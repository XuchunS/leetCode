/*
将一个字符串转换为数字，需要考虑的地方已经写到代码的注释中

@author：thebreak

 */

class Solution {
public:
    int myAtoi(string str) {
        
        int ret = 0;
        int index = 0;
        bool flag = true;
        int len = str.length();
        string s = "";
        
        //先剔除开始的空串
        while(str[index] == ' ' && index < len) index++;
        
        //判断str是不是一个空串
        if(index == len)
            return 0;
        
        //判断正负号
        if(str[index] == '+')
            index++;
        else if(str[index] == '-')
        {
            flag = false;
            index++;
        }
        //不是数字开头的话直接返回0
        else if((str[index] >= 'A' && str[index] <= 'Z') || (str[index] >= 'a' && str[index] <= 'z'))
            return 0;
        //检测正负号后面的是不是数字，不是数字的话直接返回0
        if(str[index] < '0' || str[index] > '9')
            return 0;
        
        for(int i=index; i < len; i++)
        {
            //判断是不是数字，不是的话跳出循环
            if(str[i] < '0' || str[i] > '9')
                break;
            //将单个字符转换为数字
            int pop = str[i] - '0';
            
            //判断是否溢出32位int，这里由于已经提取了正负号，所以即使超出也要判断该返回INT_MAX或者INT_MIN
            if (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && pop > 7)) 
                return flag? INT_MAX : -INT_MAX-1;
            
            ret = ret*10 + pop;
        }
        
        return flag ? ret : (-ret);
    }
};