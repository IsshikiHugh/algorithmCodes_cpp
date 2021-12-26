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
int _,n,lenA,lenS,b[2*N],a[2*N],s[2*N];
string A,S;

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    cin >> _;
    while(_--){
        cin >> A >> S;
        lenA = A.length() , lenS = S.length();
        rep(i,0,lenA-1) a[lenA-i] = A[i] - '0';
        rep(i,0,lenS-1) s[lenS-i] = S[i] - '0';
        rep(i,0,lenS+1) b[i] = 0; 
        int j = 1 , i = 1 , p;
        bool ans = true;
        while(1){
            p = i;
            if(j > lenS) break;
            if(i > lenA) a[i] = 0;
            if(s[j] >= a[i]){
                b[i] = s[j] - a[i];
                j += 1;
            } else{
                if(s[j+1] > 1 || s[j+1] < 1){
                    ans = false;
                    break;
                }
                b[i] = s[j] + s[j+1] * 10 - a[i];
                j += 2;
            }
            ++i;
        }
        if(!ans || i <= lenA){
            cout << "-1\n";
            continue;
        }
        bool leadZero = true;
        bool isZero = true;
        per(i,p,1){
            if(b[i]) leadZero = false;
            else if(leadZero) continue;
            cout << b[i];
            isZero = false;
        }
        if(isZero) cout << "-1";
        cout << "\n";

    }


    return 0;
}