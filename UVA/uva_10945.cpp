#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int len, i , j, flag;
	string s;
	string done = "DONE";
	getline(cin,s);
	while(s.compare(done)!=0){
		//printf("analizando\n");
		flag = 0;
		len = s.size();
		//a minuscula
		for(int m=0; m<s.size(); m++){
			if(s[m]<91 && s[m]>64)
				s[m] += 'a' - 'A'; 
		}
		//cout<<s<<endl;

		i = 0;
		j = len - 1;

		while(s[i]>122 || s[i]<97){
			i++;
		}
		while(s[j]>122 || s[j]<97){
			j--;
		}
		while(j>i){
			if(s[i]!=s[j]){
				flag = 1;
				break;
			}else{
				i++;
				j--;
				while(s[i]>122 || s[i]<97){
					i++;
				}
				while(s[j]>122 || s[j]<97){
					j--;
				}
			}
		}
		if(flag){
			printf("Uh oh..\n");
		}
		else{
			printf("You won't be eaten!\n");
		}
		getline(cin,s);
	}
	return 0;
}
