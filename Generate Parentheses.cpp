// Question Link - https://leetcode.com/problems/generate-parentheses/description/

// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]
 

// Constraints:

// 1 <= n <= 8

#include<bits/stdc++.h>
using namespace std;

vector<string> res;

void helper(int o, int c, int n, string temp) {
    if (temp.size() == n * 2) {
        res.push_back(temp);
        return;
    }
    if (o < n) helper(o + 1, c, n, temp + "(");
    if (c < o) helper(o, c + 1, n, temp + ")");
}

vector<string> findAll(int n) {
    helper(0, 0, n, "");
    return res;
}

int main() {
    int n;
    cin >> n;

    vector<string> sols = findAll(n);

    for (const string& sol : sols) {
        cout << sol << endl;
    }

    return 0;
}
