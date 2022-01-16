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
using std::string;using std::set;using std::queue;using std::vector;
using std::sort;
inline ll max(ll x,ll y){return x > y ? x : y;}
inline ll min(ll x,ll y){return x < y ? x : y;}
inline bool cmp(int x,int y){return x < y;}
/* -fsanitize=undefined  */
const int N = 1e6+9;
const int inf = 1e9+9;
const double eps = 1e-7;
int _,n,nmax,ans;
int a[2*N],vis[2*N];

inline int gcd(int x,int y){ return !y ? x : gcd(y,x%y); }

void solve(){
    ans = 0;
    cin >> n;
    rep(i,1,n) cin >> a[i];
    nmax = a[1];
    rep(i,2,n) nmax = nmax > a[i] ? nmax : a[i];
    rep(i,1,nmax) vis[i] = 0;
    rep(i,1,n) ++vis[ a[i] ];
    rep(i,1,nmax){
        if(!vis[i]){
            int g = 0;
            for(int j = i*2;j <= nmax;j += i) 
                if(vis[j]) g = gcd(j,g);
            ans += i == g;
        }
    } 
    cout << ans << "\n";
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    _ = 1;
    // cin >> _;
    while(_--) solve();
    return 0;
}
