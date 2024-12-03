// Question Link - https://leetcode.com/problems/palindrome-partitioning/description/

// Given a string s, partition s such that every 
// substring
//  of the partition is a 
// palindrome
// . Return all possible palindrome partitioning of s.

 

// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
// Example 2:

// Input: s = "a"
// Output: [["a"]]
 

// Constraints:

// 1 <= s.length <= 16
// s contains only lowercase English letters.

#include<bits/stdc++.h>
using namespace std;

bool checker(string& s, int i, int j) {
    while (i < j) {
        if (s[i++] != s[j--])
            return false;
    }
    return true;
}

void helper(string& s, vector<vector<string>>& res, vector<string>& temp, int index) {
    if (index == s.size()) {
        res.push_back(temp);
        return;
    }
    for (int i = index; i < s.size(); i++) {
        if (checker(s, index, i)) {
            temp.push_back(s.substr(index, i - index + 1));
            helper(s, res, temp, i + 1);
            temp.pop_back();
        }
    }
}

vector<vector<string>> findAll(string s) {
    vector<vector<string>> res;
    vector<string> temp;
    helper(s, res, temp, 0);
    return res;
}

int main() {
    string s;
    cin >> s;

    vector<vector<string>> sols = findAll(s);

    for (const auto& sol : sols) {
        for (const string& i : sol) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
