#include <algorithm>
#include <bitset>
#include <deque>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define fst first
#define snd second
#define all(x) (x).begin(), (x).end()
#define clr(a, v) memset(a, v, sizeof(a))
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x.size())
#define REPN(i,s,n) for(int i=s;i<(int)(n);i++)
#define REP(i,n) REPN(i,0,n)
#define REPIT(i,x) for( typeof x.begin()  i=x.begin(); i!=x.end(); i++ )
#define trace(x)    cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;

using namespace std;

typedef long long int64;
typedef vector <int> vi;
typedef pair <int,int> ii;
typedef vector <string> vs;
typedef vector <ii> vii;

const int INF = 2e9+9;

#define MAX 32768 

const int M=32768;
char in[200000],op[200000];
unsigned char m[M];
int p;

int main()
{
		int ncases;
		scanf("%d ",&ncases);
		REP(cs,ncases){
				op[0]=0; int d=0;
				while(gets(in),in[0]!='e'){
								for(int i=0;in[i];i++){
											if(in[i]=='[')d++;
											if(in[i]==']')d--;
											if(in[i]=='%'){
														in[i]=0; break;
												}
									}
									strcat(op,in);
				}
				printf("PROGRAM #%d:\n",cs+1);
				if(d!=0){
							puts("COMPILE ERROR");
							continue;
				}
				p=0; REP(i,M) m[i]=0;
				for(int i=0;op[i];i++){
									if(op[i]=='>')p=(p+1)%M;
									if(op[i]=='<')p=(p+M-1)%M;
									if(op[i]=='+')m[p]++;
									if(op[i]=='-')m[p]--;
									if(op[i]=='.')putchar(m[p]);
									if(op[i]=='['&&m[p]==0){
											for(d=0;;i++){
													if(op[i]=='[')d++;
													if(op[i]==']')d--;
															if(d==0)break;
													}
											continue;
									}
									if(op[i]==']'&&m[p]){
											for(d=0;;i--){
													if(op[i]=='[')d--;
													if(op[i]==']')d++;
													if(d==0)break;
											}
										continue;
									}
					}
					puts("");
			}
			return 0;
}
