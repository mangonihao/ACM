#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
typedef long long LL;
using namespace std;
const int maxn = 2e5;
LL n = 0,ans = -1;
int prime[20] = {0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
/*
本题的思路是：既然不能确定一个数x，然后再质因数分解x,求得x的约数个数，
因为x的枚举量太大，逆向思维，从已知结果出发枚举，搜索范围大大减少，
枚举素数的个数，然后检查是否满足一定条件
*/
void dfs(int depth,int lim,LL num,LL cnt){
	if(depth > 16){
		return ;
	}
	ans = max(ans,cnt);
	per(i,1,lim){
		if(num > n / prime[depth]){//不知道为什么num*prime[depth] > n,会80%正确
			break;
		}
		num *= prime[depth];
		dfs(depth+1,i,num,cnt * (i+1));//lim,剪枝，后面的素数的个数不会大于前面素数个数
	}
}
int main(){
	int T = 0;
	scanf("%d",&T);
	while(T--){
		ans = 1;
		scanf("%lld",&n);
		dfs(1,64,1,1);
		printf("%lld\n",ans);
	}


	return 0;
}