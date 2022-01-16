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
const int N = 1e6+9;
const ll inf = 1e18+9;
const double eps = 1e-7;
int _,n,m,k,id;
int a[2*N],cost[2*N],heal[2*N];
ll dp[200050];

inline bool cmp(pair<int,int> x,pair<int,int> y){return x.first < y.first;}

void solve(){
    cin >> n >> m >> k;

    vector< vector< pair<int,int> > > v(2*k+10);
    v.clear();

    id = -1;
    rep(i,1,n) cin >> cost[i];

    rep(i,2,k+1){
        int ux,uy,vx,vy,hh;
        cin >> ux >> uy >> vx >> vy >> hh;
        v[ux].push_back( mkp(uy,2*i) );
        v[vx].push_back( mkp(vy,2*i+1) );
        heal[i] = hh;
        dp[2*i] = dp[2*i+1] = inf; 
    }
    dp[3] = 0 , dp[2*k+4] = inf;
    v[1].push_back( mkp(1,3) );
    v[n].push_back( mkp(m,2*k+4) );


    rep(i,1,n){
        sort(v[i].begin(),v[i].end(),cmp);

        /**********************************************************/        
        {
            vector< pair<int,int> >::iterator it;
            for(it = v[i].begin();it != v[i].end();++it){
                if(it == v[i].begin()) continue;
                dp[ it->second ] = min( 
                    dp[ it->second ] ,
                    dp[ (it-1)->second ] + (ll)cost[i]*( it->first - (it-1)->first )
                );
            }
        }

        /**********************************************************/
        {
            vector< pair<int,int> >::reverse_iterator it;
            for(it = v[i].rbegin();it != v[i].rend();++it){
                if(it == v[i].rbegin()) continue;
                dp[ it->second ] = min( 
                    dp[ it->second ] ,
                    dp[ (it-1)->second ] + (ll)cost[i]*( (it-1)->first - it->first )
                );
            }
        }

        /**********************************************************/
        vector< pair<int,int> >::iterator it;
        for(it = v[i].begin();it < v[i].end();++it){
            if(it->second == 2*k+4){
                if(dp[2*k+4] == inf) cout << "NO ESCAPE\n";
                else cout << dp[2*k+4] << "\n";
                return;
            }
            // cout << "now " <<i << " " << it->second << " \n";
            if(it->second % 2 == 0 && dp[ it->second ] != inf){
                dp[ (it->second)+1 ] = dp[ it->second ] - heal[ it->second/2 ];
            }
            // cout << dp[ it->second ] << " " << heal[ it->second/2 ] << "\n";
        }
    }
    if(dp[2*k+4] == inf) cout << "NO ESCAPE\n";
    else cout << dp[2*k+4] << "\n";
    return;
}

int main(){
    // std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    // _ = 1;
    cin >> _;
    while(_--) solve();
    return 0;
}
