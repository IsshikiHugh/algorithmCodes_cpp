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
using std::cin;using std::cout;using std::pair;
using std::string;using std::set;using std::queue;using std::vector;using std::map;
using std::sort;
inline ll max(ll x,ll y){return x > y ? x : y;}
inline ll min(ll x,ll y){return x < y ? x : y;}
inline bool cmp(int x,int y){return x < y;}
/* -fsanitize=undefined  */
const int N = 1e6+9;
const int inf = 1e9+9;
const double eps = 1e-7;

int dp[ 1<<20 ][20];
void solve(){
    int n, dis[30][30];
    cin >> n;
    rep(i,1,n){
        rep(j,1,n){
            cin >> dis[i][j];
        }
    }
    memset(dp,inf,sizeof(dp));
    dp[1][0] = 0;
    rep(i,1,(1<<n)-1){
        rep(j,0,n-1){
            if( !( (i>>j) & 1 ) ) continue;
            rep(k,0,n-1){
                if( (k == j) || !( (i>>k) & 1 ) ) continue;
                dp[i][j] = min( dp[i][j] , dp[i ^ (1<<j)][k] + dis[k+1][j+1] );
            }
        }
    }
    cout << dp[ (1<<n) - 1 ][n-1] << "\n";
    return;
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    int _ = 1;
    // cin >> _;
    while(_--) solve();
    return 0;
}
