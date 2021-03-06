#include<bits/stdc++.h>
using namespace std;
const int maxn = 300;
int dp[18][maxn + 5];//dp[i][j]表示使用前i种货币，凑出j元的方法数 
int n = 0;
void solve(){
	fill(dp[0],dp[0]+18*(maxn+5),0);
	for(int i = 0;i <= maxn;++i){
		dp[1][i] = 1;
	}
	for(int i = 1;i <= 17;++i){//要初始化为1 
		dp[i][0] = 1;
	}
	for(int i = 2;i <= 17;++i){
		for(int j = 1;j <= maxn;++j){
			dp[i][j] = dp[i-1][j] + (j >= i*i? dp[i][j-i*i]:0);//i,j状态由只是用前i-1种货币 
			//凑成j元的方法数+使用前i种货币j-i元（在加上i元货币）的方法数 
		}
	}
	/*
	for(int i = 1;i <= 4;++i){
		for(int j = 0;j <= 4;++j){
			printf("%d%c",dp[i][j],(j == 10)?'\n':' ');
		}
	}
	*/
}
int main(){
	solve();
	while(~scanf("%d",&n) && n != 0){
		printf("%d\n",dp[17][n]);
	}
	return 0;
}
