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
const double eps = 1e-7;
int _,n,a[2*N],o[2*N],e;
ll ans;
int flag[2*N];

int primelist[2*N],isnotprime[2*N];

void getPrime(int x){
    int primenum;
    std::memset(primelist,0,sizeof(primelist));
    std::memset(isnotprime,0,sizeof(isnotprime));
    primenum = 0;
    isnotprime[0] = 1 , isnotprime[1] = 1;
    rep(i,2,x){
        if(!isnotprime[i]){
            primelist[++primenum] = i;
        }
        for(int j = 1;j <= primenum && i * primelist[j] <= x;++j){
            isnotprime[i * primelist[j]] = 1;
            if(!(i%primelist[j])) break;
        }
    }
    return;
}

bool isPrime(int x){
    // if(x == 1) return false;
    // if(x == 2) return true;
    // int tmp = std::sqrt(x);
    // rep(i,2,tmp){
    //     if(x % i == 0) return false;
    // }
    // return true;
    if(isnotprime[x]) return false;
    else return true;
}

ll cal(int x,int y){
    return ((long long)x+1) * ((long long)y+1) - 1;
}

ll solve(){
    ll ans = 0 , cntL = 0 , cntR = 0;
    int status = 0;
    rep(i,1,a[0]){
        if(isPrime(a[i])) flag[i] = 0; // prime
        else if(a[i] == 1) flag[i] = 1; // 1
        else flag[i] = -1; // other
    }

    // cout << "debug begin >>\n";
    // rep(i,1,a[0]) cout << flag[i] << " ";
    // cout << "\ndebug over <<<\n";

    rep(i,1,a[0]){
        if(flag[i] == -1){
            if(status == 0) continue;
            if(status == -1){
                status = 0;
                cntL = cntR = 0;
                continue;
            } 
            if(status == 1){
                status = 0;
                ans += (cntL + 1) * (cntR + 1) - 1;
                cntL = cntR = status = 0;
                continue;
            }
        } else if(flag[i] == 1){
            if(status == 0){
                status = -1;
                ++cntL;
                continue;
            }
            if(status == -1){
                ++cntL;
                continue;
            }
            if(status == 1){
                ++cntR;
                continue;
            }
        } else if(flag[i] == 0){
            if(status == 0){
                status = 1;
                cntL = cntR = 0;
                continue;
            } else if(status == -1){
                status = 1;
                cntR = 0;
                continue;
            } else if(status == 1){
                ans += (cntL + 1) * (cntR + 1) - 1;
                cntL = cntR;
                cntR = 0;
                continue;
            }
        }
    }
    if(status == 1){
        ans += (cntL + 1) * (cntR + 1) - 1;
    }
    return ans;
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    getPrime(1000005);
    cin >> _;
    while(_--){
        ans = 0;
        // scanf("%d %d",&n,&e);
        cin >> n >> e;
        // rep(i,1,n) scanf("%d",&o[i]);
        rep(i,1,n) cin >> o[i];
        rep(i,1,e){
            a[0] = 0;
            for(int j = i;j <= n;j += e){
                a[ ++a[0] ] = o[j];
            }
            ans += solve();
        }
        // printf("%lld\n",ans);
        cout << ans << "\n";
    }
    return 0;
}

