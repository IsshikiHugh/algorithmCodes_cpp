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

void solve(){
    string str;
    cin >> str;
    int n = str.length();
    rep(i,1,n) a[i] = str[i-1] - '0';
    bool flag = false;
    per(i,n,2){
        if(a[i] + a[i-1] >= 10){
            a[i] = a[i] + a[i-1] - 10;
            a[i-1] = 1; 
            flag = true;
            break;
        } 
    }
    if(flag){
        rep(i,1,n) cout << a[i];
        cout << "\n";
    } else {
        a[2] = a[1] + a[2];
        rep(i,2,n) cout << a[i];
        cout << "\n";
    }

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
