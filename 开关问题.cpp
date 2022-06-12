#include<iostream>
#include<cstdio>
#include<vector>
#include<bitset>
#include<stack>
#include<set>
#include<queue>
#include<map>
#include<cmath>
#include<string>
#include<cstring>
#include<ctime>
#include<fstream>
#include<cstdlib>
#include<algorithm>

using namespace std;

#define pii pair<int, int>
#define mp(a,b) make_pair(a,b)
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
#define PER(i,x) for(auto i=x.brgin();i!=x.end();i++)
#define all(x) x.begin(),x.end()
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
typedef long long ll;
const double eps=1.0e-5;
const int maxn=100000+10;

int a[25],f[25];

void solve(){
	mem(f,0);
	int res1=0,res2=0;
	per(i,2,20){
		if((f[i-1]+a[i-1])%2){
			f[i]++;
			f[i-1]++;
			f[i+1]++;
			res1++;
		}
	}
	mem(f,0); 
	rep(i,19,1){
		if((f[i+1]+a[i+1])%2){
			f[i]++;
			f[i+1]++;
			f[i-1]++;
			res2++;
		}
	}
	
	printf("%d\n",min(res1,res2));
}

int main(){
	//freopen("C:\\Users\\MAC\\Desktop\\in.txt","r",stdin);
	per(i,1,20) scanf("%d",&a[i]);
	solve();
}
