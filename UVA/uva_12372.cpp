#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
	int ncases, l, w, h;
	scanf("%d",&ncases);
	for(int i=1; i<=ncases; i++){
		scanf("%d%d%d",&l,&w,&h);
		printf("Case %d: ",i);
		if(l<=20 && w<=20 && h<=20)
			printf("good\n");
		else    printf("bad\n");
	}
	return 0;
}
