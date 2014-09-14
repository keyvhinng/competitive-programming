//UVA 120 Stacks of Flapjack
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

vector<int> v, v_aux;

int is_ord(void){
	int l, ans;
	int i = 0;
	l = v.size()-1;
	while(i<l && (v[i]<v[i+1])){
		i++;
	}
	if (i==l){
		ans = 1;
	}else{
		ans = 0;
	}
	return ans;
}

int main(){
	char c;
	int num, flag, top, r, sz, l;
	c = 'a';
	flag = 0;
	while(!flag){
		v.clear();
		v_aux.clear();
		scanf("%d",&num);
		v.pb(num);
		while(1){
			if(scanf("%c",&c)==EOF){
				flag = 1;
				break;
			}
			if(c=='\n'){
				break;
			}else{
				scanf("%d",&num);
				v.pb(num);
			}
		}
		if(!flag){
			//print
			f(i,0,v.size()){
				cout<<v[i];
				if(i!=v.size()-1){
					cout<<" ";
				}
				v_aux.pb(v[i]);
			}
			cout<<endl;
			//simulation
			sort(v_aux.begin(), v_aux.end());
			sz = v.size();
			//int flag2 = 0;
			while(!is_ord()){
				//cout<<"entro"<<endl;
				l = sz-1;
				top = v[0];
				//cout<<"top "<<top<<endl;
				r = 1;
				if(top>v[r]){
					while(r<sz && top>v[r]){
						r++;
					}
				}else{
					while(v_aux[l]==v[l]){
						l--;
					}	
					l++;
					while(r<l && top<v[r]){
						r++;
					}
				}
				cout<<sz + 1 - r<<" ";
				reverse(v.begin(),v.begin()+r);
				//f(i,0,v.size()){
				//	cout<<v[i]<<" ";
				//}
				//cout<<endl;
				//flag2++;
			}
			cout<<"0"<<endl;
		}
	}
	return 0;
}
