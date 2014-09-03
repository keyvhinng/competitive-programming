#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

struct Team{
	int res, pen, idx;
	int probs[11];
	bool corr[11];
	Team(){
		res = pen = idx = 0;
		memset(probs, 0, sizeof(probs));
		memset(corr, false, sizeof(corr));
	}
	void incress(int c, int p, int t, int l){
		idx = c;
		if(l=='C' && !corr[p]){
			res++;
			pen += t + 20*probs[p];
			corr[p] = 1;
		}else if(l=='I'){
			probs[p]++;
		}
	}
};

bool operator<(const Team &b, const Team &a){
	if(a.res!=b.res){
		return a.res < b.res;
	}
	else if(a.pen != b.pen){
		return b.pen < a.pen;
	}else{
		return b.idx < a.idx;
	}
}


int main(){
	char buff[100];
	string s;
	int ncases, c, p, t;
	char l;
	scanf("%d",&ncases);
	cin.ignore();
	cin.ignore();
	while(ncases--){
		Team teams[105];
		bool exist[105] = {0};
		while(getline(cin,s) && s!=""){
			istringstream is(s);
			is>>c>>p>>t>>l;
			//cout<<c<<" "<<p<<" "<<t<<" "<<l<<endl;
			if(!exist[c]){
				teams[c] = Team();
				exist[c] = 1;
			}
			teams[c].incress(c,p,t,l);
		}
		sort(teams, teams+105);
		for(int i=0; i<105; i++){
			if(teams[i].idx){
				printf("%d %d %d\n",teams[i].idx, teams[i].res, teams[i].pen);
			}
		}
		if(ncases) cout<<endl;
	}
}
