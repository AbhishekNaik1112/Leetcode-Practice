// Question Link - https://leetcode.com/problems/permutation-sequence/description/

// The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.

 

// Example 1:

// Input: n = 3, k = 3
// Output: "213"
// Example 2:

// Input: n = 4, k = 9
// Output: "2314"
// Example 3:

// Input: n = 3, k = 1
// Output: "123"
 

// Constraints:

// 1 <= n <= 9
// 1 <= k <= n!

// TLE CODE

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> res;

void helper(vector<int>& arr, int index) {
    if (index == arr.size()) {
        res.push_back(arr);
    }
    for (int i = index; i < arr.size(); i++) {
        swap(arr[index], arr[i]);
        helper(arr, index + 1);
        swap(arr[index], arr[i]);
    }
}

string findAll(int n, int k) {
    vector<int> arr;
    for (int i = 1; i <= n; i++) {
        arr.push_back(i);
    }
    helper(arr, 0);
    sort(res.begin(), res.end());
    string result;
    for (int num : res[k - 1])
        result += to_string(num);
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;

    cout << findAll(n, k) << endl;

    return 0;
}


// Optimized Code
#include<bits/stdc++.h>
using namespace std;

string findAll(int n, int k) {
    int fact = 1;
    vector<int> arr;
    for (int i = 1; i < n; i++) {
        fact = fact * i;
        arr.push_back(i);
    }
    arr.push_back(n);
    k = k - 1;
    string res = "";
    while (true) {
        res = res + to_string(arr[k / fact]);
        arr.erase(arr.begin() + k / fact);
        if (arr.size() == 0) {
            break;
        }
        k = k % fact;
        fact = fact / arr.size();
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;

    cout << findAll(n, k) << endl;

    return 0;
}
