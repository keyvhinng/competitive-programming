//POJ 4580 ABCDEF
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

int main(){
	int arr[100], ans1[1000010], ans2[1000010];
	int n, u, cont, r, x, y, cont1, cont2, siz1, siz2;
	scanf("%d",&n);
	f(i,0,n){
		scanf("%d",&arr[i]);
	}
	//print readed array
	//f(i,0,n){
	//	printf("%d ",arr[i]);
	//}
	//printf("\n");
	siz1 = 0;
	//a*b+c
	f(i,0,n){
		f(j,0,n){
			f(k,0,n){
				ans1[siz1] = arr[i]*arr[j]+arr[k];
				siz1++;
			}
		}
	}

	
	//(f+e)*d
	siz2 = 0;
	f(i,0,n){
		f(j,0,n){
			f(k,0,n){
				if(arr[i]==0)
					continue;
				ans2[siz2] = arr[i]*(arr[j]+arr[k]);
				siz2++;
			}
		}
	}
	
	//counting
	sort(ans1,ans1+siz1);
	sort(ans2,ans2+siz2);

	//cout<<"ans1"<<endl;
	//f(i,0,siz1){
	//	printf("%d ",ans1[i]);
	//}
	//printf("\n");

	//cout<<"ans2"<<endl;
	//f(i,0,siz2){
	//	printf("%d ",ans2[i]);
	//}
	//printf("\n");

	r = 0;
	x = 0;
	y = 0;
	cont1 = 0;
	cont2 = 0;
	while(x<siz1){
		while( x<siz1-1 && ans1[x]==ans1[x+1]){
			cont1++;
			x++;
		}
		cont1++;
		while( y<siz2 && ans2[y]<ans1[x]){
			y++;
		}

		if(y<siz2 && (ans2[y]==ans1[x])){
			//cout<<"tenemos "<<ans2[y]<<" con "<<ans1[x]<<endl;
			while(ans2[y]==ans1[x]){
				y++;
				cont2++;
			}
		}
		//if(cont1*cont2!=0){
		//	cout<<"cont1 "<<cont1<<endl;
		//	cout<<"cont2 "<<cont2<<endl;
		//}
		r += cont1*cont2;
		x++;
		cont1 = 0;
		cont2 = 0;

	}
	printf("%d",r);
	return 0;
}
