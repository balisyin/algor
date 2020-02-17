/** balis 20200217 华为蛇形字符串
 输入一个字符串（不含空格）， 请寻找输入中包含所有蛇形字符串。
蛇形字符串定义：

1.蛇形字符串由连续字符对组成，其特点如下：
1.1 字符对定义：字符对由同一字母的大写和小写组成（前大后小）。如：Aa，Dd；
1.2 蛇形字符串中包含的字符对，必须是连续字母，并按照字母顺序排序。如：AaBbCc或OoPpQqRrSs；

2.从输入中寻找字符组成蛇形字符串（字符顺序不限），符合规则：
2.1 每次寻找必须是最长的蛇形字符串；
2.2 使用过的字符不能重复使用；

例： 输入SxxsrR^AaSs
输出:
please input string:SxxsrR^AaSs
Aa
RrSs
Ss
 **/

#include<iostream>
#include<map>

using namespace std;
int main() {
    cout << "please input string:";
    string str;
    cin >> str;
    map<char, int> charCnt;
    for (auto i = 0; i < str.size(); i ++) {
        charCnt[str[i]] ++;
    }
    bool gotSnake=false;
    for (auto i = 'A'; i < 'Z'; i++) {
        gotSnake = false;
        for (auto ch = i; ; ch++) {
            char lowLetter = tolower(ch);
            if (charCnt[ch] > 0 && charCnt[lowLetter] >0) {
                cout << ch << lowLetter;
                charCnt[ch]--;
                charCnt[lowLetter]--;
                gotSnake = true;
            } else
            {
                //cout << endl;
                break;
            }
            
        }
        if (gotSnake) {
            cout << endl;
        }
    }
    //cout << endl;
    return 0;
}