
/*

给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).


 */



class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int rev;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int min = INT_MAX;
        
        for(int i = 0; i < len; i++)
        {
            if(i > 0 && nums[i-1] == nums[i]) continue;  //跳过重复的元素
            
            int j = i+1;
            int k = len-1;
            while(j < k)
            {
                
                int sum = nums[i]+nums[j]+nums[k];
                if(abs(sum-target) < min)
                {
                    min = abs(sum-target);
                    rev = sum;
                }
                
                if(sum > target)
                    k--;
                else if(sum < target)
                    j++;
                else                    //相等则直接返回
                    return target;
            }
        }
        
        return rev;
    }
};