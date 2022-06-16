// approach 1 (brute-force)
//take an extra array and push it both num1,num2 and sort it and find the median
// approach 2(optimal)
/*
Let's imagine the situation here.

so if we divide our final array in two halfs i.e. left half and right half
by making sure that **all the elements in left half should be lesser than right half** correct?
but how do we do that?
let's take an example:
num1=[1,3,4,7,10,2]
num2=[2,3,6,5]
let's make possibilities:
if we take 1,3,4,7 for the 1st half of the left half from 1st array and 10,12 from the 2dn array for the 1st half of the right half
and for the 2nd part of the left half we'll take 2 and for 2nd part of right half we'll take from the 2nd array as 3,6,15
i.e.
1st///No
l1=[1,3,4,7]   r1=[10,12]
l2=[2]         r2=[3,6,15]

2nd//No
l1=[1,3]      r1=[4,7,10,12]
l2=[2,3,6]    r2=[15]

3rd//Yes
l1=[1,3,4]         r1=[7,10,12]
l2=[2,3]           r2=[6,15]

we know that left half should be lesser than right half anyhow hence we'll compare the larger ele from the left half to the smallest ele in the right half if that satisfy the condition then rest of the elements will be satisfying too.
let n be the size.
(l1 and r1)and (l2 and r2) are already sorted because they are from the same array.
l1[n-1]<=r2[0] and l2[n-1]<=r1[0] // this is the condition of binary search here.

but what for even sized array//
we have two median for even and we need to take the median of them.
How do we find that 2 ele
//we know that in middle max(left_half) and min(right_half) will be there.// since it's sorted
hence we will take median of that.
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int n=nums1.size(),m=nums2.size();
        if(n>m) return findMedianSortedArrays(nums2,nums1); // since we'll consider n>m always
        int start=0,end=n;
        while(start<=end){
            int cut1=start+(end-start)/2;
            int cut2=(n+m+1)/2-cut1;
            
            int left1=cut1==0?INT_MIN:nums1[cut1-1];
            int left2=cut2==0?INT_MIN:nums2[cut2-1];
            
            int right1=cut1==n?INT_MAX:nums1[cut1];
            int right2=cut2==m?INT_MAX:nums2[cut2];
            
            if(left1<=right2 and left2 <=right1){ //b.s. condition
                if((n+m)%2==0){ //even size
                    return (max(left1,left2)+min(right1,right2))/2.0;
                }
                else return max(left1,left2);
            }
            else if(left1>right2)
                end=cut1-1;
            else start=cut1+1;
        }
        return 0.0;
    }
};
