#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <ctime>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define f(i,x,y) for(int i=x; i<y; i++)
#define FOR(it, A) for(typeof A.begin() it = A.begin(), it!=A.end(); it++)
#define quad(x) (x)*(x)
#define mp make_pair
#define clr(x,y) memset(x, y, sizeof x)
#define fst first
#define snd second

typedef pair<int, int>II;
typedef long long LL;
typedef long double LD;

int main(void){
	int arr1[30000], arr2[30000];
	int ind2, ncases, m, n;
	scanf("%d",&ncases);
	multiset<int> multi;
	multiset<int>::iterator it;
	for(int k=0; k<ncases; k++){
		multi.clear();
		scanf("%d%d",&m,&n);
		for(int i=0; i<m; i++){
			scanf("%d",&arr1[i]);
		}
		for(int i=0; i<n; i++){
			scanf("%d",&arr2[i]);
		}
		ind2 = 0;
		for(int i=0; i<m; i++){
			multi.insert(arr1[i]);
			if(i!=0){
				if(*it>arr1[i]){
					it--;
				}
			}
			while(ind2<n && arr2[ind2]==i+1){
				if(ind2==0){
					it = multi.begin();
				}else{
					it++;
				}
				printf("%d\n",*it);
				ind2++;
			}
		}
		if(k<ncases-1){
			printf("\n");
		}
	}
	return 0;
}
