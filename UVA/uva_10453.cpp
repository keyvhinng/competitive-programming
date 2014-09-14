#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <utility>
#include <sstream>
using namespace std;
 
int dp[1000][1000];
int dp2[1000][1000];
char s[1005];
//string s;
 
int run(int i, int j){
	//cout << "i: "<<i<< " j: "<<j<<endl;
	if(i>=j) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	if(s[i]==s[j]) dp[i][j] = run(i+1, j-1), dp2[i][j]=0;
	else if(run(i+1,j)<=run(i,j-1)) dp[i][j]=1+run(i+1,j), dp2[i][j]=1;
	else dp[i][j] = 1+run(i,j-1), dp2[i][j]=-1;
	return dp[i][j];
}

void print(int i, int j){
	if(i>j) return;
	if(i==j) printf("%c",s[i]);
	else if(dp2[i][j]==0)  printf("%c",s[i]), print(i+1,j-1), printf("%c",s[i]);
	else if(dp2[i][j]==1)  printf("%c",s[i]), print(i+1,j  ), printf("%c",s[i]);
	else if(dp2[i][j]==-1) printf("%c",s[j]), print(i,  j-1), printf("%c",s[j]);
}
 
int main(){
	int len, i, j;
	while(scanf("%s",s)!=EOF){
		len = strlen(s);
		for(i=0; i<len; i++){
				for(j=0; j<len; j++) dp[i][j] = -1;
		}
		printf("%d ",run(0,len-1));
		print(0,len-1);
		printf("\n");
	}
}

