#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<string>
#include<cmath>

using namespace std;

typedef long long LL;

#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i = a;i <= b;++i)
#define rep(i,a,b) for(int i = a;i >= b;--i)
const int maxn = 3e5;
int n = 0,m = 0; 
void solve(){

}
int main(){
	//std::ios::sync_with_stdio(false);
	
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m);
		int ans = 0;
		if(m & 1){
			//ans = (m-1)*n + n-1-1;
			ans = m*n - 2;
		}else{
			//ans = (m-1)*n - 1 - 1  + 1;
			ans = (m-1)*n - 1;
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
  	
