#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <cmath>
#include <cassert>
#include <list>
#include <stack>
#include <bitset>
#include <functional>
#include <utility>
#include <sstream>
#include <cctype>
#include <ctime>

using namespace std;

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


typedef vector<int> VI;
typedef pair<int, int> II;
typedef vector<II> VII;


int main(){
	char c;
	int flag, I, start, l, r, sum, neg, num, t ;
	while(scanf("%d",&I)==1){
		stack<int> s;
		start = 0;
		char ant[3] = {0};
		l = r = 0;
		num = 0;
		sum = 0;
		neg = 0;
		flag = 0;
		while(!start || r!=l){
			scanf("%c",&c);
			switch(c){
				case '(':
					r++;
					if(start && ant[2]!=')'){
						if(neg) num *= -1;
						s.push(num);
						sum += num;
					}
					num = 0;
					neg = 0;
					ant[0] = ant[1];
					ant[1] = ant[2];
					ant[2] = c;
					start = 1;		
					break;			
				case ')':
					l++;
					if(ant[2]!='(' && s.size()){
						sum -= s.top();
						s.pop();
					}else if(ant[0]=='(' && ant[1]==')' && ant[2]=='(' && sum==I){
						flag = 1;
					}
					ant[0] = ant[1];
					ant[1] = ant[2];
					ant[2] = c;
					break;
				case ' ':
					break;
				case '\n':
					break;
				case '-':
					neg = 1;
					break;
				default:
					num *= 10;
					num += c - '0'; 
			}
		}
		if(flag) printf("yes\n");
		else     printf("no\n");
	}
	return 0;
}
