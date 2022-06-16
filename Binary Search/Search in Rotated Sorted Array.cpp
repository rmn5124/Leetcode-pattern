//https://leetcode.com/problems/search-in-rotated-sorted-array/

// we'll find the target in sorted half.
// we just have to find the boundary of sorted half
//we will divide array in two sorted half and apply bs on both the part.
class Solution {
public:
    int search(vector<int>& nums, int target) {
       int n=nums.size();
        int start=0,end=n-1;
        while(start<=end){
            int mid=start+(end-start)/2;
             if(nums[mid]==target) return mid;
            // exist in left part
            if(nums[start]<=nums[mid]){
                if(target>=nums[start] and target<nums[mid])
               end=mid-1;
                else start=mid+1;
            }
          //exist in right half 
            else {
                if(target<=nums[end] and target>nums[mid]) start=mid+1;
                else end=mid-1;
            }
        }
        return -1;
    }
};
