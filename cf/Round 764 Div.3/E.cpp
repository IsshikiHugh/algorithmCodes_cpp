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
int _,n,m,a[1010],b[1010][1010];
int exist[1000],dp[1010];
char ch;

void init(){
    rep(i,0,999) exist[i] = false;
    rep(i,0,m+1) dp[i] = false;
}

void solve(){
    cin >> n >> m;
    init();
    rep(i,1,n){
        rep(j,1,m){
            cin >> ch;
            b[i][j] = ch - '0';
        }
    }
    rep(i,1,m){
        cin >> ch;
        a[i] = ch - '0';
    }

    rep(i,1,n){
        rep(j,1,m){
            if(j+1 <= m) exist[ b[i][j]*10 + b[i][j+1] ] = true;
            if(j+2 <= m) exist[ b[i][j]*100 + b[i][j+1]*10 + b[i][j+2] ] = true;
        }
    }
    if( exist[ a[1]*10  + a[2]] ) dp[2] = true;
    if( exist[ a[1]*100 + a[2]*10 + a[3]] ) dp[3] = true;
    rep(i,4,m){
        if( exist[ a[i-1]*10  + a[i]] ) dp[i] = dp[i-2];
        if( exist[ a[i-2]*100 + a[i-1]*10  + a[i]] ) dp[i] = dp[i-3];
        if(!dp[i]) break;
    }
    if(dp[m]) cout << "YES\n";
    else cout << "NO\n";
}


int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    
    cin >> _;
    while(_--) solve();

    return 0;
}

