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
const int N = 1e5+9;
const int inf = 1e9+9;
const double eps = 1e-7;
int _,n,x,cnt;
ll y;
ll a[2*N];

void solve(){
    cnt = 0;
    cin >> n >> x >> y;
    rep(i,1,n){
        cin >> a[i];
        if(a[i]&1) ++cnt;
    }
    // std::cerr << cnt << "]]\n";
    if(y&1){
        if(cnt&1){
            if(x&1){
                cout << "Bob\n";
            } else {
                cout << "Alice\n";
            }
        } else {
            if(x&1){
                cout << "Alice\n";
            } else {
                cout << "Bob\n";
            }
        }
    } else {
        if(cnt&1){
            if(x&1){
                cout << "Alice\n";
            } else {
                cout << "Bob\n";
            }
        } else {
            if(x&1){
                cout << "Bob\n";
            } else {
                cout << "Alice\n";
            }
        }
    }

}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    _ = 1;
    cin >> _;
    while(_--) solve();
    return 0;
}
