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


// O(log2 y)
// calculate x * y % mod even they are very big
// use mul(x,y,mod)
ll mulA(ll x,ll y,ll mod){
    x %= mod , y %= mod;
    ll ret = 0, base = x;
    while(y){
        if(y&1) ret = (ret + base) % mod;
        base = 2 * base % mod;
        y >>= 1;
    }
    return ret;
}

// O(1)
// calculate x * y % mod even they are very big
// use mul(x,y,mod)
ll mulB(ll x,ll y,ll mod){
    ll ret = 0;
    ret = (long double)x * y / mod;
    ret = x * y - ret * mod;
    return (ret + mod) % mod;
}

void solve(){
    ll a,b,p;
    cin >> a >> b >> p;
    cout << mulA(a,b,p);
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
