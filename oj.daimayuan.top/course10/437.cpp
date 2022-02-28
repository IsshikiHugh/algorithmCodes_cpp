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
const int inf = 0x3F3F3F3F;
const double eps = 1e-7;

int n, m, k;
int g[128][128];
int dp[128][128][128][2];
// dp[l][r][cnt][0l/1r]

void solve(){
    int ans = inf;
    cin >> n >> k >> m;
    memset(g,inf,sizeof(g));
    memset(dp,inf,sizeof(dp));

    rep(i,1,m){
        int u, v, w;
        // cin >> u >> v >> w;
        cin >> v >> u >> w;
        g[u][v] = min(g[u][v], w);
    }

    if(k == 1){
        cout << "0\n";
        return;
    }

    rep(i,1,n){
        rep(j,i+1,n){
            if(g[i][j] < inf) dp[i][j][2][1] = g[i][j];
            if(g[j][i] < inf) dp[i][j][2][0] = g[j][i];
        }
    }

    rep(cnt,2,k-1){
        rep(len,2,n){
            rep(i,1,n){
                int j = i+len-1;
                if(j > n) break;
                // from i
                if(dp[i][j][cnt][0] < inf){
                    rep(to,1,i-1){
                        if(g[i][to] >= inf) continue;
                        dp[to][j][cnt+1][0] = min(dp[to][j][cnt+1][0], dp[i][j][cnt][0] + g[i][to]);
                    }
                    rep(to,j+1,n){
                        if(g[i][to] >= inf) continue;
                        dp[i][to][cnt+1][1] = min(dp[i][to][cnt+1][1], dp[i][j][cnt][0] + g[i][to]);
                    }
                }
                // from j
                if(dp[i][j][cnt][1] < inf){
                    rep(to,1,i-1){
                        if(g[j][to] >= inf) continue;
                        dp[to][j][cnt+1][0] = min(dp[to][j][cnt+1][0], dp[i][j][cnt][1] + g[j][to]);
                    }
                    rep(to,j+1,n){
                        if(g[j][to] >= inf) continue;
                        dp[i][to][cnt+1][1] = min(dp[i][to][cnt+1][1], dp[i][j][cnt][1] + g[j][to]);
                    }
                }
                
            }
        }
    }
    rep(i,1,n){
        rep(j,i+k-1,n){
            ans = min(ans, dp[i][j][k][0]);
            ans = min(ans, dp[i][j][k][1]);
        }
    }

    cout << ( ans < inf ? ans : -1 );
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