/* *
 * balisyin 20190211
 * optimal substructure && overlap subproblem
 * */

//二维数组左上到右下最短路径


///DP4 MinCostPath minCostPath(int arr[][], int m, int n)
//mcp(arr, m, n) = arr[i][j] + min(mcp(arr, i-1, j),mcp(arr, i, j-1), mcp(arr, i-1,j))
int mcp(int arr[][], int m, int n){
    int m = INT_MAX;
    int tmp[m][n];
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(i == 0 && j == 0){
                tmp[i][j] = arr[i][j];
            }else if(i == 0){
                tmp[i][j] = arr[i][j] + tmp[i][j-1];
            }else if(j == 0){
                tmp[i][j] = arr[i][j] + tmp[i-1][j];
            }else{
                tmp[i][j] = arr[i][j] + min(tmp[i-1][j], tmp[i][j-1], tmp[i][j]);
            }
        }
    }
    return tmp[m-1][n-1];
}