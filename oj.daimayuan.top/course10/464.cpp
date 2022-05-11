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
#define rep(i,a,b) for(register int i = (a);i <= (b);++i)
#define per(i,a,b) for(register int i = (a);i >= (b);--i)  
typedef long long ll;
typedef unsigned long long ull;
using std::string;using std::cin;using std::cout;

const int N = 2e5+10;
int n,m,a[2*N],b[2*N],p[2*N],tot,L,R,k;
std::map<int,int> mp;

struct node{
    int l,r,sum;
    node * ls, * rs;
}Tree[32*N],*root[2*N];

inline node * create(){return &Tree[++tot];}

inline bool cmp(int x,int y){return x < y;}

inline void build(node * cur,int l,int r){
    cur->l = l , cur->r = r , cur->sum = 0;
    if(l >= r) return;
    int mid = (l+r)>>1;
    cur->ls = create() , cur->rs = create();
    build(cur->ls,l,mid) , build(cur->rs,mid+1,r);
    return;
}

inline node * add(node * cur,int x){
    node * now = create();
    now->ls = cur->ls , now->l = cur->l , now->rs = cur->rs , now->r = cur->r , now->sum = cur->sum + 1;
    if(now->l == now->r) return now;
    if(now->l <= x && x <= now->ls->r) now->ls = add(cur->ls,x);
    if(now->rs->l <= x && x <= now->r) now->rs = add(cur->rs,x);
    return now;
}

inline int query(node * u,node * v,int k){
    if(v->l >= v->r) return v->l;
    int diff = v->ls->sum - u->ls->sum;
    if(k > diff) return query(u->rs,v->rs,k-diff);
    else return query(u->ls,v->ls,k);
}

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    cin >> n >> m;
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) b[i] = a[i];
    b[0] = std::unique(b+1,b+n+1) - b - 1; // 去重
    std::sort(b+1,b+b[0]+1,cmp);
    rep(i,1,b[0]) mp[ b[i] ] = i; // 建立映射关系
    rep(i,1,n) p[i] = mp[ a[i] ]; // 记忆化
    root[0] = create();
    build(root[0],1,b[0]);
    rep(i,1,n) root[i] = add(root[i-1],p[i]);
    while(m--){
        cin >> L >> R >> k;
        cout << b[query(root[L-1],root[R],k)] << "\n";
    }
    return 0;
}