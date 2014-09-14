#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(){
	double arr[101];
	int cont, m, nd, nm;
	double owed, p,  dp, loan, worth, pay; 
	while(scanf("%d %lf %lf %d",&m, &dp, &loan, &nd)){
		if(m<0) break;
		for(int i=0; i<nd; i++){
			scanf("%d %lf",&nm, &p);
			for(int j=nm; j<101; j++){
				arr[j] = p;	
			}
		}	
		cont = 0;
		pay = loan / m;
		worth = (loan+dp)*(1.0 - arr[0]);
		owed  = loan;
		while(worth<owed){
			cont++;
			worth = worth*(1.0 - arr[cont]);
			owed = owed - pay; 
		}
		printf("%d month",cont);
		if(cont!=1)
			printf("s");
		printf("\n");
	}
	return 0;
}
