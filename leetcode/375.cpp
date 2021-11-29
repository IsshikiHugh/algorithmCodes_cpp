class Solution {
public:
    #define rep(a,b,c) for(int (a) = (b);(a) <= (c);++(a))
    int n,dp[210][210];

    int getMoneyAmount(int n) {
        rep(i,1,n) rep(j,1,n) dp[i][j] = 50000;
        rep(i,1,n) dp[i][i] = 0;
        rep(i,1,n-1) dp[i][i+1] = i;
        rep(i,1,n-2) dp[i][i+2] = i+1;
        rep(len,4,n){
            rep(i,1,n-len+1){
                int j = i + len - 1;
                rep(k,i+1,j-1){
                    dp[i][j] = std::min(
                        std::max(dp[i][k-1],dp[k+1][j]) + k,
                        dp[i][j]
                    );
                }
            }
        }
        return dp[1][n];
    }
};