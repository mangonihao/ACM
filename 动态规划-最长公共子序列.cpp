#include<bits/stdc++.h>
using namespace std;
#define per(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,a,b) for(int i=(a);i>=(b);i--)
typedef long long LL;
const int maxn = 1e2;
string s1,s2;
int dp[maxn+10][maxn+10];
void solve(){
	int size1 = s1.size(),size2 = s2.size();
	memset(dp,0,sizeof(dp));
	/* 
	dp[0][0] = s1[0] == s2[0] ? 1 : 0;
	per(i,1,size1-1){
		dp[i][0] = max(dp[i-1][0],s1[i] == s2[0] ? 1 : 0);
	}
	per(j,1,size2-1){
		dp[0][j] = max(dp[0][j-1],s1[0] == s2[j] ? 1 : 0);
	}
	*/
	//初始化没必要，下面从1-size1，然后s1[i-1] == s2[j-1]即可 
	per(i,1,size1-1){
		per(j,1,size2-1){
			dp[i][j] = 
			(s1[i-1] == s2[j-1] ? max(dp[i-1][j-1] + 1,max(dp[i-1][j],dp[i][j-1])) : max(dp[i-1][j],dp[i][j-1]));
		}
	}
	printf("%d\n",dp[size1][size2]);
}
int main(){
	while(cin >> s1 >> s2){
		solve();
	}
	
	
	return 0;
}
