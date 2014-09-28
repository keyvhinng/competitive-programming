#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
const double INF = 1e12;
const double EPS = 1e-9;
char s[110];
int n;

char ch[110];
int x[110], y[110];
vector<double> le, ri;

void check(double lx, double rx, double cx){
	vector< pair<double,int> > p;
	for(int i=0; i<n; i++){
		p.push_back(make_pair((x[i]-cx)/y[i],i));
	}
	sort(p.begin(),p.end());
	int flag=1;
	for(int i=0; i<n; i++)
		if(ch[p[i].second] != s[i]){
			flag=0;
			break;
		}
	if(flag){
		le.push_back(lx);
		ri.push_back(rx);
	}
}

int main(){
	char c;
	double r;
	scanf("%d",&n);
	scanf("%s\n",s);
	for(int i=0; i<n; i++)
		scanf("%c %d %d\n",&ch[i],&x[i],&y[i]);
	vector<double> arr;
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			if(y[i]!=y[j]){
				arr.push_back((x[j]*y[i]-x[i]*y[j])/(double)(y[i]-y[j]));
			}
	sort(arr.begin(),arr.end());
	double p;
	if(arr.size()){
		p = arr[0];
		check(-INF,p,p-1);
		for(int i=1; i<arr.size(); i++){
			r = arr[i];
			if(r-p>=EPS){
				check(p,r,(p+r)/2);
			}
			p = r;
		}
		check(p,+INF,p+1);
	}else{
		check(-INF,+INF,0);
	}
	printf("%d\n",(int)le.size());
	for(int i=0; i<le.size(); i++){
		if(i) printf(" ");
		if(le[i]==-INF)
			printf("*");
		else
			printf("%lf",le[i]);
		printf(" ");
		if(ri[i]==+INF)
			printf("*");
		else
			printf("%lf",ri[i]);
	}
	printf("\n");
	return 0;
}
