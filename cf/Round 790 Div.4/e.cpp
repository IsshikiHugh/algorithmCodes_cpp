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
inline bool cmp(int x,int y){return x > y;}
/* -fsanitize=undefined  */
const int N = 2e5+9;
const int inf = 0x3F3F3F3F;
const double eps = 1e-7;
const int MD = 20;

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> v(n+1);
    rep(i,1,n) cin >> v[i];
    v[0] = v.size()-1;
    sort(v.begin()+1, v.end(), cmp);
    vector<int> sum(n+1);
    rep(i,1,n) sum[i] = sum[i-1] + v[i];
    while(q--){
        int x;
        cin >> x;
        if(x > sum[n]){
            cout << "-1\n";
        } else {
            auto it = std::lower_bound(sum.begin()+1, sum.end(), x);
            cout << it-sum.begin() << "\n";
        }
    }
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
