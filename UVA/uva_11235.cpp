//UVA 11235
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
typedef vector<int> vi;

vector<int> vFeq;
vector<int> stmid;
vector<int> stleft;
vector<int> stleftL;
vector<int> stRight;
vector<int> stRightL;
vector<int> stSize;

//Segment Tree
void st_build(vi &t, const vi &A, int vertex, int L, int R){
	if(L==R){
		
		t[vertex] = 1;
		stleft[vertex] = 1;
		stleftL[vertex] = vFeq[L];
		stRight[vertex] = 1;
		stRightL[vertex] = vFeq[R];
		stSize[vertex] = 1;
	}else{
		int max;
		int nL = 2 * vertex, nR = 2 * vertex + 1;
		st_build(t, A, nL, L         , (L+R)/2);
		st_build(t, A, nR, (L+R)/2+1 , R      );
		//maximum frequency
		int lrContent;
		if(stleftL[nR]>stRightL[nL]){
			lrContent = stRight[nL] + stleft[nR];
		}else{
			lrContent = 0;
		}
		int lContent = t[nL]       , rContent = t[nR];
		max = (lContent>=rContent) ? lContent : rContent;
		max = (max>=lrContent) ? max : lrContent;
		t[vertex] = max;
		//size
		stSize[vertex] = stSize[nL] + stSize[nR];
		//Left limit
		stleftL[vertex] = stleftL[nL];
		//Right limit
		stRightL[vertex] = stRightL[nR];
		//Left Size
		stleft[vertex] = stleft[nL];
		if(stleft[nL] == stSize[nL] && stleftL[nR]>stRightL[nL]){
			stleft[vertex] += stleft[nR];
		}
		//Right Size
		stRight[vertex] = stRight[nR];
		if(stRight[nR] == stSize[nR] && stleftL[nR]>stRightL[nL]){
			stRight[vertex] += stRight[nL];
		}

	}

}

void st_create(vi &t, const vi &A){
	int len = (int)(2*pow(2.0, floor((log((double)A.size())/log(2.0)) + 1)));
	t.assign(len, 0);
	stleft.assign(len, 0);
	stleftL.assign(len, 0);
	stRight.assign(len, 0);
	stRightL.assign(len, 0);
	stSize.assign(len, 0);
	st_build(t, A, 1, 0, (int)A.size()-1);
}

int st_rmq(vi &t, const vi &A, int vertex, int L, int R, int i, int j, int &left, 
		int &leftL, int &right, int &rightL, int &size){
	if(i>R || j<L) return -1;
	if(L >= i && R <= j){
		size   = stSize[vertex];
		left   = stleft[vertex];
		leftL  = stleftL[vertex];
		right  = stRight[vertex];
		rightL = stRightL[vertex];
		return t[vertex];
	}
	int left1, leftL1, right1, rightL1, size1;
	int left2, leftL2, right2, rightL2, size2;
	int p1 = st_rmq(t, A, 2 * vertex     , L           , (L+R)/2, i, j,
			left1, leftL1, right1, rightL1, size1);
	int p2 = st_rmq(t, A, 2 * vertex + 1 , (L+R)/2 + 1 , R      , i, j,
			left2, leftL2, right2, rightL2, size2);

	if(p1 == -1){
		size   = size2;
		left   = left2;
		leftL  = leftL2;
		right  = right2;
		rightL = rightL2;
		return p2;
	}
	if(p2 == -1){
		size   = size1;
		left   = left1;
		leftL  = leftL1;
		right  = right1;
		rightL = rightL1;
		return p1;
	}
	//maximum frequency
	int lrContent;
	if(leftL2>rightL1){
		lrContent = right1 + left2;
	}else{
		lrContent = 0;
	}
	int max;
	max = (p1>=p2) ? p1 : p2;
	max = (max>=lrContent) ? max : lrContent;
	//size
	size = size1 + size2;
	//Left limit
	leftL = leftL1;
	//Right limit
	rightL = rightL2;
	//Left Size
	left = left1;
	if(left1 == size1 && leftL2>rightL1){
		left += left2;
	}
	//Right Size
	right = right2;
	if(right2 == size2 && leftL2>rightL1){
		right += right1;
	}
	return max;
}

int st_rmq(vi &t, const vi& A, int i, int j){
	int left, leftL, right, rightL, size;
	return st_rmq(t, A, 1, 0, (int)A.size()-1, i, j,
			left, leftL, right, rightL, size);
}

int main(){
	int n, q, e, r, s, f;
	vector<int> A;
	while(scanf("%d",&n) && n){
		scanf("%d", &q);
		A.clear();
		vFeq.clear();
		f(i,0,n){
			scanf("%d",&e);
			A.pb(e);
		}
		f = 1;
		vFeq.pb(f);
		f(i,1,n){
			if(A[i]==A[i-1])
				f++;
			else
				f = 1;
			vFeq.pb(f);
		}
		st_create(stmid, A);
		f(i,0,q){
			scanf("%d %d", &r, &s);
			printf("%d\n", st_rmq(stmid, A, r-1, s-1));
		}
	}
	return 0;
}
