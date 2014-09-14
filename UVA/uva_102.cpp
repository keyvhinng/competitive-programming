//UVA 102
#include <cassert>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <numeric>
#include <sstream>
#include <cmath>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define f(i,x,y) for(int i = x; i<y; i++)
#define FOR(it,A) for(typeof A.begin(); it!=A.end(); it++)
#define quad(x) (x)*(x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second

typedef long long ll;
typedef pair<int, int> pii;

int main(){
	int b1b, b1g, b1c, b2b, b2g, b2c, b3b, b3g, b3c; 
	int arr[6], min, ind;
	string sarr[6];
	while(scanf("%d %d %d %d %d %d %d %d %d",&b1b, &b1g, &b1c, &b2b, &b2g, &b2c, &b3b, &b3g, &b3c)==9){
		//BCG
		arr[0] = b2b + b3b + b1c + b3c + b1g + b2g; 
		sarr[0] = "BCG";
		//BGC
		arr[1] = b2b + b3b + b1g + b3g + b1c + b2c; 
		sarr[1] = "BGC";
		//CBG
		arr[2] = b2c + b3c + b1b + b3b + b1g + b2g;
		sarr[2] = "CBG";
		//CGB
		arr[3] = b2c + b3c + b1g + b3g + b1b + b2b;
		sarr[3] = "CGB";
		//GBC
		arr[4] = b2g + b3g + b1b + b3b + b1c + b2c;
		sarr[4] = "GBC";
		//GCB
		arr[5] = b2g + b3g + b1c + b3c + b1b + b2b;
		sarr[5] = "GCB";
		//looking 
		min = arr[0];
		ind = 0;
		f(i,0,6){
			if(arr[i]<min){
				min = arr[i];
				ind = i;
			}
		}
		cout<<sarr[ind]<<" "<<min<<endl;
	}

	return 0;
}
