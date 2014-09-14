#include <cassert>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <numeric>
#include <sstream>
#include <cmath>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define f(i,x,y) for(int i = x; i<y; i++)
#define FOR(it,A) for(typeof A.begin(); it!=A.end(); it++)
#define quad(x) (x)*(x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second

typedef long long ll;
typedef pair<int, int> pii;

//POJ 2136
int main(){
	char s[250];
	int arr[26], max, cont;

	f(i,0,26){
		arr[i] = 0;
	}

	f(i,0,4){
		gets(s);
		f(j,0,strlen(s)){
			if(s[j]>=65 && s[j]<=90)
				arr[s[j]-65]++;
		}
	//	printf("%s\n",s);
	}
	max = 0;
	
	f(i,0,26){
		if (arr[i] > max)
			max = arr[i];
	//	printf("%d ",arr[i]);;
	}
	//printf("\n%d\n",max);
	cont = max;
	f(i,0,max){
		f(j,0,26){
			if(arr[j]>=cont){
				printf("*");
		//		cout<<endl<<arr[j]<<" >= "<<cont<<endl;
			}
			else{
				printf(" ");
			}
			if(j!=25)
				printf(" ");
		}
		cont--;
		printf("\n");
	}
	f(i,0,26){
		printf("%c",i+65);
		if(i!=25)
			printf(" ");
	}
	return 0;
}
