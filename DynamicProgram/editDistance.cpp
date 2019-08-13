/* *
 * balisyin 20190211
 * optimal substructure && overlap subproblem
 * */

//修改字符串1到字符串2最少操作步数，操作可以是插入/删除/替换
///DP3 EditDistance insert/remove/replace


//if(arr1[m-1] == arr2[n-1]) len = edd(arr1, arr2, m-1, n-1)
//else len = 1 + min(edd(arr1, arr2, m-1, n), edd(arr1, arr2, m, n-1), edd(arr1, arr2, m-1, n-1))
int editDistance(string arr1, string arr2, int m, int n){
    int edd[m+1][n+1];
    memset(edd, 0, size(int)*m*n);
    for(int i = 0; i <= m; ++i){
        for(int j= 0; j <= n; ++j){
            if(i == 0)
                edd[i][j] = j;
            else if(j == 0)
                edd[i][j] = i;
            else{
                if(arr[i-1] == arr[j-1]){
                    edd[i][j] = edd[i-1][j-1];
                }else{
                    edd[i][j] = 1 + min(edd[i][j-1], edd[i-1][j], edd[i-1][j-1]);
                }
            }

            
        }
    }
    return edd[m][n];
}