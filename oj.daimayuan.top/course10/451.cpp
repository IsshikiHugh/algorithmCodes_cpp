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

int n, m;
vector<int> a, f, dep;
int fa[2*N][MD+1];

int next[2*N], head[2*N], ver[2*N], tot;
inline void link(int u,int v){ ver[++tot] = v, next[tot] = head[u] , head[u] = tot; }

void dfs(int cur,int father){
    fa[cur][0] = father, dep[cur] = dep[father] + 1;
    f[cur] = a[cur] ^ f[father];
    for(int i = head[cur];i;i = next[i]){
        if(ver[i] == father) continue;
        dfs(ver[i], cur);
    }
}

inline int LCA(int x,int y){
    if(dep[x] > dep[y]) std::swap(x,y);
    per(d,20,0){
        if(dep[x] <= dep[ fa[y][d] ]) y = fa[y][d];
    }
    if(x == y) return x;
    per(d,20,0){
        if(fa[x][d] != fa[y][d]) x = fa[x][d] , y = fa[y][d];
    }
    return fa[x][0];
}

inline int query(int u,int v){
    return f[u] ^ f[v] ^ a[ LCA(u,v) ];
}

void solve(){
    cin >> n >> m;
    a.resize(n+1), f.resize(n+1), dep.resize(n+1);
    a.clear(), f.clear(), dep.clear();
    rep(i,1,n) cin >> a[i];
    rep(i,1,n-1){
        int u, v;
        cin >> u >> v;
        link(u,v);
    }

    dep[0] = f[0] = 0;
    dfs(1,0);
    rep(d,1,MD) rep(i,1,n)
        fa[i][d] = fa[ fa[i][d-1] ][d-1];

    while(m--){
        int u,v;
        cin >> u >> v;
        cout << query(u,v) << "\n";
    }
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
