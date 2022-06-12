#include<iostream>
#include<string>
#include<vector>
using namespace std;
const int maxn = 100 + 10;

int Manacher(string s){
	string t = "$#";//
	for(int i = 0;i < s.size();++i){
		t += s[i];
		t += "#";
	}
	
	vector<int> p(t.size(),0);
	int mx = 0,id = 0,resLen = 0,resCenter = 0;
	
	for(int i = 1;i < t.size();++i){
		p[i] = mx > i?min( mx-i , p[2*id-i] ) : 1;
		
		while(t[i + p[i]] == t[i - p[i]]){
			++p[i];
		}
		
		if(i + p[i] > mx){
			mx = i + p[i];
			id = i;
		}
		
		if(resLen < p[i]){
			resLen = p[i];
			resCenter = i;
		}
	}
	
	//return s.substr( (resCenter - resLen)/2 , resLen-1);
	return resLen - 1;
	
} 
int main(){
	
	string str1;
	int kase = 0;
	cout<< "nima" <<endl;
	while(cin >> str1 && str1 != "END"){
		cout << "Case " << ++kase << ": " << Manacher(str1) << endl;
	}
	
	return 0;
} 
