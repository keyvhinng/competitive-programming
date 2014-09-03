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

#define eps 1e-10

typedef long long int64;
typedef vector <int> vi;
typedef pair <int,int> ii;
typedef vector <string> vs;
typedef vector <ii> vii;

const int INF = 2e9+9;

vector<string> nam;



struct myst{
	double time;
	int fast, slow;
	myst(double a, int i, int j){
		time = a;
		fast = i;
		slow = j;
	}
};

bool cmp(myst x, myst y){
	if(fabs(x.time-y.time)>eps)
		return x.time<y.time;
	return nam[x.slow]<nam[y.slow];
}

int main(){
	string s;
	int ncases, l, num;
	scanf("%d",&ncases);
	while(ncases--){
		int track;
		vector<string> name, ans;
		vector<int> start, speed;
		//track
		cin>>track;
		//name
		cin>>l;
		REP(i,l){
			cin>>s; name.pb(s);
		}
		//start
		cin>>l;
		REP(i,l){
			cin>>num; start.pb(num);
		}
		//speed
		cin>>l;
		REP(i,l){
			cin>>num; speed.pb(num);
		}
		//start
		nam=name;
		int n=name.size();
		int i,j,k;
		vector<myst> f;
		vector<double> st,sp;
		for(i=0; i<n; i++){
			st.pb(double(start[i]));
			sp.pb(double(speed[i]));
		}
		for(i=0; i<n; i++)
			for(j=0; j<n; j++) { 
			 if(st[i]<st[j] && st[i]+track/sp[i]<=st[j]+eps) { 
				 f.pb(myst(st[i]+track/sp[i],i,j)); continue;
			 }
			 if(st[j]<st[i] && st[j]+track/sp[j]<=st[i]+eps) {
				 f.pb(myst(st[j]+track/sp[j],j,i)); continue; 
			 }
			 if(sp[i]>sp[j]) {
				 if(st[i]>st[j]) {
					 double t=(st[i]-st[j])*sp[j]/(sp[i]-sp[j])+st[i];
					 f.pb(myst(t,i,j));
				 } else {
					 double d = double(track)-(st[j]-st[i])*sp[i];
					 double t = d/(sp[i]-sp[j])+st[j];
					 f.pb(myst(t,i,j));
				 }
			 }
		}
		sort(f.begin(),f.end(),cmp);
		vector<string> ret;
		vector<int> ok(n,1);
		for(i=0; i<(int)f.size(); i++)
			if(ok[f[i].fast] && ok[f[i].slow]) {
				ret.pb(name[f[i].slow]); 
				ok[f[i].slow]=0;
			}
		//print
		printf("%d\n",(int)ret.size());
		REP(i,(int)ret.size()) cout<<ret[i]<<endl;
	}
	return 0;
}


