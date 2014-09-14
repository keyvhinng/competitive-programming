//UVA 195
//Keyvhinng
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

bool cmp(const char &a, const char &b){
	int delta = tolower(a) - tolower(b);
	return (delta ? delta<0 : a<b);
}

int main(){
	string s;
	int ncases;
	scanf("%d",&ncases);
	while(cin>>s){
		sort(s.begin(),s.end(),cmp);
		cout<<s<<endl;
		while(next_permutation(s.begin(),s.end(),cmp))
			cout<<s<<endl;
	}
	return 0;
}
