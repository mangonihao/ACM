#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;

const int maxn = 100100;
typedef long long LL;
int A[maxn][21];
int n = 0;
int cnt[21];
LL f(int x){
	return 1ll*x*(x+1)/2;
}
int main(){
	int T = 0,temp = 0;
	scanf("%d",&T);
	//getchar();
	while(T--){
		LL ans = 0;
		scanf("%d",&n);
	//	getchar();
		for(int i = 0;i < n;++i){
			scanf("%d",&temp);
			for(int j = 0;j < 21;++j){//转化为二进制 
				A[i][j] = (temp >> j) & 1;
				//temp = temp >> 1;
			}
		}
		memset(cnt,0,sizeof(cnt));
		for(int j = 0;j < 21;++j){	//	相应位的计算 
			for(int i = 0;i < n;++i){
				if(A[i][j] == 1){
					++cnt[j];
				}else{
					ans += 1ll * f(cnt[j])* (1ll<< j);
					cnt[j] = 0;
				}
			}	
		}
		printf("%lld\n",ans);
	}
	
	
	
	
	return 0;
}
