#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<vector>
#include<bitset>
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
using std::vector;
inline bool cmp(int x,int y){return x < y;}
/* -fsanitize=undefined  */
const int N = 1e6+9;
const int inf = 1e9+9;
const double eps = 1e-7;
int _,n,u,v,dep[N],ans[N];
bool vis[30];
vector<int> e[N],odd,even,st[30];

void init(){
    rep(i,0,n) e[i].clear();
    rep(i,0,n) dep[i] = 0;
    ans[1] = 1; 
    rep(i,0,20) vis[i] = false;
    odd.clear() , even.clear();

    rep(i,0,20) st[i].clear();
    rep(i,1,n){
        per(j,20,0){
            if(i & (1<<j)){
                st[j].push_back(i);
                break;
            }
        }
    }
}

void dfs(int fa,int now){
    dep[now] = dep[fa] + 1;
    if(dep[now] % 2 == 1) odd.push_back(now);
    else even.push_back(now);
    // std::cerr << "dfs : dep[" << now << "] = " << dep[now] <<"\n";
    // std::cerr << "so :\n";
    // std::cerr << "odd.size() = " << odd.size() << "\n";
    // std::cerr << "even.size() = " << even.size() << "\n";
    
    rep(i,0,(int)e[now].size()-1){
        // std::cerr << "e[" << now << "]["<<i<<"] = " << e[now][i] << "\n";
        if(e[now][i] == fa) continue;
        dfs(now,e[now][i]);
    }
    return;
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    cin >> _;
    while(_--){
        cin >> n;
        init();
        rep(i,1,n-1){
            cin >> u >> v;
            e[u].push_back(v) , e[v].push_back(u);
        }
        dfs(0,1);
        if((int)odd.size() > (int)even.size()){
            int len = (int)even.size(),p = 0;
            rep(i,0,20){
                if(((1<<i) & len) && ((1<<(i+1))-1 <= n)){
                    vis[i] = true;
                    rep(j,0,(int)st[i].size()-1){
                        ans[ even[p++] ] = st[i][j];
                    }
                }
            }
            p = 0;
            rep(i,0,20){
                if(vis[i]) continue;
                if((1<<i) > n) break;
                rep(j,0,(int)st[i].size()-1){
                    if(st[i][j] > n) break;
                    ans[ odd[p++] ] = st[i][j];
                }
            }
        } else {
            int len = (int)odd.size(),p = 0;
            rep(i,0,20){
                if(((1<<i) & len) && ((1<<(i+1))-1 <= n)){
                    vis[i] = true;
                    rep(j,0,(int)st[i].size()-1){
                        ans[ odd[p++] ] = st[i][j];
                    }
                }
            }
            p = 0;
            rep(i,0,20){
                if(vis[i]) continue;
                if((1<<i) > n) break;
                rep(j,0,(int)st[i].size()-1){
                    if(st[i][j] > n) break;
                    ans[ even[p++] ] = st[i][j];
                }
            }
        }
        rep(i,1,n) cout << ans[i] << " ";
        cout << "\n";
    }



    return 0;
}

