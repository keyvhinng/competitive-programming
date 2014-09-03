#include <algorithm>
#include <bitset>
#include <deque>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define fst first
#define snd second
#define all(x) (x).begin(), (x).end()
#define clr(a, v) memset(a, v, sizeof(a))
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x.size())
#define REPN(i,s,n) for(int i=s;i<(int)(n);i++)
#define REP(i,n) REPN(i,0,n)
#define REPIT(i,x) for( typeof x.begin()  i=x.begin(); i!=x.end(); i++ )
#define trace(x)    cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;

using namespace std;

typedef long long int64;
typedef vector <int> vi;
typedef pair <int,int> ii;
typedef vector <string> vs;
typedef vector <ii> vii;

const int INF = 2e9+9;

int getval(char c){
	if(isdigit(c)){
		return c - '0';
	}else{
		switch(c){
			case 'T':
				return 10;
				break;
			case 'J':
				return 11;
				break;
			case 'Q':
				return 12;
				break;
			case 'K':
				return 13;
				break;
			case 'A':
				return 14;
				break;
		}
	}
	return -1;
}

bool mySort(string s1, string s2){
	if(s1[0]!=s2[0]) return s1<s2;
	int val1 = getval(s1[1]);
	int val2 = getval(s2[1]);
	return val1<val2;
}

int main(){
	vector<string> vs;
	string s, ans;
	int ncases;
	scanf("%d",&ncases);
	while(ncases--){
		cin >> s;
		vs.clear();
		REP(i,s.size()/2){
			string tmp(s,2*i,2);
			vs.pb(tmp);
		}
		sort(vs.begin(),vs.end(),mySort);
		ans = "";
		REP(i,vs.size()){
			ans = ans + vs[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}


