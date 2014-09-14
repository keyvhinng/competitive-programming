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

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

int dx[] = {-2,-2,-1,-1, 1,1, 2,2};
int dy[] = {-1, 1,-2, 2,-2,2,-1,1};

struct node{
	int x;
	int y;
	int c;
	node(int _x, int _y, int _c){
		x = _x;
		y = _y;
		c = _c;
	}
};

int bfs(int x1, int y1, int x2, int y2){
	int x, y;
	queue<node> q;
	q.push(node(x1,y1,0));
	while(!q.empty()){
		node u = q.front();
		q.pop();
		if(u.x==x2 && u.y==y2)
			return u.c;
		for(int i=0; i<8; i++){
			x = u.x + dx[i];
			y = u.y + dy[i];
			if(x>=0 && x<8 && y>=0 && y<8)
				q.push(node(x,y,u.c+1));
		}
	}
}

int main(){
	int ans, x1, y1, x2, y2;
	string s1, s2;
	while(cin>>s1>>s2){
		x1 = s1[0] - 'a';
		y1 = s1[1] - '1';
		x2 = s2[0] - 'a';
		y2 = s2[1] - '1';
		ans = bfs(x1,y1,x2,y2);
		printf("To get from %c%c to %c%c takes %d knight moves.\n",s1[0],s1[1],s2[0],s2[1],ans);
	}
  	return 0;
}

