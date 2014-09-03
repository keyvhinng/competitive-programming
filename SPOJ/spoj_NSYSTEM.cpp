//SPOJ NSYSTEM
#include <cassert>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <numeric>
#include <sstream>
#include <cmath>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define f(i,x,y) for(int i = x; i<y; i++)
#define FOR(it,A) for(typeof A.begin(); it!=A.end(); it++)
#define quad(x) (x)*(x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second

typedef long long ll;
typedef pair<int, int> pii;

//integer to MCXI
string rtrans(int n){
	int m, c, d, u;
	string s="";
	m = n/1000;
	c = n/100;
	c = c%10;
	d = n/10;
	d = d%10;
	u = n%10;
	if(m!=0){
		if(m!=1){
			s+=m+'0';
		}
		s+="m";
	}
	
	if(c!=0){
		if(c!=1){
			s+=c+'0';
		}
		s+="c";
	}

	if(d!=0){
		if(d!=1){
			s+=d+'0';
		}
		s+="x";
	}

	if(u!=0){
		if(u!=1){
			s+=u+'0';
		}
		s+="i";
	}

	return s;
}

//MCXI to integer
int trans(string s){
	int ans, r, k;
	ans = 0;
	r = 0;
	k = 1;
	while(r<s.size()){
		if(s[r]>='2'&& s[r]<='9'){
			k = s[r] - '0';
		}else{
			if(s[r]=='m'){
				ans += k*1000;
			}
			else if(s[r]=='c'){
				ans += k*100;
			}
			else if(s[r]=='x'){
				ans += k*10;
			}
			else{
				ans += k;
			}
			k = 1;
		}
		r++;
	}
	return ans;
}

int main(){
	int n, sum;
	string s1, s2, ssum;
	scanf("%d",&n);
	while(n--){
		cin>>s1>>s2;
		sum = trans(s1) + trans(s2);
		ssum = rtrans(sum);
		cout<<ssum<<endl;
	}
	return 0;
}
