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
int _,n,m,c,r;
int a[2*N];

void solve(){
    bool flag = false , ok = false;
    int cnt = 0;
    cin >> n >> m >> r >> c;
    rep(i,1,n){
        rep(j,1,m){
            char ch;
            cin >> ch;
            if(ch == 'B'){
                ++cnt;
                if(i == r || j == c) flag = true;
                if(i == r && j == c) ok = true;
                
            }
        }
    }
    if(cnt == 0) cout << "-1\n";
    else if(ok) cout << "0\n";
    else if(flag) cout << "1\n";
    else cout << "2\n";



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
