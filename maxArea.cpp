/*

给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。



输入: [1,8,6,2,5,4,8,3,7]
输出: 49

 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        //暴力不可取
        //int max = 0;
        //int len = height.size();
        //int temp = 0;
        
        //for(int i=0; i < len; i++)
        //{
        //    for(int j=i+1; j < len; j++)
        //    {
        //        
        //        temp = (height[i] > height[j]) ? height[j]*(j-i) : height[i]*(j-i);
        //        if(temp > max)
        //            max = temp;
        //    }
        //}
        //return max;
        int max = 0;
        int temp = 0;
        int lptr = 0;
        int rptr = height.size() - 1;
        
        while(lptr < rptr)
        {
            temp = (height[lptr] > height[rptr]) ? height[rptr]*(rptr-lptr) : height[lptr]*(rptr-lptr);
            if(temp > max)
                max = temp;
            
            if(height[lptr] < height[rptr])
                lptr++;
            else
                rptr--;
        }
        return max;
    }
};