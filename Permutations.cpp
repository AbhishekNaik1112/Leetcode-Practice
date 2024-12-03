// Question Link - https://leetcode.com/problems/permutations/description/

// Given an array nums of distinct integers, return all the possible 
// permutations
// . You can return the answer in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
// Example 3:

// Input: nums = [1]
// Output: [[1]]
 

// Constraints:

// 1 <= nums.length <= 6
// -10 <= nums[i] <= 10
// All the integers of nums are unique.

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> result;

void permutation(vector<int>& nums, int i) {
    if (i == nums.size()) {
        result.push_back(nums);
        return;
    }

    for (int j = i; j < nums.size(); j++) {
        swap(nums[i], nums[j]);
        permutation(nums, i + 1);
        swap(nums[i], nums[j]);
    }
}

vector<vector<int>> findAll(vector<int>& nums) {
    permutation(nums, 0);
    return result;
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
