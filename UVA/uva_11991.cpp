#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef vector<int> VI;

int main(){
	int n, m, num, k, v;
	
	while(scanf("%d%d",&n,&m)==2){
		//VI AdjList[MAX];
		map<int, VI> AdjList;
		
		for(int i=0; i<n; i++){
			scanf("%d",&num);
			AdjList[num].push_back(i+1);
		}
		
		for(int i=0; i<m; i++){
			scanf("%d%d",&k,&v);
			if(AdjList[v].size()>=k){
				printf("%d\n",AdjList[v][k-1]);
			}else
				printf("0\n");
		}
	}
}
