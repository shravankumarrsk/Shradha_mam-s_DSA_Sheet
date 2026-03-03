/* You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i=m-1;
    int j=n-1;
    int ind=(m+n-1);
    while(i>=0 && j>=0){
        if(nums1[i]>=nums2[j]){
            nums1[ind]=nums1[i];
            ind--;
            i--;
        }else{
            nums1[ind]=nums2[j];
            ind--;
            j--;
        }
    }
    while(j>=0){  // if there is only one array then copy that directly to the main array
        nums1[ind]=nums2[j];
        ind--;
        j--;
    }
    }
};


/* You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. Each integer appears exactly once except a which appears twice and b which is missing. The task is to find the repeating and missing numbers a and b.

Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.

 

Example 1:

Input: grid = [[1,3],[2,2]]
Output: [2,4]
Explanation: Number 2 is repeated and number 4 is missing so the answer is [2,4].



find missing and repeating values

*/

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
       int n=grid.size();
       vector<int>ans;
       int cursum=0;
       long long sq=(long long)n*n;
      unordered_set<int>st;
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
                if(st.find(grid[i][j])!=st.end()){
                    ans.push_back(grid[i][j]);
                }else{
                    st.insert(grid[i][j]);
                    cursum+=grid[i][j];
                }
        }
       }
       long long totalsum=sq*(sq+1)/2;
       ans.push_back(totalsum-cursum);
       return ans;
    }
};


/* You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.   

Container with most water

*/


class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int maxwater=0;
        int lp=0;
        int rp=n-1;
        while(lp<rp)
        {
                int w=rp-lp;
                int ht=min(height[lp],height[rp]);
                int currwater=ht*w;
                maxwater=max(currwater,maxwater);
                if(height[lp]<height[rp]){
                    lp++;
                }else{
                    rp--;
                }
        }
        
        return maxwater;
    }
};