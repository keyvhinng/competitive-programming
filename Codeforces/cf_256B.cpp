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
#define FORN(i,s,n) for(int i=s;i<(int)(n);i++)
#define REP(i,n) FORN(i,0,n)
#define FORIT(i,x) for( typeof x.begin()  i=x.begin(); i!=x.end(); i++ )
#define trace(x)    cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;

using namespace std;

typedef long long int64;
typedef vector <int> vi;
typedef pair <int,int> ii;
typedef vector <string> vs;
typedef vector <ii> vii;

const int INF = 2e9+9;

int main(){
	string s, t;
	cin>>s>>t;
	bool aut, arr, needtree;
	aut = false;
	arr = false;
	needtree = false;
	int alfA[26], alfB[26];
	clr(alfA,0); clr(alfB,0);
	REP(i,s.size())
		alfA[s[i]-'a']++;
	REP(i,t.size())
		alfB[t[i]-'a']++;
	REP(i,26){
		if(alfB[i]>alfA[i]){
			needtree = true;
		}
	}
	if(needtree){
		printf("need tree\n");
	}else{
		if(s.size() != t.size()){
			aut = true;
		}
		int pos = -1;
		REP(i,t.size()){
			char c = t[i];
			bool flag = false;
			//printf("buscando %c\n",c);
			do{
				pos++;
				if(pos==s.size()){
					arr = true;
					flag = true;
					break;
				}
			}while(s[pos]!=c);
			if(flag) break;
		}
		if(arr && aut){
			printf("both\n");
		}else if(arr)
			printf("array\n");
		else printf("automaton\n");
	}
	return 0;
}


