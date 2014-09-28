#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <cctype>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

int main(){
	int n, acum0, acum1, indi, indj, ans, max, flag;
	int arr[101], aux0[101], aux1[101];
	scanf("%d",&n);
	acum0 = 0;
	acum1 = 0;
	aux0[0] = 0;
	aux1[0] = 0;
	for(int i=1; i<=n; i++){
		scanf("%d",&arr[i]);
		if(arr[i]==0) acum0++;
		else	acum1++;
		aux0[i] = acum0;
		aux1[i] = acum1;
	}
	max = 0;
	flag = 0;
	//printf("before %d\n",indj);
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			//printf("i j %d %d\n",i,j); 
			if(((aux0[j]-aux0[i-1])-(aux1[j]-aux1[i-1]))>max){
				flag = 1;
				max = (aux0[j]-aux0[i-1])-(aux1[j]-aux1[i-1]);
				indi = i;
		//		printf("indj = %d\n",j);
				indj = j;
			}
		}
	}
	//printf("after %d\n",indj);
	//printf("max %d\n",max);
	//printf("indi %d\n",indi);
	//printf("indj %d\n",indj);	
	if(flag){
		ans = 0;
		ans += aux1[indi-1];
		ans += aux0[indj] - aux0[indi-1];
		ans += aux1[n] - aux1[indj];
	}else
		ans = aux1[n] - 1;
	printf("%d",ans);
  	return 0;
}

