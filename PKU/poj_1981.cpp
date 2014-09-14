// POJ 1981
#include <cstdio>
#include <cmath>

using namespace std;

#define EPS 1e-6

struct PT{
	double x, y;
};

double dis(PT p1, PT p2){
	PT p3;
	p3.x = p2.x - p1.x;
	p3.x = p2.y - p1.y;
	return p3.x*p3.x + p3.y*p3.py;
}

PT find_centre(PT p1, PT p2){
	PT p3, mid, centre;
	double b, c, ang;
	p3.x = p2.x - p1.x;
	p3.y = p2.y - p1.y;
	mid.x = (p1.x + p2.x) / 2;
	mid.y = (p1.y + p2.y) / 2;
	b = dis(p1,mid);
	c = sqrt(1 - b);
	if(fabs(p3.y) < EPS){
		centre.x = mid.x;
		centre.y = mid.y + c;
	}
	else{
		ang = atan(-p3.x / p3.y);
		centre.x = mid.x + c*cos(ang);
		centre.y = mid.y + c*sin(ang);
	}
	return centre;
}

int main(){
	int n, ans, tmpans, i, j, k;
	PT p[305], centre;
	double tmp;
	while(scanf("%d",&n) && n){
		for(i=0; i<n; i++){
			scanf("%lf%lf",&p[i].x,&p[i].y);
		}
		ans = 1;
		for(i=0; i<n; i++){
			for(j=i+1; j<n; j++){
				if(dis(p[i],p[j])>4)
					continue;
				tmpans = 0;
				centre = find_centre(p[i],p[j]);
				for(k=0; k<n; k++){
					tmp = dis(centre, p[k]);
					if(tmp <= 1.000001) tmpans++;
				}
				if(ans < tmpans)
					ans = tmpans;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

