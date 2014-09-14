#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <cmath>
#include <cassert>
#include <list>
#include <stack>
#include <bitset>
#include <functional>
#include <utility>
#include <sstream>
#include <cctype>
#include <ctime>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define f(i,x,y) for(int i=x; i<y; i++)
#define FOR(it,A) for(typeof A.begin(); it!=A.end(); it++)
#define quad(x) (x)*(x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second

typedef long long ll;
typedef pair<int,int> pii;


int main(){
	int h, m;
	double hang, mang, dif, dif2;
	while(scanf("%d:%d",&h, &m) && (h+m!=0)){
		//printf("%d:%d\n",h,m);
		if(h==12)
			h=0;
		hang = 30*h;
		hang += (double)m/(double)2;
		mang = m*6;
		//printf("hang %lf\n",hang);
		//printf("mang %lf\n",mang);
		dif = abs(hang - mang);
		if(dif < 360-dif){
			printf("%.3lf\n",dif);
		}else{
			printf("%.3lf\n",360-dif);
		}
	}
	return 0;
}
