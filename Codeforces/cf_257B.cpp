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
#define FORN(i,s,n) for(int i=s;i<(int)(n);i++)
#define REP(i,n) FORN(i,0,n)
#define FORIT(i,x) for( typeof x.begin()  i=x.begin(); i!=x.end(); i++ )
#define trace(x)    cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;

using namespace std;

#define MOD 1000000007
#define MAX_N 2

typedef long long int64;
typedef vector <int> vi;
typedef pair <int,int> ii;
typedef vector <string> vs;
typedef vector <ii> vii;

const int INF = 2e9+9;

struct Matrix{
	int64 mat[MAX_N][MAX_N];
};

Matrix matMul(Matrix a, Matrix b){
	Matrix ans;
	int i, j, k;
	for(i=0; i<MAX_N; i++)
		for(j=0; j<MAX_N; j++)
			for(ans.mat[i][j] = k = 0; k<MAX_N; k++){
				ans.mat[i][j] += (a.mat[i][k]%MOD) * (b.mat[k][j]%MOD);
				ans.mat[i][j] %= MOD;
			}
	return ans;
}

Matrix matPow(Matrix base, int p){
	Matrix ans;
	int i, j;
	for(i=0; i<MAX_N; i++)
		for(j=0; j<MAX_N; j++)
			ans.mat[i][j] = (i==j);
	while(p){
		if(p&1)
			ans = matMul(ans, base);
		base = matMul(base, base);
		p >>= 1;
	}
	return ans;
}

int main(){
	int x, y, n;
	scanf("%d%d%d",&x,&y,&n);
	Matrix ans, base;
	ans.mat[0][0] =  0; ans.mat[0][1] =  1;
	ans.mat[1][0] = -1; ans.mat[1][1] =  1;
	ans = matPow(ans,n-1);
	/*
	REP(i,2){
		REP(j,2)
			printf(" %lld",ans.mat[i][j]);
		printf("\n");
	}
	*/
	base.mat[0][0] = x; base.mat[0][1] = 0;
	base.mat[1][0] = y; base.mat[1][1] = 0;
	ans = matMul(ans,base);
	int64 resp = ans.mat[0][0]<0?ans.mat[0][0]+MOD:ans.mat[0][0];
	cout<<resp<<endl;
	return 0;
}


