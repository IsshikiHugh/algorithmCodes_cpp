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
int _,n,m;
int a[2*N];

inline int dis(int x,int y,int xx,int yy){return std::abs(x-xx)+std::abs(y-yy);}

void solve(){
    int r = 0,rMax,base,cnt;
    cin >> n >> m;
    if(n > m) std::swap(n,m); // keep n <= m

    cnt = -1;
    if(n%2 == 1 && m%2 == 1) base = 1;
    else if(n%2 == 0 && m%2 == 0) base = 4;
    else base = 2;

    rMax = dis(n,m,(n+1)/2,(m+1)/2);

    int nn = n , mm = m;
    n = (n+1)/2 , m = (m+1)/2;
    int d1 = 0,d2 = 0;
    if(mm%2 == 0) d1 = 2;
    if(nn%2 == 0) d2 = 2;
    rep(k,0,nn*mm-1){
        if(n-r > 0){
            ++cnt;
            if(cnt >= base) cnt = 0 , base += 4 , ++r;
            if(base == 5) --base;
        } else if(m-r > 0){
            // cout << "\nqaq  " << k << " "<< cnt << " " << base + (n-r-1)*4 + 2 << "\n";
            ++cnt;
            if(cnt >= base + (n-r-1)*4 + 2 - d1) cnt = 0 , base += 4 , ++r;
        } else {
            ++cnt;
            if(cnt >= base + (n-r-1)*4 - d1 + (m-r-1)*4 + 4 - d2) cnt = 0 , base += 4 , ++r;

        }
        
        cout << rMax + r << " ";
       
    }
    cout << "\n";

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
