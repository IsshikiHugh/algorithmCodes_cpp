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
/* -fsanitize=undefined  */
const int N = 2e5+9;
const int inf = 0x3F3F3F3F;
const double eps = 1e-7;
const int MD = 20;

struct Opt1{
    Opt1(int i,int x,int y) : time(i), pos(x), to(y) {}
    int time, pos, to;
};

inline bool cmp(Opt1 x,Opt1 y){return x.time < y.time;}


int n;
vector<int> a, maxLim;
vector< Opt1 > opt1List;

void solve(){
    int _;
    cin >> n >> _;
    a.resize(n+1), maxLim.resize(_+1);
    a.clear(), maxLim.clear();
    rep(i,1,n) cin >> a[i];
    rep(i,1,_){
        int opt, x, y;
        cin >> opt;
        if(opt == 1){
            cin >> x >> y;
            opt1List.push_back( Opt1(i,x,y) );
        } else {
            cin >> y;
            maxLim[i] = y;
        }
    }
    per(i,_-1,1) maxLim[i] = max(maxLim[i], maxLim[i+1]);
    rep(i,1,n) a[i] = max(a[i], maxLim[1]);
    sort(opt1List.begin(),opt1List.end(),cmp);
    for(auto it = opt1List.begin();it != opt1List.end();++it){
        Opt1 &opt = *it;
        a[opt.pos] = max(opt.to, maxLim[opt.time]);
    }
    rep(i,1,n) cout << a[i] << " ";
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
