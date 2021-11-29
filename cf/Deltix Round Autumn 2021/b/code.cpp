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
const int N = 1e5+9;
const int inf = 1e9+9;
const double eps = 1e-7;
int _,n,p,ans;
char t,ch[2*N];

int cal(){
    int ans = 0;
    rep(i,1,n-2){
        if(ch[i] == 'a' && ch[i+1] == 'b' && ch[i+2] == 'c'){
            ++ans;
            i += 2;
        }
    }
    return ans;
}

bool judge(){
    if(1 <= (p+0) && (p+2) <= n){
        if(ch[p] == 'a' && ch[p+1] == 'b' && ch[p+2] == 'c') return true;
    }
    if(1 <= (p-1) && (p+1) <= n){
        if(ch[p-1] == 'a' && ch[p] == 'b' && ch[p+1] == 'c') return true;
    }
    if(1 <= (p-2) && (p+0) <= n){
        if(ch[p-2] == 'a' && ch[p-1] == 'b' && ch[p] == 'c') return true;
    }
    return false;
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    cin >> n >> _;
    rep(i,1,n) cin >> ch[i];

    ans = cal();
    while(_--){
        cin >> p >> t;
        if(judge()) --ans;
        ch[p] = t;
        if(judge()) ++ans;
        cout << ans << "\n";
    }

    return 0;
}

