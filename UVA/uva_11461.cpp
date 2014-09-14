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
#include <bitset>

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

VI sq;

void generate(){
	int n;
	n = 1;
	while(n*n<=100000){
		sq.push_back(n*n);
		n++;
	}
}

void print(){
	for(int i=0; i<sq.size(); i++){
		printf("%d\n",sq[i]);
	}
}

int main(){
	int a, b, ans;
	generate();
	vector<int>::iterator low, up;
	while(scanf("%d %d",&a, &b) && (a+b!=0)){
		low = lower_bound(sq.begin(), sq.end(), a);
		up =  upper_bound(sq.begin(), sq.end(), b);
		ans = up - low;	
		printf("%d\n",ans);
	}
  	return 0;
}

