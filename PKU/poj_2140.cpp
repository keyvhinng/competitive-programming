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

int main(){
	int n;
	int result = 0;
	cin>>n;
	for(int i=1; (i+1)*i/2 <= n; i++){
		int temp = (i+1) * i/2;
		if((n-temp)%i==0){
			result++;
		}
	}
	cout<<result<<endl;
	return 0;
}
