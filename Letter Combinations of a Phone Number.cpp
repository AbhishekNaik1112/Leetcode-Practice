// Question Link - https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = ""
// Output: []
// Example 3:

// Input: digits = "2"
// Output: ["a","b","c"]
 

// Constraints:

// 0 <= digits.length <= 4
// digits[i] is a digit in the range ['2', '9'].

#include<bits/stdc++.h>
using namespace std;

vector<string> findAll(string digits) {
    unordered_map<char, string> phone = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
    };

    vector<string> res;
    vector<string> temp;

    if (digits.empty())
        return res;

    res.push_back(""); 

    for (char ch : digits) {
        string letters = phone[ch];
        for (string x : res) {
            for (char letter : letters) {
                temp.push_back(x + letter);
            }
        }
        res = move(temp); 
    }
    return res;
}

int main() {
    string digits;
    cin >> digits;

    vector<string> sols = findAll(digits);

    for (const string& sol : sols) {
        cout << sol << " ";
    }
    cout << endl;

    return 0;
}
