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

string pre, suf, sub;
bool badword(string s){
	if(s.size()>=pre.size()){
		int flag=1;
		REP(i,pre.size()){
			if(s[i]!=pre[i]){
				flag=0;
			}
		}
		if(flag) return true;
	}
	if(s.size()>=suf.size()){
		int flag=1;
		REP(i,suf.size()){
			if(s[s.size()-suf.size()+i]!=suf[i]){
				flag=0;
			}
		}
		if(flag) return true;
	}
	if((int)s.size()-2 >= (int)sub.size() ){
		string s2(s,1,s.size()-2);
		for(int i=0; i<=s2.size()-sub.size(); i++){
			int flag=1;
			for(int j=0; j<sub.size(); j++){
				if(s2[i+j]!=sub[j]){
					flag=0;
					break;
				}
			}
			if(flag){
				return true;
			} 
		}
	}
	return false;
}

int main(){
	string w;
	int ncases, l;
	scanf("%d",&ncases);
	while(ncases--){
		cin>>pre>>suf>>sub;
		cin>>l;
		int ans = 0;
		REP(i,l){
			cin>>w;
			if(badword(w)){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}


