#include <algorithm>
#include <bitset>
#include <deque>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define fst first
#define snd second
#define all(x) (x).begin(), (x).end()
#define clr(a, v) memset(a, v, sizeof(a))
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x.size())
#define REPN(i,s,n) for(int i=s;i<(int)(n);i++)
#define REP(i,n) REPN(i,0,n)
#define REPIT(i,x) for( typeof x.begin()  i=x.begin(); i!=x.end(); i++ )
#define trace(x)    cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;

using namespace std;

typedef long long int64;
typedef vector <int> vi;
typedef pair <int,int> ii;
typedef vector <string> vs;
typedef vector <ii> vii;

const int INF = 2e9+9;

bool isVowel(char c){
	if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
	return false;
}

int main(){
	string s;
	int ncases;
	scanf("%d",&ncases);
	while(ncases--){
		cin>>s;
		REP(i,s.size()){
			s[i] = tolower(s[i]);
		}
		string ans = "";
		int vowel[60];
		memset(vowel,0,sizeof(vowel));
		REP(i,s.size()){
			if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
				ans = ans + "V";
				vowel[i]=1;
			}else if(i!=0 && s[i]=='y' && !vowel[i-1]){
				ans = ans + "V";
				vowel[i]=1;
			}else{
				ans = ans + "C";
				vowel[i]=0;
			}
		}
		int r = 1;
		string res = "";
		res = res + ans[0];
		for(int i=1; i<s.size(); i++){
			if(ans[i]!=ans[i-1]) res = res + ans[i];
		}
		cout<<res<<endl;
	}
	return 0;
}

