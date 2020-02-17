/*balis 20190217
You are a dog -> dog are a You
*/

#include<iostream>
#include<string.h>
using namespace std;
void strReverse(char *start, char *end);

int main() {
   const char *str = "You are a dog";
    int len = strlen(str);
   // char newStr[len];
    char *newStr = new char[len]();
    strcpy(newStr, str);
    strReverse(newStr, newStr+len-1);

    cout << str << endl;
    char *tmp = newStr;
    char *start = newStr;
    while(*tmp != '\0') {
        if (*tmp == ' ') {
            strReverse(start, tmp-1);
            start = tmp +1;
        }
        
        tmp++;
        if (*tmp == '\0') {
            strReverse(start, tmp-1);
        }
    }
    cout << newStr << endl;

    return 0;
}

void strReverse(char *start, char *end) {
    char tmp;
    while (start < end)
    {
        tmp = *start;
        *start++ = *end;
        *end-- = tmp;
    }
    
}