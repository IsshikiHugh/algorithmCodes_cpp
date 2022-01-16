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
int _,n;
int a[2*N],dd[25],begin[2*N],end[2*N];

inline int cal(int x){
    rep(i,0,20){
        if(dd[i] < x) continue;
        else return dd[i]-x;
    }
    return 0;
}

inline void init(){
    dd[0] = 1;
    rep(i,1,20) dd[i] = dd[i-1] << 1;
}

void solve(){
    int ans = inf,tmp;
    cin >> n;
    rep(i,1,n) cin >> a[i];

    sort(a+1,a+n+1,cmp);
    rep(i,1,n) end[ a[i] ] = i;
    per(i,n,1) begin[ a[i] ] = i;
    // a[1] ~ a[i] , a[i+1] ~ a[i+dd] 
    rep(i,1,n){
        tmp = inf;
        i = end[ a[i] ];
        if(i == n){
            tmp = cal(i) + 2;
            ans = min(ans,tmp);
            break;
        }
        rep(j,0,20){
            int p = i + dd[j];
            if(p > n) break;
            p = end[ a[p] ];
            if(p == n){
                tmp = min(tmp , 1 + cal(p-i));
            } else {
                tmp = min(tmp , cal(p-i) + cal(n-p));
            }
            // cout << i << "  ss  " << tmp << "\n";
            p = begin[ a[p] ]-1;
            if(p > i) tmp = min(tmp , cal(p-i) + cal(n-p));
            else if(p == i) tmp = min(tmp , 1 + cal(n-p));
        }
        tmp += cal(i);
        ans = min(ans,tmp);
    }
    cout << ans << "\n";
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    init();
    // _ = 1;
    cin >> _;
    while(_--) solve();
    return 0;
}

/* 
 * [0,x)
 * [x,y)
 * [y,+)
 */