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
int a[maxn+10],b[maxn+10];
int cnt = 0,cnt0 = 0,cnt1 = 0,cnt2 = 0;

int main(){
	//std::ios::sync_with_stdio(false);
	while(~scanf("%d",&n)){
		map<long double,int> mp1,mp2;
		mp1.clear();mp2.clear();
		cnt = 0,cnt0 = 0,cnt1 = 0,cnt2 = 0;
		per(i,1,n){
			scanf("%d",&a[i]);
		}
		per(i,1,n){
			scanf("%d",&b[i]);
		}
		per(i,1,n){
			if(a[i] != 0 && b[i] == 0){
				++cnt0;
				continue;
			}
			if(a[i] == 0 && b[i] == 0){
				++cnt;
				continue;
			}
			
			if(a[i] == 0 && b[i] != 0){
				continue;
			}
			
			++mp1[b[i]*1.0/a[i]];
			++mp2[a[i]*1.0/b[i]];
		}
		int ans = cnt0;
		map<long double,int>::iterator it = mp1.begin();
		for(it = mp1.begin();it != mp1.end();++it){
			ans = max(ans,it->second);
		}
		for(it = mp2.begin();it != mp2.end();++it){
			ans = max(ans,it->second);
		}
		printf("%d\n",ans+cnt);
	}
	return 0;
}

