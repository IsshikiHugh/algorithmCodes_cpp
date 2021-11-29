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
const int N = 1e7+9;
const int inf = 1e9+9;
const double eps = 1e-7;
int _,n,dp[300010][10],m,s,t,add,st;
// 0 ~ 0
// 1 ~ 2
// 2 ~ 4
// 3 ~ 6
// 4 ~ 8
// 5 ~ 10
// 6 ~ 12

// v = 17
// r = 4
// c = 10
// x = 60


int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    
    cin >> m >> s >> t;
    if(m > 10){
        if(60*(m/10) > s){
            cout << "Yes\n" << (s-1) / 60 + 1 << "\n";
            return 0;
        } else add = m / 10 , st = 60*(m/10) , m %= 10;
    }
    if(add > t){
        cout << "No\n" << t*60 << "\n";
        return 0;
    }
    rep(i,0,t-add) rep(j,0,6) dp[i][j] = -1;
    dp[0][m/2] = st;
    rep(i,0,t-1-add){
        rep(j,0,4){
            if(dp[i][j] < 0) continue;
            dp[i+1][j] = std::max(dp[i+1][j],dp[i][j] + 17);
            dp[i+1][j+2] = std::max(dp[i][j],dp[i+1][j+2]);
        }
        rep(j,5,6){
            if(dp[i][j] < 0) continue;
            dp[i+1][j-5] = std::max(dp[i+1][j-5],dp[i][j] + 60);
        }
        rep(j,0,6){
            if(dp[i+1][j] > s){
                cout << "Yes\n" << i+1+add << "\n";
                return 0;
            }
        }
    }
    int ans = dp[t-add][0];
    rep(i,1,6) ans = std::max(ans,dp[t-add][i]);
    cout << "No\n" << ans << "\n";

    return 0;
}

