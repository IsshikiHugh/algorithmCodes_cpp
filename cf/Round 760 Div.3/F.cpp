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
using std::string;using std::cin;using std::cout;
inline bool cmp(int x,int y){return x < y;}
/* -fsanitize=undefined  */
const int N = 1e6+9;
const int inf = 1e9+9;
const long long llmax = 1e18+9;
const double eps = 1e-7;
int _,n;
ll x,y;

std::set<ll> st;

ll r(ll x){
    ll tmp = 0;
    while(x){
        tmp <<= 1;
        tmp += x%2;
        x >>= 1;
    }
    return tmp;
}

void dfs(ll t){
    if(st.find(t) != st.end()) return;
    if(t >= llmax) return;
    st.insert(t);
    dfs(r(t*2)) , dfs(r(t*2+1));
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    cin >> x >> y; 
    dfs(x);
    if(st.find(y) != st.end()) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}

