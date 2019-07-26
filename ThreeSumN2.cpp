/*

给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

这个不要重复的元素就很坑！！！！！！！！！

 */


class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        
        int len = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int> > rev;
        
        //nums.erase(unique(nums.begin(),nums.end()),nums.end());
        //int len = nums.size();
        
        for(int i=0; i < len-2; i++)
        {
            if(i > 0 && nums[i-1] == nums[i]) continue;
            for(int l=i+1,r=len-1; l<r; )
            {
                if(nums[r] > -nums[i]-nums[l]){
                    while(l < r && nums[r-1] == nums[r]) r--; 
                    r--;
                }
                else if(nums[r] < -nums[i]-nums[l]){
                    while(l < r && nums[l+1] == nums[l]) l++; 
                    l++;
                }
                else{
                    rev.push_back(vector<int>{nums[i],nums[l],nums[r]});
                    while(l < r && nums[r-1] == nums[r]) r--; 
                    while(l < r && nums[l+1] == nums[l]) l++; 
                    r--;
                    l++;
                }
            }
        }
        //清洗数据，去除相同的，但这样会超时，
        //sort(rev.begin(),rev.end());
        //rev.erase(unique(rev.begin(),rev.end()),rev.end());
        return rev;
    }
    /*
    
    以下为采用二分查找
    
     */
    vector<vector<int> > threeSumN2logN(vector<int>& nums) {
        
        
        sort(nums.begin(),nums.end());
        vector<vector<int> > rev;
        int k;
        
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        int len = nums.size();
        
        
        for(int i=0; i < len; i++)
        {
            //if(nums[i] + nums[i+1] + nums[len-1] == 0)
            //    rev.push_back(vector<int>{nums[i],nums[i+1],nums[len-1]});
            for(int j=i+1; j<len; j++)
            {
                if((k = binarySearch(-nums[i]-nums[j],nums)) > j)
                    rev.push_back(vector<int>{nums[i],nums[j],nums[k]});
            }
        }
        //sort(rev.begin(),rev.end());
        //rev.erase(unique(rev.begin(),rev.end()),rev.end());
        return rev;
    }
    
    int binarySearch(int key, vector<int>& a)
    {
        int lo = 0;
        int hi = a.size()-1;
        while(lo <= hi)
        {
            int mid = lo + (hi-lo)/2;
            if(key < a[mid]) hi = mid-1;
            else if(key > a[mid]) lo = mid-1;
            else    return mid;
        }
        return -1;
    }
};