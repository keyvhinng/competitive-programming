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

int isin(string n1, string n2){
	int ans;
	ans = 1;
	f(i,0,n1.size()){
		if(n1[i]!=n2[i]){
			ans = 0;
			break;
		}
	}
	return ans;
}

int main(){
	string s;
	int ncases, nt, t, flag;
	vector<string> v;
	cin>>ncases;
	f(i,0,ncases){
		//printf("CASE\n");
		v.clear();
		cin>>nt;
		f(j,0,nt){
			cin>>s;
			v.pb(s);
		}
		sort(v.begin(), v.end());
		/*
		f(j,0,nt){
			cout<<v[j]<<endl;
		}
		*/

		flag = 1;
		f(j,0,nt-1){
			if(isin(v[j],v[j+1])){
				flag = 0;
				break;
			}
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

