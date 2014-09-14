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

int reverse(int k){
	int num, aux;
	num = 0;
	while(k){
		aux = k % 10;
		k /= 10;
		num *= 10;
		num += aux;
	}
	return num;
}

int main(){
	int n, a, b, ra, rb;
	scanf("%d",&n);
	while(n--){
		scanf("%d %d",&a,&b);
		ra = reverse(a);
		rb = reverse(b);
		printf("%d\n",reverse(ra+rb));
	}
	return 0;
}

