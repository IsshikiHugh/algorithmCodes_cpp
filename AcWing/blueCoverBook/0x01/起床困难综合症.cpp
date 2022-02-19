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

vector< pair<string,int> > a;


int cal(int p,int x){
    int ret = x;
    for(auto it = a.begin();it != a.end();++it){
        int tmp = (*it).second >> p;
        tmp &= 1;
        if((*it).first == "AND"){
            ret &= tmp;
        } else if((*it).first == "OR"){
            ret |= tmp;
        } else if((*it).first == "XOR"){
            ret ^= tmp;
        }
    }
    return ret<<p;
}

void solve(){
    int n, m, ori = 0, ans = 0;
    cin >> n >> m;
    rep(i,1,n){
        string opt;
        int x;
        cin >> opt >> x;
        a.push_back( mkp(opt,x) );
    }
    per(i,29,0){
        int res0 = cal(i,0), res1 = cal(i,1);
        if(res1 > res0 && (ori + (1<<i)) <= m){
            ori += (1<<i), ans += res1;
        } else {
            ans += res0;
        }
    }
    cout << ans <<"\n";
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    int _ = 1;
    // cin >> _;
    while(_--) solve();
    return 0;
}
