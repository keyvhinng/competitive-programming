//UVA 118 Mutant Flatworld Explorers
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

typedef long long ll;
typedef pair<int,int> pii;

int m[60][60], ms[60][60], dX, dY;
int mfx[4] = {0,-1,0,1};
int mfy[4] = {-1,0,1,0};
string ins;

void move(int posx, int posy, int dir, int s){
	//printf("----\n");
	//printf("start with %d %d\n",posx, posy);
	//cout<<"s  "<<s<<endl;
	//cout<<"dir "<<dir<<endl;
	int f = 0;
	string orien;
	if(ins[s]=='L'){
		if(dir!=0){
			dir -= 1;
		}else{
			dir = 3;
		}
	}else if(ins[s]=='R'){
		if(dir!=3){
			dir += 1; 
		}else{
			dir = 0;
		}
	}else{
		posx += mfx[dir];
		posy += mfy[dir];
	}
	//printf("posx: %d posy:%d\n",posx, posy);
	if(posx<0 || posx==dX || posy<0 || posy==dY){
		posx -= mfx[dir];
		posy -= mfy[dir];
		if(ms[posx][posy]==0){
			f = 1;
		}
		ms[posx][posy] = 1;
	}

	if(s==ins.size()-1 || f){
		switch(dir){
			case 0:
				orien = "S";
				break;
			case 1:
				orien = "W";
				break;
			case 2:
				orien = "N";
				break;
			case 3:
				orien = "E";
				break;
		}

		cout<<posx<<" "<<posy<<" "<<orien;
		if(f){
			cout<<" LOST";
		}
		cout<<endl;
	}else{
		if(!f)
			move(posx, posy, dir, s+1);
	}
	return;
}

int main(){
	int posx, posy, dir;
	string orien;
	//initialize matrix
	f(i,0,60){
		f(j,0,60){
			ms[i][j] = 0;
		}
	}
	cin>>dX>>dY;
	dX++;
	dY++;
	while(cin>>posx>>posy){
		//cout<<posx<<" "<<posy<<endl;
		cin>>orien;
		cin>>ins;
		if(orien=="S"){
			dir = 0;
			//cout<<"S"<<endl;
		}else if(orien=="W"){
			dir = 1;
			//cout<<"W"<<endl;
		}else if(orien=="N"){
			dir = 2;
			//cout<<"N"<<endl;
		}else{
			dir = 3;
			//cout<<"E"<<endl;
		}
		move(posx, posy,dir,0); 
	}

	return 0;
}
