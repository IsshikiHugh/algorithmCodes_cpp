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

inline int cal(int x, int y, vector< vector<int> > mp,int n, int m){
    int ret = 0;
    rep(i,1,n){
        if(x+i < n && y+i < m){
            ret += mp[x+i][y+i];
        }
        if(x-i >= 0 && y-i >= 0){
            ret += mp[x-i][y-i];
        }
        if(x-i >= 0 && y+i < m){
            ret += mp[x-i][y+i];
        }
        if(x+i < n && y-i >= 0){
            ret += mp[x+i][y-i];
        }
    }
    return ret + mp[x][y];
}

void solve(){
    vector< vector<int> > mp;
    mp.clear();
    int n, m, ans = -inf;
    cin >> n >> m;
    rep(i,1,n){
        vector<int> line;
        rep(j,1,m){
            int x;
            cin >> x;
            line.push_back(x);
        }
        mp.push_back(line);
    }
    rep(i,1,n){
        rep(j,1,m){
            int tmp = cal(i-1, j-1, mp, n, m);
            ans = ans > tmp ? ans : tmp;
        }
    }
    cout << ans << "\n";
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
