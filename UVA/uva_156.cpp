//UVA 156
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
	int arr[1010], n, cont, j, arrt[1010];
	vector<string> vs;
	vector<string> v_aux;
	string s;
	map<string,int> m;
	map<string,int>::iterator it;
	cin>>s;
	//Store all string in a vector
	while(s[0]!='#'){
		vs.pb(s);
		cin>>s;
	}
	
	//Sort dictionary
	sort(vs.begin(),vs.end());
	//cout<<"==ORIGINAL DICTIONARY"<<endl;
	//f(i,0,vs.size()){
	//	cout<<vs[i]<<endl;
	//}
	
	//To lower cases
	f(i,0,vs.size()){
		//To lower case
		s = "";
		f(j,0,vs[i].size()){
			s += tolower(vs[i][j]);
		}
		v_aux.pb(s);
       	}


	//cout<<"==DICTIONARY"<<endl;
	//f(i,0,vs.size()){
	//	cout<<v_aux[i]<<endl;
	//}
	
	//initialize array
	f(i,0,vs.size()){
		arr[i] = 0;
		arrt[i] = 0;
	}

	//cout<<"==Ordered words"<<endl;
	f(i,0,vs.size()){
		sort(v_aux[i].begin(),v_aux[i].end());
	}

	j = 0;
	cont = 0;
	n = vs.size();
	f(j,0,n){
		if(!arr[j]){
			cont++;
			arrt[j]++;
			f(k,j+1,n){
				if(v_aux[j]==v_aux[k]){
					arrt[j]++;	
					arr[k] = 1;
				}
			}
		}
	}
	//Print
	//cout<<"==Print"<<endl;
	f(i,0,n){
		if((!arr[i] && arrt[i]==1)||(!arr[i] && vs[i].size()==1)){
			cout<<vs[i]<<endl;
		}
	}
	return 0;
}
