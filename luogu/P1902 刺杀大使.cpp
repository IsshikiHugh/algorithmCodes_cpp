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
using std::string;using std::cin;using std::cout;
using std::set;using std::pair;using std::map;using std::queue;
using std::sort;using std::pair;
inline ll max(ll x,ll y){return x > y ? x : y;}
inline ll min(ll x,ll y){return x < y ? x : y;}
inline bool cmp(int x,int y){return x < y;}
/* -fsanitize=undefined  */
const int N = 1e6+9;
const int inf = 1e9+9;
const double eps = 1e-7;
int _,n,m,res,l,r;
int mmap[1010][1010];
queue< pair<int,int> > q;
bool vis[1010][1010];

inline bool bfs(int lim){
    while(q.size()) q.pop();
    q.push( mkp(1,1) );
    rep(i,1,n) rep(j,1,m) vis[i][j] = 0;

    while(q.size()){
        int x = q.front().first , y = q.front().second;q.pop();
        if(vis[x][y]) continue;
        vis[x][y] = true;
        if(x == n) return true;
        if(x > 1 && mmap[ x-1 ][ y ] <= lim && !vis[x-1][y])
            q.push( mkp( x-1 , y ) );
        if(x < n && mmap[ x+1 ][ y ] <= lim && !vis[x+1][y])
            q.push( mkp( x+1 , y ) );
        if(y > 1 && mmap[ x ][ y-1 ] <= lim && !vis[x][y-1])
            q.push( mkp( x , y-1 ) );
        if(y < m && mmap[ x ][ y+1 ] <= lim && !vis[x][y+1])
            q.push( mkp( x , y+1 ) );
    }
    return false;
}

inline void solve(){
    cin >> n >> m;
    l = inf , r = 0;
    rep(i,1,n) rep(j,1,m) cin >> mmap[i][j];
    rep(i,1,n) rep(j,1,m) l = min(l,mmap[i][j]) , r = max(r,mmap[i][j]);
    while(l <= r){
        res = (l+r)/2;
        if(bfs(res)) r = res - 1;
        else l = res + 1;
    }
    cout << l << "\n";
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    // cin >> _;
    _ = 1;
    while(_--) solve();
    return 0;
}
