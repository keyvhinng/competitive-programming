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

int n, arr[100010], arr2[100010];

int main(){
	int flag=1;
	int i, j, aux, a, b;
	scanf("%d",&n);
	REP(i,n){
		scanf("%d",&arr[i]);
		arr2[i] = arr[i];
	}
	sort(arr2,arr2+n);
	i = 0;
	while(arr[i]==arr2[i] && i<n) i++;
	j = n-1;
	while(arr[j]==arr2[j] && j>=0) j--;
	a = i+1;
	b = j+1;
	if(i!=n){
		/*
		printf("p \n");
		REP(i,n)
			printf(" %d",arr[i]);
		printf("\n");
		*/
		while(i<j){
			swap(arr[i],arr[j]);
			i++; j--;
		}
		/*
		printf("a \n");
		REP(i,n)
			printf(" %d",arr[i]);
		printf("\n");
		*/
		REP(i,n){
			if(arr[i]!=arr2[i]) flag=0;
		}
	}else{
		a = 1; b = 1;
	}
	if(flag){
		printf("yes\n");
		printf("%d %d\n",a,b);
	}
	else printf("no\n");
	return 0;
}


