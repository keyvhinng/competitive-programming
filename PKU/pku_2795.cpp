#include <cstdio>
#include <cstring>

using namespace std;
const long long MOD = 1000000000;

long long f[310][310];
char s[310];

int main(){
	int n;
	scanf("%s",s);
	n = strlen(s);
	memset(f,0,sizeof(f));
	for(int i=0; i<n; i+=2){
		for(int j=0; j<n-i; j++){
			if(i==0){
				f[j][j]=1;
			}else{
				f[j][j+i]=0;
				for(int k=j+2; k<=j+i; k+=2){
					if(s[j]==s[k] && s[k]==s[j+i])
						f[j][j+i] = (f[j][j+i] + f[j+1][k-1]*f[k][j+i]) % MOD;
				}
			}
		}
	}
	printf("%lld\n",f[0][n-1]);
	return 0;
}
