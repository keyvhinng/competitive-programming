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

int main(){
	int64 a, b, num;
	string s, aux;
	while(getline(cin,s)){
		if(s.size()==0) break;
		cin>>a>>b;
		cin.ignore();
		if(a==9 || b==9){
			if(a==9) printf("A\n");
			else printf("B\n");
		}else{
			aux="";
			REP(i,(int)s.size()){
				if(s[i]=='+' || s[i]=='-'){
					aux = aux + ' ';
				}
				aux = aux + s[i];
			}
			stringstream ss(aux);
			int64 ans = 0; 
			while(ss>>num){
				ans += num;
			}
			if(ans==a) printf("B\n");
			else printf("A\n");
		}
	}
	return 0;
}


