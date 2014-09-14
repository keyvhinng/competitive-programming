#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <cmath>
#include <algorithm>
#include <ctime>

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

using namespace std;

int main(){
	string s;
	int ncases, n, ans, tmp, flag;
	int m[25][25], aux[25][25];
	scanf("%d",&ncases);
	f(k,0,ncases){	
		if(k)
			printf("\n");
		cin>>s;
		n = s.size();
		f(i,0,n){
			m[0][i] = s[i] - '0';
		}
		f(i,1,n){
			cin>>s;
			f(j,0,s.size()){
				m[i][j] = s[j] - '0';
			}
		}
		/*
		printf("== m == \n");
		f(i,0,n){
			f(j,0,n){
				printf("%d",m[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		*/
		f(i,0,n){
			f(j,0,n){
				aux[i][j] = m[i][j];
				if(i)
					aux[i][j] += aux[i-1][j];
				if(j)
					aux[i][j] += aux[i][j-1];
				if(i&&j)
					aux[i][j] -= aux[i-1][j-1];
			}
		}
		/*
		printf("== aux == \n");
		f(i,0,n){
			f(j,0,n){
				printf("%d",m[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		*/
		ans = 0;
		f(i,0,n){
			f(j,0,n){
				f(p,i,n){
					f(q,j,n){
						tmp = aux[p][q];
						if(j)
							tmp -= aux[p][j-1];
						if(i)
							tmp -= aux[i-1][q];
						if(i&&j)
							tmp += aux[i-1][j-1];
						if(tmp>ans && tmp==(p-i+1)*(q-j+1)){
							ans = tmp;
						}
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
