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
int _,n,m,opt;
int a[2*N];

int tot;
struct node{
    int l,r;
    ll sum,tag;
    node *ls , *rs;
    inline int dis(){return r-l+1;}
}T[2*N];

inline node * create(){ return &T[++tot]; }

inline void pushup(node *cur){ cur->sum = cur->ls->sum + cur->rs->sum; }

inline void pushdown(node *cur){
    cur->ls->tag += cur->tag;
    cur->ls->sum += cur->tag * cur->ls->dis();
    cur->rs->tag += cur->tag;
    cur->rs->sum += cur->tag * cur->rs->dis();
    cur->tag = 0;
}

inline void build(node *cur,int l,int r){
    cur->l = l , cur->r = r;
    if(l == r){
        cur->sum = a[l];
        return;
    }
    int mid = (l+r)>>1;
    build( cur->ls = create() , l , mid );
    build( cur->rs = create() , mid+1 , r );
    pushup(cur);
    return;
}

inline ll updateSection(node *cur,int l,int r,int k){
    if(r < cur->l || cur->r < l) return 0;
    else if(l <= cur->l && cur->r <= r) return ( cur->tag += k , cur->sum += k * cur->dis() );
    else {
        pushdown(cur);
        ll res = updateSection(cur->ls,l,r,k) + updateSection(cur->rs,l,r,k);
        pushup(cur);
        return res;
    }
}

void solve(){
    cin >> n >> m;
    node * root = create();
    rep(i,1,n) cin >> a[i];
    build(root,1,n);

    while(m--){
        int x,y,k;
        cin >> opt;
        switch (opt){
        case 1:
            cin >> x >> y >> k;
            updateSection(root,x,y,k);
            break;
        case 2:
            cin >> x >> y;
            cout << updateSection(root,x,y,0) << "\n";
            break;
        }
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
