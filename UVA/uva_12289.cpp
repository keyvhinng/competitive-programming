#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(){
	string s;
	int n;
	scanf("%d",&n);
	while(n--){
		cin>>s;
		if(s.size()==5)
			printf("3\n");
		else if(s[0]=='o' || s[1]=='n')
			printf("1\n");
		else	printf("2\n");	
	}
	return 0;
}
