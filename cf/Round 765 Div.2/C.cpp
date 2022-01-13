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
using std::set;using std::pair;using std::map;using std::sort;
inline ll max(ll x,ll y){return x > y ? x : y;}
inline ll min(ll x,ll y){return x < y ? x : y;}
inline bool cmp(int x,int y){return x < y;}
/* -fsanitize=undefined  */
const int N = 510;
const int inf = 1e9+9;
const double eps = 1e-7;
int _,n,k,l;
int dp[N][N];

struct node{
    int p,v;
}s[2*N];


int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    cin >> n >> l >> k;
    rep(i,1,n) cin >> s[i].p;
    rep(i,1,n) cin >> s[i].v;
    s[n+1].p = l , s[n+1].v = 0;
    rep(i,1,n+1) rep(j,0,k) dp[i][j] = inf;
    dp[1][0] = 0;
    rep(i,2,n+1){
        rep(j,0,k){
            rep(p,0,j){
                if(i-p-1 <= 0 || j-p < 0) break;
                dp[i][j] = min( dp[i][j] , dp[i-p-1][j-p] + (s[i].p - s[i-p-1].p) * s[i-p-1].v );
            }
        }
    }
    int ans = inf;
    rep(i,0,k) ans = min(ans,dp[n+1][i]);
    cout << ans << "\n";


    return 0;
}
