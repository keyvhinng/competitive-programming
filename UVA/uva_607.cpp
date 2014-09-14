#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <cmath>
#include <algorithm>
#include <ctime>

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define f(i,x,y) for(int i=x; i<y; i++)
#define FOR(it,A) for(typeof A.begin(); it!=A.end(); it++)
#define quad(x) (x)*(x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second
#define INF 10000000

using namespace std;

int n, L, C, c=1;
int t[1001];
int d1[1001];
int d2[1001];
int di(int time) {
    return time==0?0:time<=10?-C:(time-10)*(time-10);
}

int main(){
	while (cin>>n&&n) {
        cin>>L>>C;
        if (c>1) {
            cout<<endl;
        }
        for (int i=1; i<=n; i++) {
            cin>>t[i];
            t[i]+=t[i-1];
        }
        memset(d1, -1, sizeof(d1));
        memset(d2, -1, sizeof(d2));
        d1[0]=0;
        d2[0]=0;
        for (int i=1; i<=n; i++) {
            for (int j=i-1; j>=0&&t[i]-t[j]<=L; j--) {
                int d=di(L-(t[i]-t[j]));
                if (d1[i]<0||d1[i]>d1[j]+1) {
                    d1[i]=d1[j]+1;
                    d2[i]=d2[j]+d;
                }
                if (d1[i]==d1[j]+1&&(d2[i]>d2[j]+d)) {
                    d2[i]=d2[j]+d;
                }
            }
        }
        cout<<"Case "<<c<<":"<<endl;
        cout<<"Minimum number of lectures: "<<d1[n]<<endl;
        cout<<"Total dissatisfaction index: "<<d2[n]<<endl;
        c++;
    }	
	return 0;
}

