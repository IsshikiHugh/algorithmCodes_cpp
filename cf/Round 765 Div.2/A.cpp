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
const int N = 1e6+9;
const int inf = 1e9+9;
const double eps = 1e-7;
int _,n,l,a[2*N],cnt0,cnt1,ans;

inline void solve(){
    cin >> n >> l;
    ans = 0;
    rep(i,1,n) cin >> a[i];
    per(i,l-1,0){
        cnt0 = cnt1 = 0;
        int p = 1<<i;
        rep(j,1,n){
            if(p&a[j]) ++cnt1;
            else ++cnt0;
        }
        if(cnt1 > cnt0) ans = 1+ans*2;
        else ans = 0+ans*2;
    }
    cout << ans << "\n";
}


int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    cin >> _;
    while(_--){
        solve();
    }
    


    return 0;
}

