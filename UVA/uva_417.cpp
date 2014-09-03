#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
	int cont, ini, temp, p;
    char c;
    string s, saux;
    map<string, int> m;
    vector<string> vs;
    cont = 1;
    c = 'a';
    s = "";               
    for(int i=0; i<26; i++){
    	c = i + 'a';
		s = "";
    	s = s + c;
    	vs.push_back(s);
		m[s] = cont;
		cont++;
    }
    ini = 0;
    int limit = 0;
    for(int i=0; i<4; i++){
    	temp = vs.size()-1;
    	for(int j=ini; j<=temp; j++){
    		p = vs[j][vs[j].size()-1]-'a';
    		for(int k=p+1; k<26; k++){
    			c = k + 'a';
				saux = "";
    			saux = saux + c;
    			s = vs[j] + saux;
    			vs.push_back(s);
				m[s] = cont;
    			cont++;
    		}     
    	}             	
		ini = temp + 1;
    }
    while(cin>>s){
    	if(m.count(s)){
    		printf("%d\n",m[s]);
    	}else{
    		printf("0\n");
    	}
    }
}
