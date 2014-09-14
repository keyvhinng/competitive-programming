//UVA 10424
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


typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

int toOne(int n){
	int aux,s;
	while(n>9){
		s = 0;
		while(n){
			s += n%10;
			n /= 10;
		}
		n = s;
	}
	return n;
}

int getValue(string s){
	char c;
	int ans;
	ans = 0;
	for(int i=0; i<s.size(); i++){
		if(isalpha(s[i])){
			ans += tolower(s[i]) - 'a' + 1;		
		}
	}
	return ans;
}

int main(){
	string s1, s2;
	int v1, v2;
	double r;
	while(getline(cin,s1)){
		getline(cin,s2);
		v1 = getValue(s1);
		v2 = getValue(s2);
		v1 = toOne(v1);
		v2 = toOne(v2);
		if(v1>v2) swap(v1,v2);
		r = (double)v1/(double)v2;
		r *= 100;
		printf("%.2lf %%\n",r);
	}
	return 0;
}

