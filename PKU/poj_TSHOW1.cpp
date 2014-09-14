#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main(){
	int ncases, ind;
	long long int n, k, m;
	long long int bin[51], acum[51];
	//generate arrays
	k = 1;
	bin[0] = 1;
	acum[0] = 1;
	for(int i=1; i<51; i++){
		bin[i] = bin[i-1]*2;
		acum[i] = acum[i-1] + bin[i];
	}
	printf("%lld\n",acum[50]);
	printf("\n");
	//begin
	scanf("%d",&ncases);
	for(int i=0; i<ncases; i++){
		scanf("%lld",&n);
		ind = 0;
		while(n>=acum[ind])
			ind++;
		ind--;
		while(ind>=0){
			m = n - acum[ind];
			m = m / bin[ind];
			if (m%2==0){
				printf("5");
			}
			else
				printf("6");
			ind--;
		}
		printf("\n");
	}
	return 0;
}
