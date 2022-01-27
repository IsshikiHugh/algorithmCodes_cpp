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
int a[2*N],ans[2*N],mex,emex[2*N],aa[2*N];
std::priority_queue<int> q;


void solve(){
    cin >> n;
    rep(i,1,n) cin >> a[i];
    rep(i,0,n+10) aa[i] = 0;
    rep(i,0,n+10) ans[i] = 0;
    rep(i,0,n+10) emex[i] = 0;
    while(!q.empty()) q.pop();
    per(i,n,1){
        aa[ a[i] ] = 1;
        if(emex[i+1] != a[i]) emex[i] = emex[i+1];
        else{
            int tmp = emex[i+1];
            for(tmp;tmp <= n;++tmp){
                if(aa[ tmp ]) continue;
                else break;
            }
            emex[i] = tmp;
        }
    }

    ans[0] = 0;
    int pre = 1;
    q.push(-a[pre]);
    mex = a[pre] == 0 ? 1 : 0;
    for(int i = pre;i <= n;++i){
        q.push( -a[i] );
        while(mex > -q.top() && !q.empty()) q.pop();
        while(mex >= -q.top() && !q.empty()){
            if(mex == -q.top()) ++mex; 
            q.pop();
        }

        if(mex == emex[pre]){
            ans[ ++ans[0] ] = mex;
            pre = i+1;
            mex = 0;
            while(!q.empty()) q.pop();
            continue;
        }

    }
    if(pre <= n) ans[ ++ans[0] ] = mex;
    cout << ans[0] << "\n";
    rep(i,1,ans[0]) cout << ans[i] << " ";
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
