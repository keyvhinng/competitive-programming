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
typedef pair<int, int> II;
typedef vector<II> VII;

string s1, s2;

int pos(int x, int i){
	int r;
	r = i;
	while(s2[r]!=x){
		r++;
	}
	return r-i;
}

void post(int i1, int j1, int i2, int j2){
	int k;
	if(j2<i2)
		return;
	else if(i2==j2){
		printf("%c",s2[i2]);
	}
	else{
		k = pos(s1[i1],i2);
		post(i1+1   ,i1+k ,i2     , i2+k-1);
		post(i1+k+1 ,j1   ,i2+k+1 , j2);
		printf("%c",s1[i1]);	
	}
	return;
}

int main(){
	while(cin>>s1>>s2){
		//cout<<s1<<" "<<s2<<endl;
		post(0,s1.size()-1,0,s2.size()-1);
		printf("\n");
	}
	return 0;
}
