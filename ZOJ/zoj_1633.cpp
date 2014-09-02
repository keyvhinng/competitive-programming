#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

string str = "T.T^__^";

char run(long long n){
	if(n<=7) return str[n-1];
	long long a, b, aux;
	a = 3; b = 7;
	while(b<n){
		aux = b;
		b += a;
		a = aux;	
	}
	return run(n-a);
}

int main(){
	long long n;
	while(scanf("%lld",&n)==1){
		printf("%c\n",run(n));
	}
}