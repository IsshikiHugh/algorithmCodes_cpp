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
using std::set;using std::pair;using std::map;using std::sort;
inline ll max(ll x,ll y){return x > y ? x : y;}
inline ll min(ll x,ll y){return x < y ? x : y;}
inline bool cmp(int x,int y){return x < y;}
/* -fsanitize=undefined  */
const int N = 1e6+9;
const int inf = 1e9+9;
const double eps = 1e-7;
int _,n,O,cnt,ans,as[2*N];
int a[2*N] , flag;
string str , opt , v , l , r , vv[2*N];

inline int extract(string s){
    int p = 4 , res = 0;
    while(s[p] != ')'){
        res = res * 10 + s[p]-'0';
        ++p;
    }
    return res;
}

inline int val(string s){
    int res = 0,len = s.length();
    rep(i,0,len-1) res = res*10 + s[i]-'0';
    return res;
}

void solve(){
    set<string> st;
    st.clear();
    cin >> n >> str;
    if(str == "O(1)") O = 0;
    else O = extract(str);

    as[0] = 0;
    ans = cnt = 0;
    flag = inf;
    
    rep(i,1,n){
        cin >> opt;
        if(opt == "F"){
            cin >> v >> l >> r;
            if(ans == -1) continue;
            ++cnt;
            if(st.find(v) != st.end()){
                ans = -1;
                continue;
            } else {
                st.insert(v);
                vv[cnt] = v;
            }

            if(flag > cnt){
                if(l == "n" && r != "n") flag = cnt;
                else if(l == "n" && r == "n") as[cnt] = as[cnt-1];
                else if(l != "n" && r == "n") as[cnt] = as[cnt-1]+1 , ans = max(ans , as[cnt]);
                else if(l != "n" && r != "n"){
                    if(val(l) <= val(r)){
                        as[cnt] = as[cnt-1];
                    } else {
                        as[cnt] = -inf;
                    }
                }
            }
        } else {
            if(ans == -1) continue;
            st.erase(vv[cnt]);
            --cnt;
            if(flag > cnt) flag = inf;
            if(cnt < 0){
                ans = -1;
                continue;
            }
        }
    }
    if(cnt != 0) ans = -1;
    if(ans == -1) cout << "ERR\n";
    else if(ans == O) cout << "Yes\n";
    else cout << "No\n";

}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef LOCAL //  -DLOCAL
        freopen("in.in", "r", stdin);
    #endif
    cin >> _;
    while(_--) solve();
    return 0;
}
