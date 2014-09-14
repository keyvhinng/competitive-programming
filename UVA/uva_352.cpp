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
#include <cctype>
#include <ctime>

using namespace std;

#define pb push_back
#define f(i,x,y) for(int i=x; i<y; i++)

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

int R, C;
char grid[25][25];
int dr[] = {1,1,0,-1,-1,-1, 0, 1};
int dc[] = {0,1,1, 1, 0,-1,-1,-1};

void floodfill(int r, int c, char c1, char c2){
	if(r < 0 || r>=R || c < 0 || c>=C) return;
	if(grid[r][c] != c1) return;
	grid[r][c] = c2;
	for(int i=0; i<8; i++){
		floodfill(r + dr[i], c + dc[i], c1, c2);
	}
	return;
}

int main(){
	int img, n, ans;
	char c;
	img = 0;
	while(scanf("%d",&n)==1){
		img++;
		R = n;
		C = n;
		//read
		scanf("%c",&c);
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++)
				scanf("%c",&grid[i][j]);
			scanf("%c",&c);	
		}
		//print
		/*
		f(i,0,n){
			f(j,0,n)
				printf("%c",grid[i][j]);
			printf("\n");
		}
		*/
		//work
		ans = 0;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(grid[i][j]=='1'){
					ans++;
					floodfill(i,j,'1','0');
				}
		//print
		printf("Image number %d contains %d war eagles.\n",img,ans);
	}		
	return 0;
}
