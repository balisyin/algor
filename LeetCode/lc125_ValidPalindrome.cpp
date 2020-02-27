/*20200221 balis [Leetcode] 125. Valid Pallindrome
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.
*/

#include<iostream>
using namespace std;
int main(){
    string str;
    cin >> str;
    int l=0, r=str.length() -1;

    while(l <r) {
        while(!isalnum(str[l]) && l < r) l++;
        while (!isalnum(str[r]) && l< r) r--;
        if (toupper(str[l]) != toupper(str[r])) {   
            cout << false <<endl;
            return 0;
        }
        l++;
        r--;
    }

    cout << true << endl;
    return 0;
}