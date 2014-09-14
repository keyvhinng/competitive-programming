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

typedef long long ll;
typedef pair<int,int> pii;

char m[8][8];

int check_knight(int i,int j,int p){
	int ni, nj;
	if(p==0){
		//check k
		//N..
		//..k
		ni = i-1;
		nj = j-2;
		if((ni>=0) && (ni<8) && (nj>=0) && (nj<8)){
			if(m[ni][nj]=='N'){
				return 1;
			}
		}
		ni = i-1;
		nj = j+2;
		if((ni>=0) && (ni<8) && (nj>=0) && (nj<8)){
			if(m[ni][nj]=='N'){
				return 1;
			}
		}
		ni = i-2;
		nj = j-1;
		if((ni>=0) && (ni<8) && (nj>=0) && (nj<8)){
			if(m[ni][nj]=='N'){
				return 1;
			}
		}
		ni = i-2;
		nj = j+1;
		if((ni>=0) && (ni<8) && (nj>=0) && (nj<8)){
			if(m[ni][nj]=='N'){
				return 1;
			}
		}
		ni = i+1;
		nj = j-2;
		if((ni>=0) && (ni<8) && (nj>=0) && (nj<8)){
			if(m[ni][nj]=='N'){
				return 1;
			}
		}
		ni = i+1;
		nj = j+2;
		if((ni>=0) && (ni<8) && (nj>=0) && (nj<8)){
			if(m[ni][nj]=='N'){
				return 1;
			}
		}
		ni = i+2;
		nj = j-1;
		if((ni>=0) && (ni<8) && (nj>=0) && (nj<8)){
			if(m[ni][nj]=='N'){
				return 1;
			}
		}
		ni = i+2;
		nj = j+1;
		if((ni>=0) && (ni<8) && (nj>=0) && (nj<8)){
			if(m[ni][nj]=='N'){
				return 1;
			}
		}
		return 0;
	}else{
		//check K
		ni = i-1;
		nj = j-2;
		if((ni>=0) && (ni<8) && (nj>=0) && (nj<8)){
			if(m[ni][nj]=='n'){
				return 1;
			}
		}
		ni = i-1;
		nj = j+2;
		if((ni>=0) && (ni<8) && (nj>=0) && (nj<8)){
			if(m[ni][nj]=='n'){
				return 1;
			}
		}
		ni = i-2;
		nj = j-1;
		if((ni>=0) && (ni<8) && (nj>=0) && (nj<8)){
			if(m[ni][nj]=='n'){
				return 1;
			}
		}
		ni = i-2;
		nj = j+1;
		if((ni>=0) && (ni<8) && (nj>=0) && (nj<8)){
			if(m[ni][nj]=='n'){
				return 1;
			}
		}
		ni = i+1;
		nj = j-2;
		if((ni>=0) && (ni<8) && (nj>=0) && (nj<8)){
			if(m[ni][nj]=='n'){
				return 1;
			}
		}
		ni = i+1;
		nj = j+2;
		if((ni>=0) && (ni<8) && (nj>=0) && (nj<8)){
			if(m[ni][nj]=='n'){
				return 1;
			}
		}
		ni = i+2;
		nj = j-1;
		if((ni>=0) && (ni<8) && (nj>=0) && (nj<8)){
			if(m[ni][nj]=='n'){
				return 1;
			}
		}
		ni = i+2;
		nj = j+1;
		if((ni>=0) && (ni<8) && (nj>=0) && (nj<8)){
			if(m[ni][nj]=='n'){
				return 1;
			}
		}
		return 0;
	}	
}

