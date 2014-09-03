#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int n, i, j, k, l, maximo, curr;
	scanf("%d",&n);
	int m[100][100], acum[100][100];

	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			scanf("%d",&m[i][j]);


	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			acum[i][j] = m[i][j];
			if(i>0) acum[i][j] += acum[i-1][j];
			if(j>0) acum[i][j] += acum[i][j-1];
			if(i>0 && j>0) acum[i][j] -= acum[i-1][j-1];
		}
	}

	maximo = 0;
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			for(k=i; k<n; k++)
				for(l=j; l<n; l++){
					curr = acum[k][l];
					if(i>0) curr -= acum[i-1][l];
					if(j>0) curr -= acum[k][j-1];
					if(i>0 && j>0) curr += acum[i-1][j-1];
					if(maximo<curr) maximo = curr;
				}
	printf("%d\n",maximo);
	return 0;
}
