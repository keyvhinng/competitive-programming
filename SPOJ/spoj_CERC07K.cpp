#include <cstdio>
#include <cstdlib>

using namespace std;

int n, m;

int dist[100][100][10];
char g[100][100];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

int main(){
	while(scanf("%d%d",&n,&m) && (n+m)){
		for(int i=0; i<n; i++) scanf("%s",g[i]);
		for(int i=0; i<n; i++) for(int j=0; j<m; j++) for(int k=0; k<16; k++) dist[i][j][k]=-1;
	}
	return 0;
}
