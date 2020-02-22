/*20200221 balis [Leetcode] 680. Valid PallindromeII
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True

Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
 
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
*/

#include<iostream>
using namespace std;

bool isPalindrome(string str, int l, int r) ;
int main(){
    string str;
    cin >> str;
    int l=0, r=str.length() -1;

    while(l <r) {
        if(str[l] != str[r]) {
            cout << (isPalindrome(str, l+1, r) || isPalindrome(str, l, r-1)) << endl;
            return 0;
        }
        l++;
        r--;
    }

    cout << true << endl;
    return 0;
}

bool isPalindrome(string str, int l, int r) {
    while(l < r) {
        if (str[l] != str[r]) {
            return false;
        }
        l++;
        r--;
    }
    return true;
}