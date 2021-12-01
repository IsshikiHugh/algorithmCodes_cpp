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
const int N = 1e7+9;
const int inf = 1e9+9;
const double eps = 1e-7;
int _,n,a[2*N],x1,x2,l1,l2,p1,p2,zero[20];

int len(int x){
    int ans = 0;
    while(x){
        ++ans;
        x /= 10;
    }
    return ans;
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    zero[0] = 1;
    rep(i,1,10) zero[i] = zero[i-1] * 10;
    cin >> _;
    while(_--){
        cin >> x1 >> p1 >> x2 >> p2;
        l1 = len(x1) + p1 , l2 = len(x2) + p2;
        if(l1 < l2) cout << "<\n";
        else if(l1 > l2) cout << ">\n";
        else{
            l1 -= p1 , l2 -= p2;
            if(l1 < l2){
                x1 *= zero[l2-l1];
            } else {
                x2 *= zero[l1-l2];
            }
            if(x1 < x2) cout << "<\n";
            else if(x1 > x2) cout <<">\n";
            else cout << "=\n";
        }
    }    

    return 0;
}

