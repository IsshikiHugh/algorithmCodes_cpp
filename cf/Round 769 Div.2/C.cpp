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
int a[2*N],dd[2*N];

void init(){
    dd[0] = 1;
    rep(i,1,20) dd[i] = dd[i-1] * 2;
}

void printd(int x){
    per(i,20,0){
        cout << (x>>i);
        x &= (1<<i)-1;
    }
    cout << "\n";
}

void solve(){
    int x,y;
    cin >> x >> y;
    // printd(x);
    // printd(y);
    int ans = y-x;
    rep(i,x,x+ans){
        int tmp = 0;
        per(j,20,0){
            if( !((y>>j)&1) && ((i>>j)&1) ){
                tmp |= (1<<j);
                break;
            } else {
                tmp |= y&(1<<j);
            }
        }
        // printd(tmp);
        ans = min(ans,i-x+(i|tmp)-y+1);
        // cout << i << " " << ans << "\n";

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
