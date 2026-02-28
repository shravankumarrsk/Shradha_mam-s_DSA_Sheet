/*Given an integer array nums, find the subarray with the largest sum, and return its sum.
Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

*/
/// maximum sum array (kadens algorithm)
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            
            if(sum>maxi){
                maxi=sum;
            }
            if(sum<0){
                sum=0;
            }
        }
        return maxi;
    }
};



/* Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]   */


//brute for(auto var : collection_to_loop)

class Solution {
public:
    void sortColors(vector<int>& nums) {
       int n=nums.size();
       int i=1;
       while(i<n){
        if(nums[i]<nums[i-1]){
            swap(nums[i],nums[i-1]);
            i=1;
        }else{
            i++;
        }
       }
       
    }
};

//optimal approach (dutch national flag algorithm)

class Solution {
public:
    void sortColors(vector<int>& nums) {
       int n=nums.size();
       int low=0;int mid=0;int high=n-1;
       while(mid<=high){
        if(nums[mid]==0){
            swap(nums[low],nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid]==1){
            mid++;
        }
        else{
            swap(nums[mid],nums[high]);
            high--;
        }
       }
       return ;
    }
};



/* 

The next permutation  question is not yet solved by me. when it is solved the sheet will be updated.

*/