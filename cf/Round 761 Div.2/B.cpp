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
int _,n,a,b,c,tmp;


int primelist[2*N],isnotprime[2*N],tot;

// 线性筛，其实没必要
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
    tot = primenum;
    return;
}


int find(int x){
    rep(i,1,tot){
        if(primelist[i] > x) return 0;;
        if(x % primelist[i] == 0) return primelist[i];
    }
    return 0;
}

int solve(int x){
    rep(i,1,tot){
        if(primelist[i] > x) return 0;
        if(x % primelist[i] != 0) return primelist[i];
    }
    return 0;
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    getPrime(1000005);
    cin >> _;
    while(_--){
        cin >> n;
        if(n % 2 == 0){
            a = n-3 , b = 2 , c = 1;
        } else {
            c = 1 , --n;
            a = solve(n);
            b = n - a;
        }
        cout << a << " " << b << " " << c << "\n";
    }


    return 0;
}

