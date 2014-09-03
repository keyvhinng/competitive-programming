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
	string init, goal, goal2;
	int ncases;
	scanf("%d",&ncases);
	while(ncases--){
		cin>>init>>goal;
		goal2 = "";
		REP(i,goal.size()){
			if(goal[i]!='z'){
				goal2 = goal2 + goal[i];
			}
		}
		int flag=1;
		if(init.size()!=goal2.size()){
			flag = 0;
		}else{
			REP(i,init.size()){
				if(init[i]!=goal2[i]){
					flag=0;
					break;
				}
			}
		}
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

