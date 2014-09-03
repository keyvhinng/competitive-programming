// SPOJ LABY
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

char m[1010][1010];
char v[1010][1010];
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

int R, C;
int maxi , maxj;
int maxlen;

int dfs_aux(int i, int j, int l){
	//cout<<"l is "<<l<<endl;
	int ni, nj, ans, max;
	max = 1;
	v[i][j] = 'Y';
	l++;
	if(l>maxlen){
		maxi = i;
		maxj = j;
		maxlen = l;
	}
	f(r,0,4){
		ni = i + dx[r];
		nj = j + dy[r];
		if(ni>=0 && nj>=0 && ni<R && nj<C && v[ni][nj]=='N' && m[ni][nj]=='.'){
			ans = 1 + dfs_aux(ni,nj,l);
			if(ans>max){
				max = ans;
			}
		}
	}
	return max;
}

int dfs(int i,int j){
	//cout<<"i "<<i<<" j "<<j<<endl;
	int ni, nj, ans, max;
	max = 1;
	v[i][j] = 'Y';
	f(r,0,4){
		ni = i + dx[r];
		nj = j + dy[r];
		//cout<<"ni "<<ni<<" nj "<<nj<<endl;
		//printf("m[1][2] = %c\n",m[1][2]);
		if(ni>=0 && nj>=0 && ni<R && nj<C && v[ni][nj]=='N' && m[ni][nj]=='.'){
		//	cout<<"entro "<<"ni "<<ni<<" nj "<<nj<<endl;
			ans = 1 + dfs(ni, nj);
			if(ans>max)
				max = ans;
		}
	}
	return max;
}

int main(){
	char c;
	int ncases, max, ans, flag;
	scanf("%d",&ncases);	
	while(ncases--){
		flag = 0;
		max = 0;
		scanf("%d %d",&C, &R);
		scanf("%c",&c);
		f(i,0,R){
			f(j,0,C){
				scanf("%c",&m[i][j]);
			}
			scanf("%c",&c);
		}
		f(i,0,R){
			f(j,0,C){
				if(m[i][j]=='.'){
					flag = 1;
					memset(v,'N',sizeof(v));
					//dfs1
					maxlen = 0;
					maxlen = 0;
					ans = dfs_aux(i,j,0);
					//f(p,0,R)
					//	f(q,0,C)
					//		v[p][q] = 'N';
					memset(v,'N',sizeof(v));
					//dfs2
					ans = dfs(maxi,maxj);
					if(ans>max)
						max = ans;
				}
				if(flag)
					break;
				//printf("%c",m[i][j]);
			}
			//printf("\n");
			if(flag)
				break;
		}
		if(max==0)
			max = 1;
		printf("Maximum rope length is %d.\n",max-1);
	}
	return 0;
}
