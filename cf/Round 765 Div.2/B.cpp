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
using std::set;using std::pair;using std::map;using std::sort;
/* -fsanitize=undefined  */
const int N = 1e6+9;
const int inf = 1e9+9;
const double eps = 1e-7;
int _,n,a[2*N],ans;

struct node1{
    
};

inline ll max(ll x,ll y){return x > y ? x : y;}
inline ll min(ll x,ll y){return x < y ? x : y;}
inline bool cmp(int x,int y){return x < y;}
inline void init(){

}

inline void solve();

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    cin >> _;
    while(_--) solve();
    return 0;
}

inline void solve(){
    cin >> n;
    ans = -1;
    rep(i,1,n) cin >> a[i];
    map<int,int> mp;
    rep(i,1,n){
        auto it = mp.find(a[i]);
        if(it != mp.end()) ans = std::max(ans,n - (i-it->second));
        mp[ a[i] ] = i;
    }
    cout << ans << "\n";
}
