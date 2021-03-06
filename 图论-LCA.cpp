#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (b);i >= (b);--i)
using namespace std;
const int maxn = 2e5 + 10;
vector<int> g[maxn+10],query[maxn+10];
map<pair<int,int>,int> cf;
int n = 0,q = 0;
bool vis[maxn];
int fa[maxn],rak[maxn],in[maxn];
vector<pair<int,int> > p;
void init(){
	memset(vis,false,sizeof(vis));
	memset(rak,0,sizeof(rak));
	memset(in,0,sizeof(in));
	per(i,1,n){
		fa[i] = i;
	}
	cf.clear();p.clear();
	per(i,1,n){
		g[i].clear();
		query[i].clear();
	}
}
int find(int x){
	if(fa[x] == x){
		return x;
	}else{
		return fa[x] = find(fa[x]);
	}
}
void unite(int x,int y){//建树
	x = find(x); y = find(y);
	if(x == y){
		return ;
	}else{
		if(rak[x] == rak[y]){
			++rak[x];
		}
		fa[y] = x;
	}
}
/*
伪代码：
Tarjan(u)//marge和find为并查集合并函数和查找函数
{
    for each(u,v)    //访问所有u子节点v
    {
        Tarjan(v);        //继续往下遍历
        marge(u,v);    //合并v到u上
        标记v被访问过;
    }
    for each(u,e)    //访问所有和u有询问关系的e
    {
        如果e被访问过;
        u,e的最近公共祖先为find(e);
    }
}
*/

void Tarjan(int u){
	int si = g[u].size();
	per(i,0,si-1){
		int v = g[u][i];
		Tarjan(v);
		unite(u,v);//
		vis[v] = true;
	}
	int size = query[u].size();
	per(i,0,size-1){
		int v = query[u][i];
		if(vis[v]){
			cf[make_pair(u,v)] = cf[make_pair(v,u)] = find(v);
		}
	}
}

int main(){
	while(~scanf("%d",&n)){
		init();
		per(i,1,n-1){
			int x = 0,y = 0;
			scanf("%d %d",&x,&y);
			g[x].push_back(y);
			++in[y];
		}
		scanf("%d",&q);
		per(i,1,q){
			int x = 0,y = 0;
			scanf("%d %d",&x,&y);
			query[x].push_back(y); query[y].push_back(x);
			p.push_back(make_pair(x,y));
		}
		per(i,1,n){
			if(in[i] == 0){
				//printf("jiji %d\n",i);
				Tarjan(i);
			}
		}
		int size = p.size();
		printf("%d\n",size);
		per(i,0,size-1){
			printf("%d\n",cf[p[i]]);
		}
		
	}


	return 0;
}

/*
9
1 2
1 3
2 4
2 5
5 7
5 8
7 9
3 6
4
9 8
4 6
2 7
5 3

*/