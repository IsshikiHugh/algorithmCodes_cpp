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
int _,n,a2[2*N],l2,a3[2*N],l3;
std::set<int> s3,s2;

void init(){
    rep(i,1,inf){
        if(i * i >= inf) break;
        a2[++l2] = i*i;
        s2.insert(i*i);
    }
    rep(i,1,inf){
        if(i * i * i >= inf) break;
        a3[++l3] = i*i*i;
        // s3.insert(i*i*i);
    }
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    cin >> _;
    init();
    while(_--){
        cin >> n;
        int cnt = 0;
        rep(i,1,l3){
            if(a3[i] <= n) ++cnt;
            // if(a3[i] <= n) cout << a3[i] << "\n";
            if(a3[i] <= n && s2.find( a3[i] ) != s2.end()) --cnt;
        }
        rep(i,1,l2){
            if(a2[i] <= n) ++cnt;
            // if(a2[i] <= n) cout << a2[i] << "\n";
        }
        cout << cnt << "\n";
    }


    return 0;
}

