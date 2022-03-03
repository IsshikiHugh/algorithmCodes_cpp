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
const int N = 2e5+9;
const int inf = 0x3F3F3F3F;
const double eps = 1e-7;
const int MD = 20;

int n, l, r;
vector<int> a, b;
vector<int> vis;

void solve(){
    cin >> n;
    a.resize(n+1), a.clear();
    b.resize(n+1), b.clear();
    vis.resize(n+1), vis.clear();
    rep(i,1,n) cin >> b[i];
    rep(i,1,n) a[i] = (a[i-1] + b[i])%n;
    rep(i,1,n){
        if(a[i] == 0) l = 1, r = i;
        else if(vis[ a[i] ]) l = vis[ a[i] ] + 1, r = i;
        else vis[ a[i] ] = i;
        if(l) break;
    }

    cout << r-l+1 << "\n";
    rep(i,l,r) cout << i << " ";
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
