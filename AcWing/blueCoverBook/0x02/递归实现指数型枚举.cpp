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

set<int> st;

int n;

void func(int x){
    if(x == n+1){
        for(auto it = st.begin();it != st.end();++it){
            cout << (*it) << " ";
        }
        cout << "\n";
        return;
    }
    func(x+1);
    st.insert(x);
    func(x+1);
    auto it = st.find(x);
    st.erase(it);
}

void solve(){
    st.clear();
    cin >> n;
    func(1);
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