int check_queen(int i,int j,int p){
	int ni, nj;
	int r;
	if(p==0){
		//*check k*
		//check left side
		r = j-1;
		while(r>0 && m[i][r]=='.'){
			r--;
		}
		if(r>=0 && m[i][r]=='Q')
			return 1;	
		//check right-side
		r = j+1;
		while(r<8 && m[i][r]=='.'){
			r++;
		}
		if(r<8 && m[i][r]=='Q')
			return 1;
		//check down-side
		r = i-1;
		while(r>=0 && m[r][j]=='.')
			r--;
		if(r>=0 && m[r][j]=='Q')
			return 1;
		//chech up-side
		r = i+1;
		while(r<8 && m[r][j]=='.')
			r++;
		if(r<8 && m[r][j]=='Q')
			return 1;
		//chech left-down side
		ni = i-1;
		nj = j-1;
		while(ni>=0 && nj>=0 && m[ni][nj]=='.'){
			ni--;
			nj--;
		}
		if(ni>=0 && nj>=0 && m[ni][nj]=='Q')
			return 1;
		//chech right-down side
		ni = i-1;
		nj = j+1;
		while(ni>=0 && nj<8 && m[ni][nj]=='.'){
			ni--;
			nj++;
		}
		if(ni>=0 && nj<8 && m[ni][nj]=='Q')
			return 1;
		//chech left-up side
		ni = i+1;
		nj = j-1;
		while(ni<8 && nj>=0 && m[ni][nj]=='.'){
			ni++;
			nj--;
		}
		if(ni<8 && nj>=0 && m[ni][nj]=='Q')
			return 1;
		//chech right-up side
		ni = i+1;
		nj = j+1;
		while(ni<8 && nj<8 && m[ni][nj]=='.'){
			ni++;
			nj++;
		}
		if(ni<8 && nj<8 && m[ni][nj]=='Q')
			return 1;
		return 0;
	}else{
		//*check K*
		//check left side
		r = j-1;
		while(r>0 && m[i][r]=='.'){
			r--;
		}
		if(r>=0 && m[i][r]=='q')
			return 1;	
		//check right-side
		r = j+1;
		while(r<8 && m[i][r]=='.'){
			r++;
		}
		if(r<8 && m[i][r]=='q')
			return 1;
		//check down-side
		r = i-1;
		while(r>=0 && m[r][j]=='.')
			r--;
		if(r>=0 && m[r][j]=='q')
			return 1;
		//chech up-side
		r = i+1;
		while(r<8 && m[r][j]=='.')
			r++;
		if(r<8 && m[r][j]=='q')
			return 1;
		//chech left-down side
		ni = i-1;
		nj = j-1;
		while(ni>=0 && nj>=0 && m[ni][nj]=='.'){
			ni--;
			nj--;
		}
		if(ni>=0 && nj>=0 && m[ni][nj]=='q')
			return 1;
		//chech right-down side
		ni = i-1;
		nj = j+1;
		while(ni>=0 && nj<8 && m[ni][nj]=='.'){
			ni--;
			nj++;
		}
		if(ni>=0 && nj<8 && m[ni][nj]=='q')
			return 1;
		//chech left-up side
		ni = i+1;
		nj = j-1;
		while(ni<8 && nj>=0 && m[ni][nj]=='.'){
			ni++;
			nj--;
		}
		if(ni<8 && nj>=0 && m[ni][nj]=='q')
			return 1;
		//chech right-up side
		ni = i+1;
		nj = j+1;
		while(ni<8 && nj<8 && m[ni][nj]=='.'){
			ni++;
			nj++;
		}
		if(ni<8 && nj<8 && m[ni][nj]=='q')
			return 1;
		return 0;
	}
}


int check_bishop(int i, int j, int p){
	int ni, nj;
	if(p==0){
		//*check k*
		//chech left-down side
		ni = i-1;
		nj = j-1;
		while(ni>=0 && nj>=0 && m[ni][nj]=='.'){
			ni--;
			nj--;
		}
		if(ni>=0 && nj>=0 && m[ni][nj]=='B')
			return 1;
		//chech right-down side
		ni = i-1;
		nj = j+1;
		while(ni>=0 && nj<8 && m[ni][nj]=='.'){
			ni--;
			nj++;
		}
		if(ni>=0 && nj<8 && m[ni][nj]=='B')
			return 1;
		//chech left-up side
		ni = i+1;
		nj = j-1;
		while(ni<8 && nj>=0 && m[ni][nj]=='.'){
			ni++;
			nj--;
		}
		if(ni<8 && nj>=0 && m[ni][nj]=='B')
			return 1;
		//chech right-up side
		ni = i+1;
		nj = j+1;
		while(ni<8 && nj<8 && m[ni][nj]=='.'){
			ni++;
			nj++;
		}
		if(ni<8 && nj<8 && m[ni][nj]=='B'){
			return 1;
		}
		return 0;
	}else{
		//*check K*
		//chech left-down side
		ni = i-1;
		nj = j-1;
		while(ni>=0 && nj>=0 && m[ni][nj]=='.'){
			ni--;
			nj--;
		}
		if(ni>=0 && nj>=0 && m[ni][nj]=='b')
			return 1;
		//chech right-down side
		ni = i-1;
		nj = j+1;
		while(ni>=0 && nj<8 && m[ni][nj]=='.'){
			ni--;
			nj++;
		}
		if(ni>=0 && nj<8 && m[ni][nj]=='b')
			return 1;
		//chech left-up side
		ni = i+1;
		nj = j-1;
		while(ni<8 && nj>=0 && m[ni][nj]=='.'){
			ni++;
			nj--;
		}
		if(ni<8 && nj>=0 && m[ni][nj]=='b')
			return 1;
		//chech right-up side
		ni = i+1;
		nj = j+1;
		while(ni<8 && nj<8 && m[ni][nj]=='.'){
			ni++;
			nj++;
		}
		if(ni<8 && nj<8 && m[ni][nj]=='b')
			return 1;
		return 0;
	}
}

