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

VI LongestIncreasingSubsequence(VI v){
	VPII best;
	VI dad(v.size(), -1);

	for(int i=0; i<v.size(); i++){
		PII item = make_pair(v[i],0);
		VPII::iterator it;
		it = lower_bound(best.begin(), best.end(), item);
		item.second = i;
		if(it==best.end()){
			dad[i] = (best.size() == 0 ? -1 : best.back().second);
			best.push_back(item);
		}else{
			dad[i] = (it==best.begin() ? -1 : (it-1)->second);
			*it = item;
		}
	}
	VI ret;
	for(int i=best.back().second; i>=0; i=dad[i]){
		ret.push_back(v[i]);
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int toInt(string s){
	int ans = 0;
	for(int i=0; i<s.size(); i++){
		ans *= 10;
		ans += s[i]-'0';
	}
	return ans;
}

int main(){
	vector<int> v;
	vector<int> LIS;
	string s;
	int ncases;
	char c;
	cin>>ncases;
	cin.ignore();
	cin.ignore();
	while(ncases--){
		v.clear();
		while(1){
			getline(cin,s);
			if(s.size()==0){
				break;
			}
			v.push_back(toInt(s));
		}
		LIS = LongestIncreasingSubsequence(v);
		printf("Max hits: %d\n",(int)LIS.size());
		for(int i=0; i<(int)LIS.size(); i++){
			printf("%d\n",LIS[i]);
		}
		if(ncases)
			printf("\n");
	}
	return 0;
}
