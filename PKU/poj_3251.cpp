#include <cassert>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <numeric>
#include <sstream>
#include <cmath>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define f(i,x,y) for(int i = x; i<y; i++)
#define FOR(it,A) for(typeof A.begin(); it!=A.end(); it++)
#define quad(x) (x)*(x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second


typedef long long ll;
typedef pair<int, int> pii;

struct Node{
	int w,h;

	Node(){
	}

	Node(int wi,int hi){
	w=wi,h=hi;
	}

};

std::vector<Node> rect[9802];
char cheb[100][101];
int N;

bool check(int x,int y,int r){
	int ri,di,gx,gy;
	int rin=rect[r].size();
	for (ri=0;ri<rin;ri++){
		int w=rect[r][ri].w;
		int h=rect[r][ri].h;
		int J=0;
		int tot[4][2];
		tot[0][0]=0;
		tot[0][1]=0;
		tot[1][0]=w;
		tot[1][1]=h;
		//caseA:(+1,+3) w<=h clockwise
		if (w<=h){
			tot[2][0]=h+w;
			tot[2][1]=h-w;
			tot[3][0]=h;
			tot[3][1]=-w;
		}
		
		//caseB:(+3,+1) w>h
		if (w>h){
			tot[2][0]=w-h;
			tot[2][1]=w+h;
			tot[3][0]=-h;
			tot[3][1]=w;
		}
		
		//printf("running(%d,%d)+(%d,%d)=(%d,%d)\n",x,y,w,h,x+w,y+h);
		
		for (di=3;di>=0;di--){
			gx=x+tot[di][0];
			gy=y+tot[di][1];
			if (gx<0 || gy<0 || gx>=N || gy>=N)break;
			if (cheb[gx][gy]=='B')break;
			if (cheb[gx][gy]=='J')J++;
			else if (di+J<3)break;
			//printf("testcase[%d](%d,%d) J=%d\n",di,gx,gy,J);
		}
		if (di==-1 && J>=3)return true;
	}
	return false;
}
void algorithm2(){
	int i,j,n,ans=0;
	std::vector<Node> Q;
	for (i=0;i<N;i++)
		for (j=0;j<N;j++)
			if (cheb[i][j]=='J')
				Q.push_back(Node(i,j));
	n=Q.size();
	for (i=0;i<n;i++)
		for (j=i+1;j<n;j++){
			int x=Q[i].w,y=Q[i].h,p=Q[j].w,q=Q[j].h,dist,a,b;
			Node A,B;
			#define SQ(x) ((x)*(x))
			#define ABS(x) ((x)<0?(-(x)):(x))
			dist=SQ(x-p)+SQ(y-q);
			if (ans >= dist)continue;
			a=p-x;
			b=q-y;
			if ((a+b)%2)continue;
			A=Node(x+(a+b)/2,y+(b-a)/2);
			B=Node(x+(a-b)/2,y+(a+b)/2);
			//printf("use(%d,%d)(%d,%d) to check(%d,%d)(%d,%d) <dist=%d/2>\n",x,y,p,q,A.w,A.h,B.w,B.h,dist);
			if (A.w<0 || A.h<0 || B.w<0 || B.h<0 || A.w>=N || A.h>=N || B.w>=N || B.h>=N)continue;
			if (cheb[A.w][A.h]=='B')continue;
			if (cheb[B.w][B.h]=='B')continue;
			if (cheb[A.w][A.h]=='*' && cheb[B.w][B.h]=='*')continue;
			ans=dist;
		}
	printf("%d\n",ans/2);
}
int main(){
	/*
	#ifdef JACK1_NOTEBOOK
	freopen("pku3251_in.txt","r",stdin);
	freopen("pku3251_out.h","w",stdout);
	#endif
	*/
	int N2,i,j,k,ans=0,w,h,J=0;

	scanf("%d",&N);
	N2=(N-1)*(N-1);

	for (i=0;i<N;i++){
		scanf("%s",cheb[i]);
		for (j=0;j<N;j++)
			if (cheb[i][j]=='J')J++;
	}

	if (J<N2/2){
		algorithm2();
		return 0;
	}

	for (i=0;i<N;i++)
		for (j=0;i*i+j*j<=N2;j++)
			rect[i*i+j*j].push_back(Node(i,j));
	
	for (k=N2;k>0;k--)
		for (i=0,w=N-1;i<N;i++,w--)
			for (j=0,h=N-1;j<N;j++,h--){
				if (w*h<k)break;
				if (cheb[i][j]=='B')continue;
				if (check(i,j,k)){
					ans=k;
					goto OUTPUT;
				}
			}
	
	for (i=0,w=N-1;i<N;i++,w--)
		for (j=0,h=N-1;j<N;j++,h--){
			//cuts
			if (cheb[i][j]=='B')continue;
			
			//check if left-up(i,j) forms area(k) squares
			for (k=w*h; k>ans; k--)
				if (check(i,j,k)){
					//printf("got area(%d,%d) size(%d ^ 2)\n",i,j,k);
					ans = k;
					break;
				}
		}
	
	OUTPUT:
	printf("%d\n",ans);
}
