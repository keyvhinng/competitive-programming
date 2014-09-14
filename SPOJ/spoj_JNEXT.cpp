#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
	vector<char> vc;
	char fs, r;
	int ncases, l, ind;
	char c;
	char s[1000002];
	scanf("%d",&ncases);
	while(ncases--){
		//read
		scanf("%d",&l);
		c = getchar();

		for(int i=0; i<l; i++){
			scanf("%c",&s[i]);
			scanf("%c",&c);
		}

		//for(int i=0; i<l; i++){
		//	printf("%c",s[i]);
		//}
		//printf("\n");

		//run
		ind = l-1;
		while((ind>=1) && (s[ind]<=s[ind-1])){
			ind--;
		}
		if(ind==0){
			printf("-1\n");
		}else{
			r = s[ind-1];
			fs = s[ind];
			for(int j = ind+1; j<l; j++){
				if((s[j]>r) && (s[j]<fs))
					fs = s[j];
			}
			for(int j=0; j<ind-1; j++)
				printf("%c",s[j]);
			printf("%c",fs);
			sort(s+ind-1,s+l);
			int flag = 0;
			for(int j=ind-1; j<l; j++){
				if(s[j]!=fs || flag){
					printf("%c",s[j]);
				}
				else{
					flag = 1;
				}
			}
			printf("\n");
		}
	}
	return 0;
}
