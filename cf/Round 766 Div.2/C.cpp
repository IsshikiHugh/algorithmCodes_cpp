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
int _,n;
bool ans;
int a[2*N],status[2*N];

int head[2*N],next[2*N],ver[2*N],color[2*N],tot;
inline void link(int x,int y){ver[++tot] = y, next[tot] = head[x], head[x] = tot , color[tot] = -1;}

queue<int> q;

void dfs(int now,int father,int Color){
    int di = 0;
    if(!ans) return;
    for(int i = head[now];i;i = next[i]){
        if(ver[i] == father) continue;
        ++di;
        if(di > 1){
            ans = false;
            return;
        }
        color[ i ] = !Color;
        dfs(ver[i],now,color[i]);
    }
}

void init(){
    rep(i,0,tot) head[i] = next[i] = ver[i] = color[i] = 0;
    tot = 0;
}



void solve(){
    while(!q.empty()) q.pop();
    ans = true;
    cin >> n;
    
    init();

    rep(i,1,n-1){
        int u,v;
        cin >> u >> v;
        link(u,v), link(v,u);
    }

    int di = 0;
    for(int i = head[1];i;i = next[i]){
        ++di;
        if(di > 2){
            ans = false;
            break;
        }
        color[i] = di-1;
        dfs( ver[i] , 1 , color[i] );
    }


    if(!ans){
        cout << "-1\n";
        return;
    }
    rep(i,1,n-1){
        if(color[2*i]*color[2*i-1] == -1) cout << "11 "; 
        if(color[2*i]*color[2*i-1] == 0) cout << "2 "; 
    }
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
