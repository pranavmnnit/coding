#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<sstream>

using namespace std;
#define INF 99999
class CuttingBitString
{
 public:
 int dp[51];
 vector<string> P;
 int N;
 string s;
 bool check(string t)
 {
  for(int i=0;i<P.size();i++)
  {
   if(P[i]==t)return true;
  }
  return false;
 }
 int go(int pos)
 {
  if(pos==N)return 0;
  int &ret=dp[pos];
  if(ret!=-1)return ret;
  ret=INF;
  for(int i=pos;i<N;i++)
  {
   if(check(s.substr(pos,i-pos+1)))
   {
    ret=min(ret,1+go(i+1));
   }
  }
  return ret;
 }
 int getmin(string S)
 {
  s=S;
  N=S.length();
  memset(dp,-1,sizeof(dp));
  string F[]={"0","1"};
  long long int t=1;
  P.push_back("1");
  for(int i=1;i<27;i++)
  {
    t*=5;
    long long int tt=t;
    string g="";
    while(tt>1)
    {
     g=F[tt%2]+g;
     tt/=2;
    }
    g="1"+g;
    P.push_back(g);
  }
  int ret=go(0);
  if(ret>=INF)return -1;
  return ret;
 }
};
