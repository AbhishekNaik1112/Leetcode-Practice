// Question Link - https://leetcode.com/problems/subsets-ii/description/

// Given an integer array nums that may contain duplicates, return all possible 
// subsets
//  (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]
 

// Constraints:

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10

#include<bits/stdc++.h>
using namespace std;

void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& temp, int index) {
    res.push_back(temp);

    for (int i = index; i < nums.size(); i++) {
        if (i != index && nums[i] == nums[i - 1])
            continue;
        temp.push_back(nums[i]);
        helper(nums, res, temp, i + 1);
        temp.pop_back();
    }
}

vector<vector<int>> findAll(vector<int>& nums) {
    sort(begin(nums), end(nums));
    vector<vector<int>> res;
    vector<int> temp;
    helper(nums, res, temp, 0);
    return res;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> sols = findAll(nums);

    for (const auto& sol : sols) {
        for (int i : sol) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