int check_rook(int i, int j, int p){
	int r;
	if(p==0){
		//*check k*
		//check left side
		r = j-1;
		while(r>0 && m[i][r]=='.'){
			r--;
		}
		if(r>=0 && m[i][r]=='R')
			return 1;	
		//check right-side
		r = j+1;
		while(r<8 && m[i][r]=='.'){
			r++;
		}
		if(r<8 && m[i][r]=='R')
			return 1;
		//check down-side
		r = i-1;
		while(r>=0 && m[r][j]=='.')
			r--;
		if(r>=0 && m[r][j]=='R')
			return 1;
		//chech up-side
		r = i+1;
		while(r<8 && m[r][j]=='.')
			r++;
		if(r<8 && m[r][j]=='R')
			return 1;
		return 0;
	}else{
		//*check K*
		//check left side
		r = j-1;
		while(r>0 && m[i][r]=='.'){
			r--;
		}
		if(r>=0 && m[i][r]=='r')
			return 1;	
		//check right-side
		r = j+1;
		while(r<8 && m[i][r]=='.'){
			r++;
		}
		if(r<8 && m[i][r]=='r')
			return 1;
		//check down-side
		r = i-1;
		while(r>=0 && m[r][j]=='.')
			r--;
		if(r>=0 && m[r][j]=='r')
			return 1;
		//chech up-side
		r = i+1;
		while(r<8 && m[r][j]=='.')
			r++;
		if(r<8 && m[r][j]=='r')
			return 1;
		return 0;
	}
}

int check_pawn(int i, int j, int p){
	if(p==0){
		//check k
		if( (i+1>=0) && (i+1<8) && (j+1<8) && (j+1>=0)){
			if(m[i+1][j+1]=='P')
				return 1;
		}
		if( (i+1>=0) && (i+1<8) && (j-1<8) && (j-1>=0)){
			if(m[i+1][j-1]=='P')
				return 1;
		}
	}else{
		//check K
		if( (i-1>=0) && (i-1<8) && (j+1<8) && (j+1>=0)){
			if(m[i-1][j+1]=='p')
				return 1;
		}
		if( (i-1>=0) && (i-1<8) && (j-1<8) && (j-1>=0)){
			if(m[i-1][j-1]=='p')
				return 1;
		}
	}
	return 0;
}

int main(){
	char c;
	int end, ngame, rk, ck, rK, cK;
	end = 0;
	ngame = 0;
	while(!end){
		ngame++;

		//intialize
		end = 1;
		//read
		for(int i=0; i<8; i++){
			for(int j=0; j<8; j++){
				scanf("%c",&m[i][j]);
				if(m[i][j]!='.'){
					end = 0;
					if(m[i][j]=='k'){
						rk = i;
						ck = j;
					}
					if(m[i][j]=='K'){
						rK = i;
						cK = j;
					}
				}
				//printf("%c",m[i][j]);
			}
			scanf("%c",&c);
			//printf("\n");
		}
		//work
		//check k
		if(!end){
			printf("Game #%d: ",ngame);
			if(check_pawn(rk,ck,0) || check_rook(rk,ck,0)
				|| check_bishop(rk,ck,0) || check_queen(rk,ck,0)
				|| check_knight(rk,ck,0) || check_knight(rk,ck,0)){
					printf("black king is in check.\n");
			//check K
			}else if(check_pawn(rK,cK,1) || check_rook(rK,cK,1)
				|| check_bishop(rK,cK,1) || check_queen(rK,cK,1)
				|| check_knight(rK,cK,1) || check_knight(rK,cK,1)){
					printf("white king is in check.\n");
			}else{
				printf("no king is in check.\n");
			}
			scanf("%c",&c);
		}
	}
	return 0;
}
