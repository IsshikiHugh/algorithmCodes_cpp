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

struct NUM{
    ll val;
    int pos;
};

NUM min(NUM x, NUM y){ return x.val < y.val ? x : y; }
NUM max(NUM x, NUM y){ return x.val > y.val ? x : y; }

struct node{
    int l,r;
    NUM max,min;
    node *ls,*rs;
} T[2*N];
int tot;

node * create(){ return &T[++tot]; }

void pushUp(node * cur){
    if(cur->l == cur->r) return;
    cur->max = max(cur->ls->max,cur->rs->max);
    cur->min = min(cur->ls->min,cur->rs->min);
}

void build(node * cur,int l,int r, const vector<int> &a){
    cur->l = l, cur->r = r;
    if(l == r){
        cur->l = cur->r = l, 
        cur->max = cur->min = NUM{a[l],l};
        return;
    }
    int mid = (l+r)>>1;
    cur->ls = create(), cur->rs = create();
    build(cur->ls,l,mid,a), build(cur->rs,mid+1,r,a);
    pushUp(cur);
}

pair<NUM,NUM> query(node * cur,int l,int r){
    if(l <= cur->l && cur->r <= r) return mkp(cur->min, cur->max);
    if(r < cur->l || l > cur->r) return mkp(NUM{inf,0},NUM{-inf,0});
    pair<NUM,NUM> pl, pr;
    pl = query(cur->ls,l,r);
    pr = query(cur->rs,l,r);
    return mkp( min(pl.first,pr.first), max(pl.second,pr.second) );
}

ll calcHigh(node * root, int l, int r){
    if(l >= r) return 0;
    auto cur = query(root,l,r).second;
    return calcHigh(root, l, cur.pos-1) + calcHigh(root, cur.pos+1, r) + cur.val * ( (ll)(cur.pos - l) * (r - cur.pos) + (cur.pos - l) + (r - cur.pos) );
}

ll calcLow(node * root, int l, int r){
    if(l >= r) return 0;
    auto cur = query(root,l,r).first;
    return calcLow(root, l, cur.pos-1) + calcLow(root, cur.pos+1, r) + cur.val * ( (ll)(cur.pos - l) * (r - cur.pos) + (cur.pos - l) + (r - cur.pos) );
}

void solve(){
    vector<int> a;
    int n;
    cin >> n;
    a.resize(n+1);
    rep(i,1,n) cin >> a[i];
    node * root = create();
    build(root,1,n,a);
    ll sum = 0;
    sum = calcHigh(root,1,n);
    sum -= calcLow(root,1,n);
    cout << sum << "\n";
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
