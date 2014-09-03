#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

vector< pair< int, int> > solve(long long n){
	vector< pair<int,int> > ret;
	if(n==1){
		ret.push_back(make_pair(0,0));
		return ret;	
	}
	int a=0, b=0;
	while(n%2==0){
		n/=2;
		a++;
	}
	while(n%3==0){
		n/=3;
		b++;
	}
	if(n==1){
		ret.push_back(make_pair(a,b));
		return ret;
	}
	
	long long t=1;
	int tb=0;
	while(t*3<=n){
		++tb;
		t *= 3;
	}
	ret.push_back(make_pair(a,b+tb));
	vector<pair<int, int> > tmp = solve(n-t);
	for(int i=0; i<(int)tmp.size(); i++) 
		ret.push_back(make_pair(tmp[i].first+a,tmp[i].second+b));
	return ret;	
}

int main(){
	int ncases;
	long long n;
	scanf("%d",&ncases);
	for(int i=1; i<=ncases; i++){
		printf("%d",i);
		scanf("%lld",&n);
		vector<pair<int,int> > ans = solve(n);
		printf(" %d",(int)ans.size());
		for(int j=0; j<(int)ans.size(); j++){
			printf(" [%d,%d]",ans[j].first,ans[j].second);
		}
		printf("\n");
	}
	return 0;
}