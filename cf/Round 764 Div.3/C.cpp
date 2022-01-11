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
int _,n,a[2*N];

inline void solve(){
    bool ans = false;
    int flag[55];
    rep(i,1,n) flag[i] = 0;
    rep(i,1,n){
        while(a[i] > n) a[i] /= 2;
        flag[ a[i] ]++;
    }
    per(i,n,1){
        if(!flag[i]) break;
        if(i == 1){
            ans = true;
            break;
        }
        else flag[ i/2 ] += flag[i]-1 , flag[i] = 1;
    }
    if(ans) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    cin >> _;
    while(_--){
        cin >> n;
        rep(i,1,n) cin >> a[i];
        solve();
    }


    return 0;
}


