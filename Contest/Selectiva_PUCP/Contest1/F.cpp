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

bool isVowel(char c){
	if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
		return true;
	return false;
}

bool isCons(char c){
	return !isVowel(c);
}

int main(){
	string s;
	vector<string> vs;
	int ncases, l;
	scanf("%d",&ncases);
	while(ncases--){
		scanf("%d",&l);
		vs.clear();
		REP(i,l){
			cin>>s;
			vs.pb(s);
		}
		int flag=1;
		REP(i,l){
			string tmp;
			s = vs[i];
			tmp = s;
			REP(j,(int)s.size()) s[j] = tolower(s[j]);
			REP(j,(int)s.size()-2){
				if(isCons(s[j]) && isCons(s[j+1]) && isCons(s[j+2])){
					flag=0;
					break;
				} 
			}
			REP(j,(int)s.size()-1){
				if(isVowel(s[j]) && isVowel(s[j+1]) && (s[j]!=s[j+1])){
					flag=0;
					break;
				} 
			}
			if(!flag){
				cout<<tmp<<endl;
				break;
			}
		}
		if(flag) printf("\n");
	}
	return 0;
}


