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
int _,n,len;
int a[2*N];
int dd[2*N];

void init(){
    dd[0] = 1;
    rep(i,1,20){
        dd[i] = dd[i-1] * 2;
    }
}


void solve(){
    cin >> n;
    rep(i,1,n) cin >> a[i];
    len = 1;
    per(i,n-1,1){
        if(a[i] == a[i+1]) ++len;
        else break;
    }
    int now = n-len+1;
    int cnt = 0;
    while(now > 1){
        now -= len , len *= 2;
        ++cnt;
        while(now >= 2 && a[now-1] == a[n]) --now , ++len;
    }
    cout << cnt << "\n";
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    // _ = 1;
    init();
    cin >> _;
    while(_--) solve();
    return 0;
}
