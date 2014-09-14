
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
	string s;
	int freq[30];
	char alfa[30];
	int n, e, j;
	char c;
	map<char, int> m;
	map<char,int>::iterator it;
	map<int, char> m2;
	map<int, char>::iterator it2;
	scanf("%d",&n);
	scanf("%c",&c);
	while(n--){
		getline(cin,s);
		for(int i=0; i<s.size(); i++){
			if(s[i]>=97 && s[i]<=122){
				m[s[i]-('a'-'A')]++;	
			}else if(s[i]>=65 && s[i]<=90){
				m[s[i]]++;
			}
		}
	}
	int r;
	r = 0;
	for(it=m.begin(); it!=m.end(); it++){
		//cout<<(*it).first<<" "<<(*it).second<<endl;
		freq[r] = (*it).second;
		alfa[r] = (*it).first;
		r++;
	}
	for(int i=1; i<r; i++){
		e = freq[i];
		c = alfa[i];
		j = i-1;
		while(j>=0 && freq[j]>=e){
			freq[j+1] = freq[j];
			alfa[j+1] = alfa[j];
			j--;
		}
		freq[j+1] = e;
		alfa[j+1] = c;
	}

	for(int i=r-1; i>=0; i--){
		printf("%c %d\n",alfa[i], freq[i]);
	}

	return 0;
}
