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

typedef vector<int> VI;


int V, E;
vector<VI> AdjList;
int in[100];
int visited[100];

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int nc, v, u;
	string s, sa, sb;
	map<string,int> m1;
	map<int,string> m2;
	nc = 0;
	while(scanf("%d",&V)==1){
		AdjList.assign(V,VI());
		memset(visited,0,sizeof(visited));
		memset(in,0,sizeof(in));
		m1.clear(); m2.clear();
		f(i,0,V){
			cin>>s;	
			m1[s] = V-(i+1);
			m2[V-(i+1)] = s;
		}
		scanf("%d",&E);
		f(i,0,E){
			cin>>sa>>sb;
			AdjList[m1[sa]].pb(m1[sb]);
			in[m1[sb]]++;
		}

		printf("Case #%d: Dilbert should drink beverages in this order:",++nc);
		//bfs begin
		priority_queue<int> pq; 
		f(i,0,V) if(!in[i]){
		   	pq.push(i);
		}
		while(!pq.empty()){
			u = pq.top();
			pq.pop();
			cout<<" "<<m2[u];
			f(j,0,AdjList[u].size()){
				v = AdjList[u][j];
				in[v]--;
				if(!visited[v] && in[v]==0){ 
					visited[v] = 1;
					pq.push(v);
				}
			}
		}
		//bfs end
		printf(".\n");
		printf("\n");
	}
	return 0;
}

