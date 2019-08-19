/** balis 20190818 
 * Shopee的统计字符串中字符个数，不区分大小写 **/
#include<iostream>
#include<map>
using namespace std;
int main() {
    string str1;
    cin >> str1;
    map<char, int> charCount;
    for (int i = 0; i < str1.size(); i++) {
        char tmp = tolower(str1[i]);
        charCount[tmp] ++;
    }

    for (auto iter = charCount.begin(); iter != charCount.end(); iter++) {
        cout << iter->first << " " << iter->second << endl;
    }
    return 0;
}