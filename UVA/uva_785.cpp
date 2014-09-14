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
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <cmath>
#include <algorithm>
#include <iomanip>
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
#define sz size

using namespace std;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
char b, mark;

vector<string> vs;

int dfs(int x, int y){
	int nx, ny;
	vs[x][y] = mark; 
	f(i,0,4){
		nx = x + dx[i];
		ny = y + dy[i];
		if(vs[nx][ny]==' '){
			dfs(nx,ny);
		}
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	string s, lin;
	char c;
	int flag;
	flag = 1;

	while(getline(cin,s)){
		vs.clear();
		while(1){
			if(s[0]=='_'){
				lin = s;
				break;
			}
			vs.pb(s);
			getline(cin,s);
		}
		flag = 1;
		for(int i=0; i<vs.size() && flag; i++){
			for(int j=0; j<vs[i].size() && flag; j++){
				if(vs[i][j]!=' '){
					b = vs[i][j];
					flag = 0;
				}
			}
		}
		f(i,0,vs.size()){
			f(j,0,vs[i].size()){
				c = vs[i][j];
				if(c!=b && c!=' '){
					mark = c;
					dfs(i,j);
				}
			}
		}
		f(i,0,vs.size()){
			f(j,0,vs[i].size())
				printf("%c",vs[i][j]);
			printf("\n");
		}
		cout<<lin<<endl;
	}
	return 0;
}

