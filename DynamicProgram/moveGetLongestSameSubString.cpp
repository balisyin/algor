/* *
 * balisyin 20190211
 * optimal substructure && overlap subproblem
 * */

//m次移动得到最长相同字符串


///DP m move to get longest same substring
///like str = "ababa" m = 2; get str="baaab"
#define ALPHA 26

int sameLen(int m, int n, int arr[]){
    if(m == n)
        return 0;
    if(m + 1 == n)
        return arr[n] - arr[m] - 1;
    else {
        return sameLen(m+1, n-1, arr) + arr[n] - arr[m] - (n - m);
    }
}

int getSameLen(string str, num) {
    int len = str.length();
    int matrix[len][ALPHA];
    int letter[ALPHA];
    int m[len];
    memset(arr, 0, sizeof(len*ALPHA)); 
    memset(letter, 0, ALPHA);
    memset(m, 0, len);
    int i,j,k;
    for(i = 0; i < len; ++i){
        matrix[i][str[i]-'a'] = 1;
    }
    for(j = 0; j < ALPHA; ++j){
        k = 0;
        for(i = 0; i < len; ++i){
            if(matrix[i][j] == 1)
                m[k++] = i;
        }
        if(k == 1){
            letter[j] = 1;
        } else {
            for(i = 0; i < k; ++i){
                for(int ii = i+1; ii < k; ++ii){
                    if(sameLen(i, ii, m) < num){
                        if(ii - i + 1 > tmp)
                            tmp = ii - i + 1;
                    }
                }
            }
        }
        letter[j] = tmp;
    }
    int max = -1;
    for(i = 0; i < ALPHA; ++i){
        if(letter[i] > max)
            max = letter[i];
    }

    retrun max;
}