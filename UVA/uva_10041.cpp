//UVA 10041
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

#define MAX 150000;
using namespace std;

int main(){
	int ncases, r, s, sum, summin;
	vector<int>v;
	scanf("%d",&ncases);
	while(ncases--){
		v.clear();
		scanf("%d",&r);
		for(int i=0; i<r; i++){
			scanf("%d",&s);
			v.push_back(s);
		}
		summin = MAX;
		for(int i=0; i<v.size(); i++){
			sum = 0;
			for(int j=0; j<v.size(); j++){
				sum += abs(v[j] - v[i]);
			}
			if(sum < summin)
				summin = sum;
		}
			printf("%d\n",summin);
	}
}
