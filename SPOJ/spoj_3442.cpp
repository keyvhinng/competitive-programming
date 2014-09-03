#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;
int main(){
	string ar[10];
	int arr[10][10], arrt[10];
	ar[1] = "11";
	arrt[1] = 1;
	ar[2] = "6248";
	arrt[2] = 4;
	ar[3] = "1397";
	arrt[3] = 4;
	ar[4] = "64";
	arrt[4] = 2;
	ar[5] = "55";
	arrt[5] = 1;
	ar[6] = "66";
	arrt[6] = 1;
	ar[7] = "1793";
	arrt[7] = 4;
	ar[8] = "6842";
	arrt[8] = 4;
	ar[9] = "19";
	arrt[9] = 2;
	int t, a, b, cont;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&a, &b);
		a = a%10;
		if(a==0)
			printf("0\n");
		else if(b==0){
			printf("1\n");
		}
		else
			printf("%c\n",ar[a][(b%arrt[a])]);
	}
	return 0;
}
