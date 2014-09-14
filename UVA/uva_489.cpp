//UVA 489
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

vector<char> plbf;
string sol;
string sol2;

int correct(char c){
	int ans = 0;
	for(int i=0; i<sol.size(); i++){
		if(sol[i]==c){
			ans = 1;
			break;
		}
	}
	return ans;
}

int isIn(string v, char c){
	int ans = 0;
	for(int i=0; i<v.size(); i++){
		if(v[i]==c){
			ans = 1;
			break;
		}
	}
	return ans;
}

int play_before(char c){
	int ans = 0;
	for(int i=0; i<plbf.size(); i++){
		if(plbf[i]==c){
			ans = 1;
			break;
		}
	}
	return ans;
}


int main(){
	int round, guess, wrong, loose;
	char c;
	string seq;
	while(scanf("%d",&round) && (round!=-1)){
		plbf.clear();
		sol.clear();
		cin>>sol2;
		//sol
		for(int i=0; i<sol2.size(); i++){
			if(!isIn(sol, sol2[i])){
				sol.pb(sol2[i]);
			}
		}
		//cout<<"sol "<<sol<<endl;
		cin>>seq;
		//play
		guess = 0;
		loose = 0;
		wrong = 0;
		for(int i=0; i<seq.size() && (!loose); i++){
			c = seq[i];	
			if(!play_before(c)){
				plbf.pb(c);
				if(correct(c)){
					guess++;
					//cout<<"correct with "<<c<<endl;
					if(guess==sol.size())
						break;
				}else{
					wrong++;	
					if(wrong==7){
						loose = 1;
					}
				}
			}
		}
		printf("Round %d\n",round);
		if(loose){
			printf("You lose.\n");
		}else{
			if(guess==sol.size()){
				printf("You win.\n");
			}else{
				printf("You chickened out.\n");
			}
		}
	}
	return 0;
}
