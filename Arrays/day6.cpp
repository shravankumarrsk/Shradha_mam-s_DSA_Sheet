/*Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.



longest substring without repeating characters

*/


// brute force approach


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi=0;
        for(int i=0;i<s.length();i++){
            vector<int>hash(256,0);
            int count=0;
            for(int j=i;j<s.length();j++){
                if(hash[s[j]]==1) break;
            
            hash[s[j]]=1;
            count++;
            maxi=max(maxi,count);
        }
        }
        return maxi;
    }
};


/*Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2



subarray sum equals k

*/

#include <bits/stdc++.h>
using namespace std;
class solution{
    public:
    int subarraysum(vector<int>&nums,int k){
        int count=0;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                if(sum==k) count++;
            }
        }
        return count;
    }
};


/*You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.




*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==target) return true;
            }
        }
        return false;
    }
};