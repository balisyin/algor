/*balisyin 20200220
https://interview.nowcoder.com/interview/445006/interviewee?code=p2RKbqSv#userCode

请实现一个函数，输入一个正整数 n，返回与 n 组成数字完全相同，且小于 n 的最大整数。若不存在这样的数，返回 0。例如：
65 => 56
7123 => 3721
8918 => 8891 8819
23 => 0
103 => 0 (前导0不作为组成数字，因此31不符合要求)

*/

#include<iostream>
#include<string>
using namespace std;

 void swapChar(char *a,char *b) {
      char tmp = *a;
        *a = *b;
        *b = tmp;
 }
int main() {
    int num;
    cin >> num;
    if (num < 10) {
        cout << 0 << endl;
        return 0;
    }
    bool getAnswer = false;
    bool rool = false;
    string str = to_string(num);
    for(auto it = str.begin(); it+1 != str.end(); it++){
        if ((*it == '0' || *(it+1) == '0' || *it <= *(it+1)) && getAnswer == false) {
            continue;
        }
        //cout << *it <<endl;
        auto max = it +1;
        char tmp;
        
        for(auto its = it+1; its != str.end(); its++) {
            if (*its > *max) {
                max = its;
            }
        }
        if (getAnswer == false || (*max > tmp)) {
             tmp = *max;
            *max = *it;
            *it = tmp;
        }

        getAnswer = true;

       // break;
    }
    
    if (getAnswer == false) {
        cout << 0 << endl;
        return 0;
    }
    

    int out = atoi(str.c_str());
    cout << out<< endl;


    return 0;
}