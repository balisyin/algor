/* *
 * balisyin 20190211
 * optimal substructure && overlap subproblem
 * */

//最长相同子序列
///DP2 LCS longest common subsequence 

//if(arr1[m-1] == arr2[n-1]) len = lcs(arr1, arr2, m-1, n-1) + 1;
//else len = max(lcs(arr1, arr2, m-1, n), lcs(arr1, arr2, m, n-1))
int lcs(char arr1[], char arr2[], int m, int n){
    int lcs[m][n];
    memset(lcs, 0, sizeof(int) * m * n);
    for(int i = 1; i < m; ++i){
        for(int j = 1; j < n; ++j){
            if(arr1[i] == arr2[j]){
                lcs[i][j] = lcs[i-1][j-1] + 1;
            } else{
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            }
        }
    }
    return lcs[m-1][n-1];

}