#include <iostream>
#include <vector>
#include <deque>
using namespace std;

const int MAXN = 1001;

struct PP
{
 int st , ed;
 PP(){}
 PP(int st , int ed):st(st) , ed(ed){}
};
deque<PP>kk , empty;
struct Node
{
 int v;
 Node *next;
};
int n ,m;
Node *graph[MAXN];
Node node[MAXN * MAXN];
bool hate[MAXN][MAXN];
int tail;
int biaoji[MAXN];
int color[MAXN];
int mark[MAXN];
void add(int a , int b)
{
 node[tail].v = b;
 node[tail].next = graph[a];
 graph[a] = &node[tail];
 tail++;
}
int dfn[MAXN] , low[MAXN]  , s[MAXN];
int cnt ;

bool check_odd(int u , int col)
{//检查该子块是否为二分图
 int i , v;
 color[u] = col;
 for(Node *it = graph[u] ; it ; it = it->next)
 {
  v = it->v;
  if(mark[v])
  {
   if(color[v] == 0)
   {
    if(check_odd(v , -col))
     return true;
   }
   else if(col == color[v])
    return true;
  }
 }
 return false;
}
void DFS(int pre , int u)
{
 int v , x ,y;
 dfn[u] = low[u] = ++cnt;
 for(Node *it = graph[u] ; it ; it = it->next)
 {
  v = it->v;
  if(v != pre && dfn[u] > dfn[v])
  {//边u-v未访问过
   kk.push_back(PP(u , v));
  }
  if(dfn[v] == -1)
  {//顶点v未访问过
   DFS(u , v);
   low[u] = min(low[u] , low[v]);
   if(dfn[u] <= low[v])
   {//u是割点，找到一个重联通分量
    memset(mark , false , sizeof(mark));
    int st = u;
    do
    {
     x = kk.back().st;
     y = kk.back().ed;
     kk.pop_back();
     mark[x] = mark[y] = true;
    }
    while(!(( x == u && y == v)||( x == v && y == u)));
    memset(color , 0 , sizeof(color));
    if(check_odd(st , 1))
    {
     for(int j = 0 ; j < n ; j++)
     {
      biaoji[j] |= mark[j];
     }
    }
   }
  }
  else if(v != pre )
  {
   low[u] = min(low[u] , dfn[v]);
  }
 }

}
int main()
{
 while(2 == scanf("%d%d",&n,&m))
 {
  if(n == 0 && m == 0)
   break;
  int i , j;
  memset(graph , 0 , sizeof(graph));
  memset(hate , false , sizeof(hate));
  for(i = 0 ; i < m ; i++)
  {
   int u , v;
   scanf("%d%d",&u , &v);
   u-- , v--;
   hate[u][v] = hate[v][u] = true;
  }
  for(i = 0 ; i < n ; i++)
  {
   for(j = i+ 1 ; j < n ; j++)
   {
    if(!hate[i][j])
    {
     add(i , j);
     add(j , i);
    }
   }
  }
  cnt = 0;
  memset(dfn , 0xff , sizeof(dfn));
  memset(low , 0xff , sizeof(low));
  memset(biaoji , 0 , sizeof(biaoji));
  kk = empty;
  for(i = 0 ; i < n ; i++)
  {
   if(dfn[i] == -1)
   {
    DFS(-1 , i);
   }
  }
 
  int jishu = 0;
  for(i = 0 ; i < n ; i++)
   if(biaoji[i])
    jishu++;
  printf("%d\n" , n - jishu);
  
 }
 return 0;
}