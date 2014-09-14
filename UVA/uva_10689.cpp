
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
typedef pair<int, int> ii;
typedef vector<long> vl;
typedef vector<ii> vii;

int f[15100];

int main(){
	int ncases, a, b, m, s, pot, cycle;
	long long int n;
	scanf("%d",&ncases);
	f(i,0,ncases){
		scanf("%d %d %lld %d",&a, &b, &n, &m);
		switch(m){
			case 1:
				cycle = 60;
				break;
			case 2:
				cycle = 300;
				break;
			case 3:
				cycle = 1500;
				break;
			case 4:
				cycle = 15000;
				break;
			default:
				cout<<"ERROR"<<endl;
		}
		pot = 1;
		f(k,0,m){
			pot *= 10;
		}
		f[0] = a;
		f[1] = b;
		f(j,2,cycle){
			f[j] = (f[j-2] + f[j-1])%pot;
		}
		n = n % cycle;
		//printf("n = %lld\n",n);
		//printf("cycle %d\n",cycle);
		printf("%d\n",f[n]);
	}
	return 0;
}
