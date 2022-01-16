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
/* -fsanitize=undefined  */
const int N = 1e6+9;
const int inf = 1e9+9;
const double eps = 1e-7;
int _,n;;

struct monster{
    int k , h , x;
}a[2*N];

inline ll cost(int x){ return (ll)(x+1)*(x)/2; }

inline bool cmp(monster x,monster y){
    if(x.x != y.x) return x.x > y.x;
    else return x.k < y.k;
}

void solve(){
    ll ans = 0;
    cin >> n;
    rep(i,1,n) cin >> a[i].k;
    rep(i,1,n) cin >> a[i].h;
    rep(i,1,n) a[i].x = a[i].h - a[i].k;
    sort(a+1,a+n+1,cmp);
    monster pre;
    pre = a[1];
    rep(i,2,n){
        if(a[i].k < pre.k) continue;
        else if(a[i].k - a[i].h < pre.k) pre.h += a[i].k - pre.k , pre.k = a[i].k;
        else{
            ans += cost(pre.h);
            pre = a[i];
        }
    }
    ans += cost(pre.h);
    cout << ans << "\n";
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    // _ = 1;
    cin >> _;
    while(_--) solve();
    return 0;
}
