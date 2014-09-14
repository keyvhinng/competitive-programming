#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

#define MAX 10000000

typedef long long ll;
typedef pair<int,int> pii;


long long gcd(ll a, ll b){
	return (b==0 ? a : gcd(b, a%b));
}

long long lcm(ll a, ll b){
	return (a * (b/gcd(a,b)));
}

int main(){
	ll coin[51];
	int n, t;	
	ll lc, lc2, k, h, th, min, max;
	ll dismin, dismin2,dis,dis1, dis2;
	while((scanf("%d %d",&n,&t))&&(n+t!=0)){
		//read thickness
		for(int i=0; i<n; i++){
			scanf("%lld",&th);
			coin[i] =  th;
		}
		//get
		for(int m=0; m<t; m++){
			dismin = MAX;
			dismin2 = MAX;
			scanf("%lld",&h);
			int flag = 0;
			for(int i=0; i<n; i++){
				if(flag)
					break;
				for(int j=i+1; j<n; j++){
					if(flag)
						break;
					for(int k=j+1; k<n; k++){
						if(flag)
							break;
						for(int l=k+1; l<n; l++){
							if(flag)
								break;
							lc = lcm(coin[i],coin[j]);
							lc = lcm(lc,coin[k]);
							lc = lcm(lc,coin[l]);
						//	printf(" lc %lld\n",lc);
							dis = h % lc;
							if(dis!=0){
								dis1 = dis;
								dis2 = lc - dis;
								if(dis1<dismin){
									//least dif on left
									dismin = dis1;
								}
								if(dis2<dismin2){
									dismin2 = dis2;
								}
							}
							else{
								dismin = 0;
								dismin2 = 0;
								flag = 1;
							}
						}
					}
				} 
			}
			//printf("h %lld\n",h);
			//printf("a = %lld | b = %lld\n",a,b);
			printf("%lld %lld\n",h-dismin,h+dismin2);
		}
	}
	return 0;
}
