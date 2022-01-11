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
int _,n,a,b,c;


int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    cin >> _;
    while(_--){
        cin >> a >> b >> c;
        int k;
        bool flag = false;
        k = c - b;
        if((b - k) % a == 0 && (b - k) > 0) flag = true;
        // cout << flag << "\n";
        k = b - a;
        if((b + k) % c == 0 && (b + k) > 0) flag = true;
        // cout << flag << "\n";
        k = (c - a);
        if(k % 2 == 0){
            if((a+c)/2 % b == 0) flag = true;
        }
        // cout << flag << "\n";
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }


    return 0;
}

