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
int _,n,k;
int a[2*N];

void solve(){
    cin >> n >> k;
    if(n == 4 && k == 3){
        cout << "-1\n";
        return;
    }
    if(n == k+1){
        cout << n-1 << " " << n-2 << "\n";
        cout << 1 << " " << n-3 << "\n";
        cout << 0 << " " << ((n-1)^(n-3)) << "\n";
        rep(i,3,n/2-1){
            cout << i << " " << ((n-1)^i) << "\n";
        }   
        return;
    }

    cout << n-1 << " " << k << "\n";
    if(k != 0) cout << ((n-1)^k) << " " << 0 << "\n";
    rep(i,1,n/2-1){
        if(i == k || i == ((n-1)^k) || ((n-1)^i) == k) continue;
        cout << i << " " << ((n-1)^i) << "\n";
    }   
    return;
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    _ = 1;
    cin >> _;
    while(_--) solve();
    return 0;
}
