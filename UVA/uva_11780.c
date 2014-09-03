#include <iostream>
#include <stdio.h>
 
 
/*
  diff
  5 : 0.0
  3 : 0.2
  2 : 0.2
  1 : 0.4
  */
 
  int main (){
    int n;
    while (scanf("%d",&n) && n){
        n = n%5;
        switch (n){
            case 0:
				printf("0.00\n");
				break;
            case 1:
				printf("0.40\n");
				break;
            case 2:
				printf("0.20\n");
				break;
            case 3:
				printf("0.20\n");
				break;
            case 4:
				printf("0.40\n");
				break;
        }
 
    }
    return 0;
  }
