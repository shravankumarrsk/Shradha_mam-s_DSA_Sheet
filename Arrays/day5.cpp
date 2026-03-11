/*Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and using only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2  


find the duplicate number


*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int duplicate=nums[0];
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                duplicate=nums[i];
            }
        }
        return duplicate;
    }
};


/* Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

set matrix zeroes

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       int m = matrix.size();        
       int n = matrix[0].size();     
       vector<int>row(m,0);
       vector<int>col(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(row[i]||col[j]){
                    matrix[i][j]=0;
                }
            }
        }
    }
};


/*Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

merge intervals 

*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      sort(intervals.begin(),intervals.end());
      vector<vector<int>>ans;
      for(int i=0;i<intervals.size();i++){
        if(ans.empty()||ans.back()[1]<intervals[i][0]){   ///non overlaping intervals
            ans.push_back(intervals[i]);
        }else{
            ans.back()[1]=max(ans.back()[1],intervals[i][1]); ///overlapping intervals
        }
      }  
      return ans;
    }
};