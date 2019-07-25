//using namespace std;

/*

罗马数字到阿拉伯数字转换

 */
class Solution {
public:
    int my_romanToInt(string s) {
        
        //int vals[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        //vector<string> maps = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        unordered_map<string,int> romanInt = {{"M",1000}, {"CM",900}, {"D",500}, {"CD",400}, {"C",100}, {"XC",90}, {"L",50}, {"XL",40}, {"X",10}, {"IX",9}, {"V",5}, {"IV",4}, {"I",1}};
        
        int val = 0;
        int i = 0;
        unordered_map<string,int>::const_iterator iter;
        
        while(i < s.length())
        {
            
            if(i+1 < s.length())
            {
                iter = romanInt.find(s.substr(i,2));
                if(iter != romanInt.end())
                {
                    val = val + iter->second;
                    i += 2;
                    //continue;
                }
            }
            else
            {
                iter = romanInt.find(s[i]+"");
                val = val + iter->second;
                i += 1;
            }
        }
        return val;
    }
    int romanToInt(string s) {
        int result=0;//存放结果
        map<char,int> luomab;//建立罗马表
        //插入对应关系
        luomab.insert(map<char,int>::value_type('I',1));
        luomab.insert(map<char,int>::value_type('V',5));
        luomab.insert(map<char,int>::value_type('X',10));
        luomab.insert(map<char,int>::value_type('L',50));
        luomab.insert(map<char,int>::value_type('C',100));
        luomab.insert(map<char,int>::value_type('D',500));
        luomab.insert(map<char,int>::value_type('M',1000));
        for(int i=0;i<s.length();i++)
        {
            if(luomab[s[i]]>=luomab[s[i+1]])
                result+=luomab[s[i]];
            else
            {
                result+=(luomab[s[i+1]]-luomab[s[i]]);
                i++;
            }
        }
        return result;
    }

};