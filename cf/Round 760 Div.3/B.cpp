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
int _,n;
string ch[2*N];


int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    cin >> _;
    while(_--){
        bool flag = false;
        cin >> n;
        rep(i,1,n-2){
            cin >> ch[i];
        }
        cout << ch[1][0];
        rep(i,2,n-2){
            if(ch[i-1][1] == ch[i][0]) cout << ch[i][0];
            else {
                flag = true;
                cout << ch[i-1][1] << ch[i][0];
            }
        }
        cout << ch[n-2][1];
        if(!flag) cout << "a\n";
        else cout << "\n";
    }


    return 0;
}
 