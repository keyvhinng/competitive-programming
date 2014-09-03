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
		return c-'0';
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

int getval2(char c){
		switch(c){
			case 'C':
				return 1;
				break;
			case 'D':
				return 2;
				break;
			case 'S':
				return 3;
				break;
			case 'H':
				return 4;
				break;
		}
		return -1;
}

bool mySort(string a, string b){
	int val1 = getval(a[0]);
	int val2 = getval(b[0]);
	if(val1!=val2){
		return val1<val2;
	}else{
		return getval2(a[1]) < getval2(b[1]);
	}
}

int main(){
	string card;
	int ncases, k;
	scanf("%d",&ncases);
	while(ncases--){
		vector<string> da, de;
		scanf("%d",&k);
		REP(i,k){
			cin>>card;
			da.pb(card);
		}
		REP(i,k){
			cin>>card;
			de.pb(card);
		}
		sort(da.begin(), da.end(), mySort);
		sort(de.begin(), de.end(), mySort);
		int ans = 0;
		int r = 0;
		REP(i,k){
			if(r==k) break;
			if(mySort(da[r],de[i])){
				ans++;
				r++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}


