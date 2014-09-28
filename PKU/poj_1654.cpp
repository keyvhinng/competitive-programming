//POJ 1654
#include <cassert>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <numeric>
#include <sstream>
#include <cmath>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define f(i,x,y) for(int i = x; i<y; i++)
#define FOR(it,A) for(typeof A.begin(); it!=A.end(); it++)
#define quad(x) (x)*(x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second

typedef long long ll;
typedef pair<int, int> pii;

double INF = 1e100;
double EPS = 1e-12;

int d[10][2] = {{0,0}, {-1,-1}, {0,-1}, {1,-1}, {-1,0}, {0,0}, {1,0}, {-1,1}, {0,1}, {1,1}};
char str[1000005];

struct PT{
	int x, y;
	PT() {}
	PT(int x, int y) : x(x),     y(y)    {}
	PT(const PT &p)  : x(p.x), y(p.y)    {}
};


//double ComputeSignedArea(const vector<PT> &p){
	//double area = 0;
	//for(int i=0; i < p.size(); i++){
	//	int j = (i+1) % p.size();
	//	area += (double)p[i].x*p[j].y - (double)p[j].x*p[i].y;
	//}
	//return area / 2.0;
//}

//double ComputeArea(const vector<PT> &p){
//	return fabs(ComputeSignedArea(p));
//}



int main(){
	long long area;
	int t, len, dir;
	scanf("%d",&t);
	while(t--){
		area = 0;
		PT p(0,0), pant(0,0);
		cin>>str;
		if (str[0]=='5'){
			cout<<0<<endl;
			continue;
		}
		len = strlen(str);
		p.x = d[str[0] - '0'][0];
		p.y = d[str[0] - '0'][1];
		for(int i=1; str[i]!='5'; i++){
			dir = str[i] - '0';
			pant.x = p.x;
			pant.y = p.y;
			p.x += d[dir][0];
			p.y += d[dir][1];
			area += pant.x*p.y - p.x*pant.y;
		}
		if(area<0)
			area = -area;
		cout<<area/2;
		if(area%2)
			cout<<".5";
		cout<<endl;
	}
	return 0;
}

