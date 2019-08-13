/* *
 * balisyin 20190211
 * optimal substructure && overlap subproblem
 * */

//矩阵链相乘，找出最优方法 例如ABC是(AB)C还是A(BC)


///DP6 MatrixChainMultiplication
//mcm(int arr[], int l, int r) = mcm(arr, l, k) + mcm(arr, k+1, r) + arr[l-1]*arr[k]*arr[r];
int mcm(int arr[], int l, int r){
    int min_v = INT_MAX;
    int tmp;
    if(l == r)
        return 0;
    for(int i = l; i < r; ++i){
        tmp = mcm(arr, l, i) + mcm(arr, i+1, r) + arr[l-1]*arr[i]*arr[r];
        if(tmp < min_v)
            min_v = tmp;
    }

    return min_v;
}//recursion
int mcm(int arr[], int n){
    int tmp[n][n];
    int min;
    int i,j,k,len;
    
    for(i = 0; i < n; ++i){
        tmp[i][i] = 0;
    }
    for(len=2; len < n; ++len){
        for(i=1; i < n - len +1; ++i){
            j = i + len;
            int tmp[i][j] = INT_MAX;
            for(k = i; k < j; k++){
                min = tmp[i][k] + tmp[k+1][j] + arr[i-1]*arr[k]*arr[r];
                if(min < tmp[i][j]){
                    tmp[i][j] = min;
                }
            }
            
        }
    }
    return tmp[1][n-1];

}//loop