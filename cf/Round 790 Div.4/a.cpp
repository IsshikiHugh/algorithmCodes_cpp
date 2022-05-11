#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<bitset>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iomanip>
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
const int N = 2e5+9;
const int inf = 0x3F3F3F3F;
const double eps = 1e-7;
const int MD = 20;

void solve(){
    string str;
    cin >> str;
    int sum1 = str[0] + str[1] + str[2] - 3*'0';
    int sum2 = str[3] + str[4] + str[5] - 3*'0';
    if(sum1 != sum2) cout << "NO\n";
    else cout << "YES\n";
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    int _ = 1;
    cin >> _;
    while(_--) solve();
    return 0;
}
