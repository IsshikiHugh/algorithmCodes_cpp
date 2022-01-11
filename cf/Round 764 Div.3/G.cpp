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
inline bool cmp(int x,int y){return x < y;}
/* -fsanitize=undefined  */
const int N = 1e6+9;
const int inf = 1e9+9;
const double eps = 1e-7;
int _,n,m;

int u[2*N],v[2*N],w[2*N];

struct node{
    int fa[2*N],size;
    
    inline void init(int n){
        size = n;
        rep(i,1,n) fa[i] = i;
    }

    inline int getf(int x){
        return fa[x] == x ? x : fa[x] = getf(fa[x]);
    }

    inline void merge(int x,int y){
        int fx = getf(x) , fy = getf(y);
        if(fx == fy) return;
        fa[ fy ] = fx , --size;
    }
};

inline void solve(){
    int ans = 0 , ban = 0;
    cin >> n >> m;
    rep(i,1,m) cin >> u[i] >> v[i] >> w[i];
    per(k,30,0){
        node p;
        p.init(n);

        ban |= (1<<k);

        rep(i,1,m){
            if((w[i] & ban) == 0){
                p.merge(u[i],v[i]);
            }
        }

        if(p.size > 1){
            ans |= (1<<k);
            ban ^= (1<<k);
        }
    }
    cout << ans << "\n";
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif 
    cin >> _;
    while(_--){
        solve();
    }
    return 0;
}

