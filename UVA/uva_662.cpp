#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#define MAX 250
using namespace std;

int arr[MAX], p[MAX], depot[MAX][MAX], dp[MAX][MAX];


int getcost(int a, int b){
	int ans = 100000;
	for(int i=a; i<=b; i++){
		int curr = 0;
		for(int j=a; j<=b; j++){
			curr += abs(arr[j]-arr[i]);
		}
		if(curr<ans){
			ans = curr;
			depot[a][b] = i;
		}
	}
	return ans;
}

int run(int a, int i){
	if(a==n) return dp[a][i]=0;
	if(i==k-1) return dp[a][i] = getcost(a,n-1);
	if(dp[a][i]!=-1) return dp[a][i];
	int ans = 100000;
	for(int b=a; b<n; b++){
		if(ans > getcost(a,b)
	}
}

int main(){
	int n, k;
	return 0;
}
