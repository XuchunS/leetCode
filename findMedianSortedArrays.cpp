class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<int> num3;
        //num3.resize(len1+len2);
        int temp;
        int i,j;
        
        for(i=0,j=0; i<len1 && j<len2; )
        {
            temp = (nums1[i] < nums2[j]) ? nums1[i] : nums2[j];
            if(temp == nums1[i])
                i++;
            else
                j++;
            num3.push_back(temp);
        }
        
        if(i == len1)
        {
            while(j < len2)
            {
                num3.push_back(nums2[j]);
                j++;
            }
        }
        else
        {
            while(i < len1)
            {
                num3.push_back(nums1[i]);
                i++;
            }
        }
        
        int len3 = num3.size();
        if((len3 % 2) == 0)
            return (num3[(len3-1)/2] + num3[(len3+1)/2]) / 2.0;
        else
            return num3[len3/2];
        
    }
    

    double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
        
        
        int len1 = nums1.size();
        int len2 = nums2.size();
        int i=0,j=0;
        int temp1=0,temp2=0;
        int flag;
        int len = len1 + len2;
        
        if(len1 == 0)
            if(len2%2 == 0)
            {
                return (nums2[(len2-2)/2]+nums2[(len2/2)])/2.0;
            }
            else
            {
                return nums2[(len2-1)/2];
            }
            else if(len2 == 0)
                if(len1%2 == 0)
                {
                    return (nums1[(len1-2)/2]+nums1[(len1/2)])/2.0;
                }
                else
                {
                    return nums1[(len1-1)/2];
                }
        
        if(len%2 == 0)
        {
            flag = (len-2)/2;
            while((i+j) <= flag)
            {
                if(i<len1 && j<len2)
                {
                    temp1 = (nums1[i] < nums2[j]) ? nums1[i] : nums2[j];
                    if(temp1 == nums1[i])
                        i++;
                    else
                        j++;
                }
                else if(i >= len1)
                {
                    temp1 = nums2[j];
                    j++;
                }
                else
                {
                    temp1 = nums1[i];
                    i++;
                }
            }
            
            if(i == len1)
                temp2 = nums2[j];
            else if(j == len2)
                temp2 = nums1[i];
            else
                temp2 = (nums1[i] < nums2[j]) ? nums1[i] : nums2[j];
            return (temp1 + temp2)/2.0;
        }
        else
        {
            flag = (len-1)/2;
            while((i+j) <= flag)
            {
                if(i<len1 && j<len2)
                {
                    temp1 = (nums1[i] < nums2[j]) ? nums1[i] : nums2[j];
                    if(temp1 == nums1[i])
                        i++;
                    else
                        j++;
                }
                else if(i >= len1)
                {temp1 = nums2[j];
                    j++;}
                else
                {temp1 = nums1[i];
                    i++;}
                
            }
            return temp1;
        }
    }
};
