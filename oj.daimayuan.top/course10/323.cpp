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

void solve(){
    int n;
    cin >> n;
    vector<int> a(n+1), dp(n+1);
    rep(i,1,n){
        cin >> a[i];
    }
    sort(a.begin()+1,a.end(),cmp);
    per(i,n,1){
        dp[i] = 1;
        rep(j,i+1,n){
            if(a[j]%a[i] == 0){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    int ans = 0;
    rep(i,1,n){
        ans = max(ans,dp[i]);
    }
    cout << ans << "\n";
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
