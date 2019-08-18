/** balis 20190818 
 * Shopee的*通配符，牛客网上 **/

#include<iostream>
#include<string>
using namespace std;

bool isStringMatch(string str1, string str2, int first, int second, int start, int len) {
    if(str1[first] == '\0') {
        cout << start << " " << len << endl;
        return true;
    }
    if(str1[first] != '\0' && str2[second] == '\0') {
        return false;
    }
    if(str1[first] == '*') {
        auto tmp1 = isStringMatch(str1, str2, first+1, second, start, len);//第一个字符串后移
        auto tmp2 = isStringMatch(str1, str2, first, second+1, start, len+1);//第二个字符串后移
        return tmp1 || tmp2;
    }else{
        if(str1[first] == str2[second]) {
            return isStringMatch(str1, str2, first+1, second+1, start, len+1);
        } else{
            return false;
        }
    }

}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    bool res = false;

    if(str1 == "*") {
        for(auto i = 0; i < str2.size(); i++) {
            for(auto j= 1; i + j < str2.size(); j++) {
                cout << i << " " << j << endl;
            }
        }
        return 0;
    }

    for(auto i = 0; i < str2.size(); i++) {
        if (isStringMatch(str1, str2, 0, i, i, 0)) {
            res = true;
        }
    }
    if (!res) {
        cout << -1 << " " << 0 << endl;
    }
    

    return 0;
}


/* 例子如下
o*m
shopeemobile.com

2 5
2 14
7 9
14 2
 */