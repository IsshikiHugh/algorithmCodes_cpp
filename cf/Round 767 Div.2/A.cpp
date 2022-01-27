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
/* -fsanitize=undefined  */
const int N = 1e3;
const int inf = 1e9+9;
const double eps = 1e-7;
int _,n,k;

struct node{
    int a,b;
}x[2*N];

inline bool cmp(node x,node y){return x.a < y.a;}

void solve(){
    cin >> n >> k;
    rep(i,1,n) cin >> x[i].a;
    rep(i,1,n) cin >> x[i].b;
    sort(x+1,x+n+1,cmp);
    rep(i,1,n){
        if(x[i].a <= k) k+= x[i].b;
        else break;
    }
    cout << k << "\n";
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    // _ = 1;
    cin >> _;
    while(_--) solve();
    return 0;
}
