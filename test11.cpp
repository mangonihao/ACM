#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 50000 + 500;
typedef long long LL;

LL gcd(LL a,LL b)
{
    return (b==0)?a:gcd(b,a%b);
}

int pos[maxn];
int col[maxn];
int f[maxn];
int n,m;

struct Query
{
    int l,r,id;
    LL a,b;
    friend bool operator < (const Query &R,const Query &T)
    {
        return pos[R.l]<pos[T.l] || (pos[R.l]==pos[T.l] && R.r<T.r);
    }
    void modify()
    {
        LL k=gcd(a,b);
        a/=k,b/=k;
    }
}Q[maxn];
bool cmp_id(const Query &a,const Query &b)
{
    return a.id<b.id;
}

void init()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%d",&col[i]);
    int limit=(int)sqrt((double)n+0.5);
    for(int i=1;i<=n;++i)
        pos[i]=(i-1)/limit+1;//左端点分块
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d",&Q[i].l,&Q[i].r);
        Q[i].id=i;
    }
    sort(Q+1,Q+m+1);
}

void modify(int p,LL &ans,int add)
{
    if(add == 1){//当区间扩大时
         ans=ans+2*add*f[col[p]];
    }else{//当区间缩小时
        ans = ans + 2*add*f[col[p]] + 2;
    }
    f[col[p]]+=add;
}

void solve()
{
    LL ans=0;
    int l=1,r=0;
    for(int i=1;i<=m;++i)
    {
        if(r<Q[i].r)
        {
            for(r=r+1;r<Q[i].r;++r)
                modify(r,ans,1);
            modify(r,ans,1);
        }
        if(Q[i].l<l)
        {
            for(l=l-1;Q[i].l<l;--l)
                modify(l,ans,1);
            modify(l,ans,1);
        }
        if(Q[i].r<r)
            for(;Q[i].r<r;--r)
                modify(r,ans,-1);
        if(l<Q[i].l)
            for(;l<Q[i].l;++l)
                modify(l,ans,-1);
        if(Q[i].l==Q[i].r)
        {
            Q[i].a=0,Q[i].b=1;
            continue;
        }
        Q[i].a=ans,Q[i].b=(LL)(Q[i].r-Q[i].l+1)*(Q[i].r-Q[i].l);
        Q[i].modify();
    }
    sort(Q+1,Q+m+1,cmp_id);
    for(int i=1;i<=m;++i)
        printf("%lld/%lld\n",Q[i].a,Q[i].b);
}

int main()
{
    init();
    solve();

    return 0;
}