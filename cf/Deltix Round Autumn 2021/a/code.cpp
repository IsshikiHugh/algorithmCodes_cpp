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
const int N = 20;
const int inf = 1e9+9;
const double eps = 1e-7;
int _,n;
ull a[2*N],cnt[2*N],b[2*N],d[20];


ll cal(ll x){
    int cnt = 0;
    while(x % 2 == 0) ++cnt , x >>= 1;
    return cnt;
}

int main(){
    // std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    d[0] = 1;
    rep(i,1,15){
        d[i] = d[i-1] << 1;
    }
    cin >> _;
    while(_--){
        cin >> n;
        rep(i,1,n) cin >> a[i];
        rep(i,1,n) cnt[i] = cal(a[i]);
        rep(i,1,n) b[i] = a[i] / d[ cnt[i] ];
        ull max = 0;
        rep(i,1,n){
            max = b[i] > max ? b[i] : max;
        }
        ull sum = 0;
        rep(i,1,n) sum += b[i];
        sum -= max;
        rep(i,1,n) max *= d[ cnt[i] ];
        sum += max;
        cout << sum << "\n";
    }


    return 0;
}

