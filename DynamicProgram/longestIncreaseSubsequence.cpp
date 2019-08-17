/* *
 * balisyin 20190211
 * optimal substructure && overlap subproblem
 * */

//最长递增子序列
///DP1 LIS longest increase subsequence
int lis_int(int arr[], int n){
    int max_len = -1;
    int lis[n];
    memset(lis, 0, sizeof(int)*n);
    lis[0] = 1;
    for(int i = 1; i < n; ++i){
        lis[i] = 1;
        for(int j = 0; j < i; ++j){
            if(arr[j] < arr[i] && lis[i] < lis[j] + 1){
                lis[i] = lis[j] + 1;
            }
        }
    }
    for(i = 0; i < n; ++i){
        if(max_len < lis[i])
            max_len = lis[i];
    }
    return max_len;
}