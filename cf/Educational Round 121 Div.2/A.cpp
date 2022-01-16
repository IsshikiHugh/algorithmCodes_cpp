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
int a[2*N];
char x[2*N],y[2*N];
char ch[2*N];

void solve(){
    string str;
    cin >> str;
    n = str.length();
    rep(i,1,n) ch[i] = str[i-1];
    sort(ch+1,ch+n+1);
    x[0] = y[0] = 0;
    ch[n+1] = 0;
    rep(i,1,n){
        if(ch[i] == ch[i+1]){
            x[ ++x[0] ] = ch[i];
            ++i;
        } else {
            y[ ++y[0] ] = ch[i];
        }
    }
    rep(i,1,x[0]) cout << x[i];
    rep(i,1,x[0]) cout << x[i];
    rep(i,1,y[0]) cout << y[i];
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
