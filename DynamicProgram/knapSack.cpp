/* *
 * balisyin 20190211
 * optimal substructure && overlap subproblem
 * */

//背包问题

///DP8 0-1KnapSack
//knapSack(int cap, int wt[], int val[], int n)
// = max(knapSack(cap, wt, val, n-1), val[n-1] + knapSack(cap-wt[n-1],wt,val,n-1))
int knapSack(int cap, int wt[], int val[], int n){
    if(cap == 0 || n == 0)
        return 0;
    if(cap < wt[n-1])
        return knapSack(cap, wt, val, n-1);
    else
    {
        return max(knapSack(cap,wt,val,n-1), val[n-1] + knapSack(cap-wt[n-1], wt, val, n-1));
    }  
}//recursive

int knapSack(int cap, int wt[], int val[], int n){
    int tmp[cap][n];
    int i,j;
    for(i = 0; i < cap; ++i){
        for(j = 0; j < n; ++j){
            if(i = 0 || j = 0){
                tmp[i][j] = 0;
            }
            if(wt[j-1] > i)
                tmp[i][j] = tmp[i][j-1];
            else 
                tmp[i][j] = max(tmp[i][j-1], val[j-1] + tmp[i-wt[j-1]][j-1]);
        }
    }
    return tmp[cap][n];

}//iterate
