// Given a string, we have to find out all its subsequences of it. A String is said to be a subsequence of another String, if it can be obtained by deleting 0 or more character without changing its order.

// Examples: 

// Input : ab
// Output : “”, “a”, “b”, “ab”

// Input : abc
// Output : “”, “a”, “b”, “c”, “ab”, “ac”, “bc”, “abc”

#include <bits/stdc++.h>
using namespace std;
void helper(string s, string curr){
    if (s.empty()){
        cout << curr << endl;
        return;
    }
    helper(s.substr(1), curr + s[0]);
    helper(s.substr(1), curr);
}
void findAll(string s){
    string curr = ""; 
    helper(s, curr);
}
int main(){
    string s;
    cin>>s;
    findAll(s); 
    return 0;
}