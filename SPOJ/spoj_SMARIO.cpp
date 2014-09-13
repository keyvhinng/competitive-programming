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
#define REPN(i,s,n) for(int i=s;i<(int)(n);i++)
#define REP(i,n) REPN(i,0,n)
#define REPIT(i,x) for( typeof x.begin()  i=x.begin(); i!=x.end(); i++ )
#define trace(x)    cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;

using namespace std;

typedef long long int64;
typedef vector <int> vi;
typedef pair <int,int> ii;
typedef vector <string> vs;
typedef vector <ii> vii;

const int INF = 2e9+9;

int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
char g[9][15][15];
int dist[9][15][15][2050];

struct state{
	int x, y, z, mask;
	state(){}
	state(int _z, int _x, int _y, int _mask){
		x = _x;
		y = _y;
		z = _z;
		mask = _mask;
	}
};

int main(){
	char ch;
	int r, c, w, nx, ny, nz, nmask;
	while(scanf("%d%d%d",&r,&c,&w) && (r+c)){
		map<pair< pair<int,int>, int >, int > m;
		queue<state> q;
		int ncon = 0;
		REP(i,w) REP(j,r) REP(k,c) REP(l,2050) dist[i][j][k][l] = -1;
		REP(k,w)
			REP(i,r){
				scanf("%c",&ch);
				REP(j,c){
					scanf("%c",&g[k][i][j]);
					switch(g[k][i][j]){
						case 'S':{
							g[k][i][j] = '.';
							dist[k][i][j][0] = 0;
							state ns(k,i,j,0);
							q.push(ns);
							break;
						}
						case 'C':
							m[mp(mp(k,i),j)] = ncon++;
							break;
						default:
							break;
					}
				}
			}

		int ans = -1;
		state s;
		//trace(ncon);
		while(!q.empty()){
			s = q.front(); q.pop();
			//printf("analizo %d %d %d %d | dist %d\n",s.z,s.x,s.y,s.mask,dist[s.z][s.x][s.y][s.mask]);
			if(g[s.z][s.x][s.y]=='M'){
					if(s.mask == (1<<ncon)-1){
						ans = dist[s.z][s.x][s.y][s.mask]; break;
					}
			} 
			if(g[s.z][s.x][s.y]=='.' || g[s.z][s.x][s.y]=='C'){
				nmask = s.mask;
				if(g[s.z][s.x][s.y]=='C'){
					nmask |= ( 1 << (m[mp(mp(s.z,s.x),s.y)]) );
				}
				for(int i=0; i<4; i++){
					nx = s.x + dx[i];
					ny = s.y + dy[i];
					//printf("reviso %d %d %d\n",s.z,nx,ny);
					if(nx>=0 && nx<r && ny>=0 && ny<c && g[s.z][nx][ny]!='#'){
						if(dist[s.z][nx][ny][nmask]==-1){
							dist[s.z][nx][ny][nmask] = dist[s.z][s.x][s.y][s.mask] + 1;
							//printf("meto %d %d %d\n",s.z,nx,ny);
							q.push(state(s.z,nx,ny,nmask));
						}
					}
				}
			}else if(g[s.z][s.x][s.y]=='D' || g[s.z][s.x][s.y]=='U'){
				nz = g[s.z][s.x][s.y]=='D' ? nz = s.z + 1 : nz = s.z - 1;
				if(nz>=w || nz<0) continue;
				dist[nz][s.x][s.y][s.mask] = dist[s.z][s.x][s.y][s.mask];
				q.push(state(nz,s.x,s.y,s.mask));
			}		
		}
		if(ans==-1) printf("Mario failed to save princess\n");
		else printf("Mario saved the princess in %d steps\n",ans);
	}
	return 0;
}


