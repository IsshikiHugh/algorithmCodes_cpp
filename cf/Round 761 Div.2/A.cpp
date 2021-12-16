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
inline bool cmp(char x,char y){return x < y;}
/* -fsanitize=undefined  */
const int N = 1e6+9;
const int inf = 1e9+9;
const double eps = 1e-7;
int _,n,a[2*N];
string s,t;
char ch[2*N];

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    cin >> _;

    while(_--){
        bool fa = false,fb = false,fc = false,flag = false;;
        cin >> s >> t;
        int len = s.length();
        rep(i,0,len-1){
            if(s[i] == 'a') fa = true;
            if(s[i] == 'b') fb = true;
            if(s[i] == 'c') fc = true;
        }
        if((!fa) || (!fb) || (!fc)) flag = true;

        rep(i,0,len-1) ch[i+1] = s[i];
        if(flag){
            std::sort(ch+1,ch+len+1,cmp);
            ch[len+1] = 0;
            cout << ch+1 << "\n";            
        } else {
            if(t == "abc"){
                rep(i,1,len){
                    if(ch[i] == 'b') ch[i] = 'c';
                    else if(ch[i] == 'c') ch[i] = 'b';
                }
                std::sort(ch+1,ch+len+1,cmp);
                rep(i,1,len){
                    if(ch[i] == 'b') cout << 'c';
                    else if(ch[i] == 'c') cout << 'b';
                    else cout << ch[i];
                }
                cout << "\n";
            } else {
                std::sort(ch+1,ch+len+1,cmp);
                ch[len+1] = 0;
                cout << ch+1 << "\n";  
            }
        }

    }


    return 0;
}

