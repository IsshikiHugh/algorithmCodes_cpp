#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<bitset>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define rep(i,a,b) for(int i = (a);i <= (b);++i)
#define per(i,a,b) for(int i = (a);i >= (b);--i) 
#define mkp std::make_pair
typedef long long ll;
typedef unsigned long long ull;
using std::string;using std::cin;using std::cout;
inline bool cmp(int x,int y){return x < y;}
/* -fsanitize=undefined  */
const int N = 1e6+9;
const int inf = 1e9+9;
const double eps = 1e-7;
int mod = 998244353;
int _,n,a[2*N],cnt1,ans,dp[2*N][2];

ll quick_power(ll x,ll p){
    ll base = x, ans = 1;
    while(p){
        if(p&1) ans = (ans * base)%mod;
        base = (base * base)%mod;
        p >>= 1;
    }
    return ans%mod;
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    cin >> _;
    while(_--){
        ans = cnt1 = 0;
        rep(i,0,n) dp[i][0] = dp[i][1] = -1;

        cin >> n;
        rep(i,1,n) cin >> a[i];

        rep(i,1,n) if(a[i] == 1) cnt1 = (cnt1+1)%mod;
        ans = (ans+quick_power(2,cnt1)-1)%mod;

        // dp[i][1] 表示 MEX = i-1 , dp[i][0] 表示 MEX = i+1;
        int p; // p 表示 当前a[i]
        rep(i,1,n){
            if(a[i] == 0){
                if(dp[0][0] == -1) dp[0][0] = 1;
                else dp[0][0] = ( 2 * dp[0][0] + 1)%mod;
                if(dp[2][1] != -1) dp[2][1] = (dp[2][1] * 2)%mod;
            } else {
                p = a[i];
                if(dp[p][0] != -1) dp[p][0] = (dp[p][0] * 2)%mod;
                if(dp[p][1] != -1) dp[p][1] = (dp[p][1] * 2)%mod;
                if(dp[p-1][0] != -1) dp[p][0] = ( std::max(0,dp[p][0]) + dp[p-1][0] )%mod;
                if(p > 1) if(dp[p-2][0] != -1) dp[p][1] = ( std::max(0,dp[p][1]) + dp[p-2][0] )%mod;
                if(dp[p+2][1] != -1) dp[p+2][1] = (dp[p+2][1] * 2)%mod;
            }
        }
        rep(i,0,n){
            if(dp[i][0] != -1) ans = ( ans + dp[i][0] )%mod;
            if(dp[i][1] != -1) ans = ( ans + dp[i][1] )%mod;
        }
        cout << ans << "\n";
    }
    return 0;
}

