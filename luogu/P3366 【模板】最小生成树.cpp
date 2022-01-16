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
/* -fsanitize=undefined  */
const int N = 1e6+9;
const int inf = 1e9+9;
const double eps = 1e-7;
int _,n,m,size,ans;
int fa[2*N];

struct node{
    int u,v,w;
}a[2*N];

inline bool cmp(node x,node y){return x.w < y.w;}

inline int getfa(int x){ return fa[x] == x ? x : fa[x] = getfa(fa[x]); }

void solve(){
    cin >> n >> m;
    rep(i,1,n) fa[i] = i;
    rep(i,1,m) cin >> a[i].u >> a[i].v >> a[i].w;
    sort(a+1,a+m+1,cmp);
    size = n;
    rep(i,1,m){
        int fu = getfa( fa[ a[i].u ] );
        int fv = getfa( fa[ a[i].v ] );
        if(fu == fv) continue;
        --size;
        fa[ fv ] = fu;
        ans += a[i].w;
    }
    if(size-1) cout << "orz\n";
    else cout << ans << "\n";

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
