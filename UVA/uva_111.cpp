//UVA 111 History Grading
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

using namespace std;

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

typedef long long ll;
typedef pair<int,int> pii;

int map_s[25], dp[25], mp_ans[25];
int n;

int solve(int i){
	int s;
	if(dp[i]!=-1)
		return dp[i];
	int maxl = 1;
	for(int r=i+1; r<=n; r++){
		if(mp_ans[i]<mp_ans[r]){
			s = 1 + solve(r);
			if(s>maxl){
				maxl = s;
			}
		}
	}
	return dp[i] = maxl;
}

int main(){
	int arr[25], arr2[25], n1, num, ans[25], ans2[25];
	int max_ans;
	scanf("%d",&n);
	f(i,1,n+1){
		scanf("%d",&arr2[i]);
	}
	//arrange acording ranks
	f(i,1,n+1){
		arr[arr2[i]] = i;
	}
//	cout<<"arr original"<<endl;
//	f(i,1,n+1){
//		cout<<arr[i]<<" ";
//	}
//	cout<<endl;
	//map original array
	f(i,1,n+1){
		map_s[arr[i]] = i; 
	}
	while((scanf("%d",&ans2[1]))==1){
		max_ans = 0;
		f(i,2,n+1){
			scanf("%d",&ans2[i]);
		}
		//arrange acording ranks
		f(i,1,n+1){
			ans[ans2[i]] = i;
		}
		f(i,1,n+1)
			mp_ans[i] = map_s[ans[i]];
		//initialize dp array
		f(i,1,n+1){
			dp[i] = -1;
		}
		//print
//		cout<<"mapping of answers"<<endl;
//		f(i,1,n+1){
//			cout<<mp_ans[i]<<" ";
//		}
//		cout<<endl;
		f(i,1,n+1){
			solve(i);
			//printf("solve(%d) is %d\n",i,solve(i));
			if(dp[i]>max_ans)
				max_ans = dp[i];
		}
		printf("%d\n",max_ans);
	}
	return 0;
}
