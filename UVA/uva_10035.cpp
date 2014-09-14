#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <utility>
#include <set>
#include <math.h>
using namespace std;

int main() 
{
	int res_a,res_b,x_a,y_b; 
    	unsigned  long long a,b;
    	int carreo=0;
    	int resto=0;
	int suma=0;
	int cont=0;
	while (cin >> a >> b ){
		if ( a+b ==0)
			break;
		cont=0;
		carreo=0;
		//cout <<carreo<<endl;
	       res_a=a;
	       res_b=b;
	       while ((res_a) || (res_b) ){
		   //cout <<carreo<<endl;
		   x_a= res_a % 10;
		   y_b= res_b % 10;
		   suma= x_a + y_b + carreo;
		   res_a = res_a / 10;
		   res_b = res_b /10;
		   
		  if (suma > 9){
		  	  carreo= suma /10;
			  cont++;
		  }
		  else
			  carreo = 0;
		   //cout <<carreo<<endl;
	   	}


		if (cont ==0) {
		    cout <<"No carry operation."<<endl;}
		    else  if (cont == 1){  cout << cont<<" carry operation."<<endl;}
			  else { cout << cont<<" carry operations."<<endl;}
	}
	return 0;

}

