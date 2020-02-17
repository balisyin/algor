 #include <iostream>
 
using namespace std;
 
const int N = 1000010, M = 2010;
 
int n, m;
int c[N], s[M];
/*
12 5
2 5 3 1 3 2 4 1 0 5 4 3 
1 2 3 4 5  4 1 2 2 4 3 5
2 5 3 1 【3 2 4 1 0 5】 4 3 
*/
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &c[i]);
    int res = n + 1;
 
    int colors = 0;
    for (int i = 1, j = 0; i <= n; i ++ )
    {
        if (c[i] && !s[c[i]]) colors ++ ;
        s[c[i]] ++ ;
 
        if (colors == m)
        {
            while (!c[j] || s[c[j]] > 1)
            {
                s[c[j]] -- ;
                j ++ ;
            }
            res = min(res, i - j + 1);
        }
    }
 
    if (res > n) res = -1;
    cout << res << endl;
 
    return 0;
}