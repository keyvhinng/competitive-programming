//UVA 11577
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
typedef pair<int,int> pii;

int main(){
	string s;
	int ncases, aux, max, r;
	int cont[26];
	int alf[26];
	char c;
	cin>>ncases;
	cin.ignore();
	while(ncases--){
		for(int i=0; i<26; i++){
			alf[i] = i;
		}
		memset(cont, 0, sizeof cont);
		getline(cin,s);
		for(int i=0; i<s.size(); i++){
			if(s[i]>=65 && s[i]<=90){
				s[i] += 'a' - 'A';
			}
		}
		for(int i=0; i<s.size(); i++){
			if(s[i]>=97 && s[i]<=122){
				cont[s[i]-'a']++;
			}
		}
		for(int i=0; i<26; i++){
			for(int j=i+1; j<26; j++){
				if(cont[j]>cont[i]){
					aux = cont[i];
					cont[i] = cont[j];
					cont[j] = aux;
					aux = alf[i];
					alf[i] = alf[j];
					alf[j] = aux;
				}
			}
		}
		max = cont[0];
		r = 0;
		while(cont[r]==max){
			c = 97 + alf[r];
			cout<<c;
			r++;
		}
		cout<<endl;
	}
	return 0;
}
