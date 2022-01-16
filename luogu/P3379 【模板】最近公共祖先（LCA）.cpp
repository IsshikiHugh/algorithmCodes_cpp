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
const int N = 5e5+9;
const int inf = 1e9+9;
const double eps = 1e-7;
int _,n,T,root,u,v;
int a[2*N],depth[2*N],fa[2*N][21];

int ver[2*N],head[2*N],next[2*N],tot;
inline void link(int x,int y){ ver[++tot] = y , next[tot] = head[x] ,head[x] = tot; }

void dfs(int now,int father){
    depth[now] = depth[father] + 1;
    fa[now][0] = father;
    for(int i = head[now];i;i = next[i]){
        if( ver[i] != father ) dfs(ver[i],now);
    }
    return;
}

inline int LCA(int x,int y){
    if(depth[x] > depth[y]) std::swap(x,y);
    per(d,20,0){
        if(depth[x] <= depth[ fa[y][d] ]) y = fa[y][d];
    }
    if(x == y) return x;
    per(d,20,0){
        if(fa[x][d] != fa[y][d]) x = fa[x][d] , y = fa[y][d];
    }
    return fa[x][0];
}

void solve(){
    cin >> n >> T >> root;

    rep(i,1,n-1){
        cin >> u >> v;
        link(u,v) , link(v,u);
    }
    dfs(root,0);
    rep(d,1,20){
        rep(i,1,n){
            fa[i][d] = fa[ fa[i][d-1] ][d-1];
        }
    }
    while(T--){
        cin >> u >> v;
        cout << LCA(u,v) << "\n";
    }


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
