/* *
 * balisyin 20190211
 * optimal substructure && overlap subproblem
 * */

//二项式系数


///DP7 BinomialCoefficient
//Selelct(n,k) = Select(n-1,k-1) + Select(n-1,k)
//if k==0||k==n Select(n,k) = 1;
int BinomialCoefficient(int n, int k){
    int tmp[k+1];
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j < min(i,k); ++j){
            if(j == 0 || j == i)
                tmp[j] += tmp[j-1]
        }
    }

    return tmp[k];
}