//UVA 10340
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <cmath>
#include <cassert>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define f(i,x,y) for(int i=x; i<y; i++)
#define FOR(it,A) for(typeof A.begin(); it!=A.end(); it++)
#define quad(x) (x)*(x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second

typedef long long ll;
typedef pair<int,int> pii;

int main(){
	string s1, s2;
	int ans, r, i, cont;
	while(cin>>s1>>s2){
		cont = 0;
		ans = 1;
		r = 0;
		for(i=0;i<s1.size();i++){
			while(r<s2.size() && s1[i]!=s2[r] ){
				r++;
			}
			if(r<s2.size() && s1[i]==s2[r]){
				cont++;
			}
			r++;
			if(r==s2.size())
				break;
		}
		if(cont==s1.size()){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
