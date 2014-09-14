#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <cctype>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <bitset>

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> II;
typedef vector<II> VII;

char grid[30][30][30];
int dist[30][30][30];

int dx[] = {0, 0,-1, 0, 1, 0};
int dy[] = {0, 0, 0, 1, 0,-1};
int dz[] = {1,-1, 0, 0, 0, 0};
int L, R, C;

struct Point{
	int x, y, z, d;
	Point(){}
	
	Point(int _x, int _y, int _z, int _d){
		x = _x;
		y = _y;
		z = _z;
		d = _d;
	}
};

int isIn(Point p){
	if(p.x>=0 && p.x<R && p.y>=0 && p.y<C && p.z>=0 && p.z<L){
		return 1;
	}
	return 0;
}

int isFree(Point p){
	if(grid[p.x][p.y][p.z]!='#')
		return 1;
	return 0;
}

void bfs(int si, int sj, int sk){
	Point s(si, sj, sk, 0);
	Point u, v;
	queue<Point> q;
	q.push(s);
	dist[si][sj][sk] = 0;
	while(!q.empty()){
		u = q.front();
		q.pop();
		for(int j=0; j<6; j++){
			v.x = u.x + dx[j];
			v.y = u.y + dy[j];
			v.z = u.z + dz[j];
			if(isIn(v) && isFree(v)){
				if(dist[v.x][v.y][v.z]==-1){
					dist[v.x][v.y][v.z] = u.d + 1;
					v.d = u.d + 1;
					q.push(v);
				}
			}
		}
	}
	return;
}

int main(){
	int si, sj, sk, di, dj, dk;
	char c;
	while(scanf("%d %d %d",&L, &R, &C) && (L+R+C!=0)){
		for(int k=0; k<L; k++){
			scanf("%c",&c);
			for(int i=0; i<R; i++){
				for(int j=0; j<C; j++){
					dist[i][j][k] = -1; //initialize
					scanf("%c",&grid[i][j][k]);
					if(grid[i][j][k]=='S'){
						si = i;
						sj = j;
						sk = k;
					}
					if(grid[i][j][k]=='E'){
						di = i;
						dj = j;
						dk = k;
					}
				}
				scanf("%c",&c);
			}
			
		}
	
		//work
		bfs(si, sj, sk);
		//print
		/*
		for(int i=0; i<R; i++){
			for(int j=0; j<C; j++){
				printf("%2.d ",dist[i][j][1]);
			}
			printf("\n");
		}
		*/
		if(dist[di][dj][dk]!=-1){
			printf("Escaped in %d minute(s).\n",dist[di][dj][dk]);
		}else
			printf("Trapped!\n");
		
	}
  	return 0;
}

