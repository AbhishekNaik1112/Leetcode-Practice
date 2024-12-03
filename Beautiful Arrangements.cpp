//  Question Link - https://leetcode.com/problems/beautiful-arrangement/description/

// Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:

// perm[i] is divisible by i.
// i is divisible by perm[i].
// Given an integer n, return the number of the beautiful arrangements that you can construct.

 

// Example 1:

// Input: n = 2
// Output: 2
// Explanation: 
// The first beautiful arrangement is [1,2]:    
//     - perm[1] = 1 is divisible by i = 1
//     - perm[2] = 2 is divisible by i = 2
// The second beautiful arrangement is [2,1]:
//     - perm[1] = 2 is divisible by i = 1
//     - i = 2 is divisible by perm[2] = 1
// Example 2:

// Input: n = 1
// Output: 1
 

// Constraints:

// 1 <= n <= 15

#include<bits/stdc++.h>
using namespace std;

bool checker(vector<int>& arr){
    for(int i=1;i<=arr.size();i++){
        if(!(arr[i-1]%i== 0 || i%arr[i-1]==0))
        return false;
    }
    return true;
}

void helper(vector<int>& arr,vector<vector<int>> &res,int index){
    if(index==arr.size()){
        if(checker(arr)){
            res.push_back(arr);
        }
    return;
    }
    for(int i=index;i<arr.size();i++){
        swap(arr[index],arr[i]);
        helper(arr,res,index+1);
        swap(arr[index],arr[i]);
    }
}
int findAll(int n){
    vector<int> arr;
    for(int i=1;i<=n;i++){
        arr.push_back(i);
    }
    vector<vector<int>> res;
    helper(arr,res,0);
    return res.size();
}
int main(){
int n;
cin>>n;
int val = findAll(n);
cout<<val;
return 0;
}