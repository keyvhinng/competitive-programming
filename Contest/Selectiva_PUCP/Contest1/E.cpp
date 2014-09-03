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

#define EPS 1e-9

using namespace std;

typedef long long int64;
typedef vector <int> vi;
typedef pair <int,int> ii;
typedef vector <string> vs;
typedef vector <ii> vii;

const int INF  = 2e9+9;


int main(){
	string text, search, whole;
	int ncases, n, m, start;
	size_t found;
	cin>>ncases;
	cin.ignore();
	while(ncases--){
		getline(cin,text);
		cin>>search>>whole;
		cin>>start;
		cin.ignore();
		int flag=0;
		for(int i=start; i<=(int)text.size()-(int)search.size(); i++){
			found = text.find(search,i);
			if(found!=-1){
				if(whole[0]=='Y'){
					if( (found==0 || text[found-1]==' ') && (found==text.size()-search.size() || text[found+search.size()]==' ')){
						printf("%d\n",(int)found);
						flag=1;
						break;
					}
				}else{
					printf("%d\n",(int)found);
					flag=1;
					break;
				}
			}
		}
		if(!flag) printf("-1\n");
	}
	return 0;
}


