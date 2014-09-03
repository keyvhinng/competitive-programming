#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string.h>
#include <map>
#include <vector>

using namespace std;

int main(){
	double f;
	int total;
	int ncases;
	string s;
	map<string, int> m;
	map<string, int>::iterator it;
	cin>>ncases;
	getline(cin,s);
	getline(cin,s);
	for(int i=0; i<ncases; i++){
		m.clear();
		total = 0;
		while(getline(cin,s)){
			//cout<<s<<endl;
			if(s==""){
				break;
			}else{
				total++;
				if(!m.count(s)){
					m[s] = 1;
				}else{
					m[s] = m[s] + 1;
				}
			}
		}
		for(it=m.begin(); it!=m.end(); it++){
			f = it->second/(double)total;
			f *= 100;
			cout<<it->first;
			printf(" %.4lf\n",f);
		}
		if(i<ncases-1){
			printf("\n");
		}
	}
	return 0;
}
