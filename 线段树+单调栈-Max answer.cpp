#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 0x3f3f3f
using namespace std; 
typedef long long LL;
const int maxn = 5e5;
int n = 0,m = 0;
LL a[maxn+10];
LL pre[maxn+10],suf[maxn+10],sum = 0;
int L[maxn+10],R[maxn+10];
struct node{
	LL ma,mi;
	int l,r;
};
node tree[2][4*maxn+10];//0???????ߵģ?1?????ұߵ? 
void build_tree(int l,int r,int root){
	tree[0][root].l = l,tree[0][root].r = r;
	tree[1][root].l = l,tree[1][root].r = r;
	
	if(l == r){
		tree[0][root].mi = tree[0][root].ma = sum - pre[l-1];
		tree[1][root].mi = tree[1][root].ma = sum - suf[l+1];
	}else{
		int mid = (l + r) >> 1;
		build_tree(l,mid,root<<1);
		build_tree(mid+1,r,root<<1|1);
		tree[0][root].mi = min(tree[0][root<<1].mi,tree[0][root<<1|1].mi);
		tree[0][root].ma = max(tree[0][root<<1].ma,tree[0][root<<1|1].ma);
		
		tree[1][root].mi = min(tree[1][root<<1].mi,tree[1][root<<1|1].mi);
		tree[1][root].ma = max(tree[1][root<<1].ma,tree[1][root<<1|1].ma);
	}
	return ;
}
LL query_max(int l,int r,int root,int id){
	if(tree[id][root].l > r || tree[id][root].r < l){
		return -1e18;
	}else if(l <= tree[id][root].l && r >= tree[id][root].r){
		return tree[id][root].ma;
	}else{
		return max(query_max(l,r,root<<1,id),query_max(l,r,root<<1|1,id));
	}
}
LL query_min(int l,int r,int root,int id){
	//if(l > r){
	//	return 0;
	//}
	if(tree[id][root].l > r || tree[id][root].r < l){
		return 1e18;
	}else if(l <= tree[id][root].l && r >= tree[id][root].r){
		return tree[id][root].mi;
	}else{
		return min(query_min(l,r,root<<1,id),query_min(l,r,root<<1|1,id));
	}
}

void Mo_stack(){
	stack<int> st;
	per(i,1,n){
		while(!st.empty() && a[i] <= a[st.top()]){
			st.pop();
		}
		if(st.empty()){
			L[i] = 0;
		}else{
			L[i] = st.top();
		}
		st.push(i);
	}
	
	while(!st.empty()){
		st.pop();
	}
	
	rep(i,n,1){
		while(!st.empty() && a[i] <= a[st.top()]){
			st.pop();
		}
		if(st.empty()){
			R[i] = n+1;
		}else{
			R[i] = st.top();
		}
		st.push(i);
	}
}
void init(){
	memset(pre,0,sizeof(pre)); memset(suf,0,sizeof(suf));
	sum = 0;	
	per(i,0,1){
		per(j,0,5e5*4){
			tree[i][j].mi = 1e18;	tree[i][j].ma = -1e18;
		}
	}	
}
int main(){
	while(~scanf("%d",&n)){
		init();
		per(i,1,n){
			scanf("%lld",&a[i]);
			pre[i] = pre[i-1] + a[i];
			sum += a[i];
		}
		rep(i,n,1){
			suf[i] = suf[i+1] + a[i];
		}
		Mo_stack();
		build_tree(1,n,1);
		LL maxv = -1e18;
		per(i,1,n){
			if(a[i] > 0){
				//LL lm = max(query_max(L[i]+1,i-1,1,0),1ll*0),rm = max(query_max(i+1,R[i]-1,1,1),1ll*0);
				//maxv = max(maxv,1ll*a[i]*(lm+a[i]+rm));
				maxv = max(maxv,1ll*a[i]*(pre[R[i]-1] - pre[L[i]]));//??СֵΪ??????????????ȫ>0,?????????ڵ???ȫҪ 
			
			}else if(a[i] < 0){
				//????-suf[i],?ұ?-pre[i]?? 
				LL lm = min(query_min(L[i]+1,i-1,1,0) - suf[i],1ll*0),rm = min(query_min(i+1,R[i]-1,1,1) - pre[i],1ll*0);
				maxv = max(maxv,1ll*a[i]*(lm+a[i]+rm));
			}else{
				maxv = max(maxv,1ll*0);
			}
		}
		printf("%lld\n",maxv);
	}
	
	return 0;
}
/*
4
-1 -1 -1 -1
4
-3 1 -2 1
*/
