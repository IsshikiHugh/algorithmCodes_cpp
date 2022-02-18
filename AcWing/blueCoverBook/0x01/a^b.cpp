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
int _;

// calculate a^p % mod
// use _pow((ll)a,(int)p,(ll)mod)
// or _pow((ll)a,(int)p)
ll _pow(ll a,int p,ll mod = 0){
    ll base = a, ret = 1;
    while(p){
        if(p&1) ret = (mod) ? (base * ret % mod) : (base * ret);
        base = (mod) ? (base * base % mod) : (base * base);
        p >>= 1;
    }
    return (mod) ? (ret % mod) : (ret);
}

void solve(){
    int a,b,p;
    cin >> a >> b >> p;
    cout << _pow(a,b,p);
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
