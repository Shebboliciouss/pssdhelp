#include <vector>
#include <string>
#include <iostream>
 
using namespace std;
 
class  QuickSums  {
public:
int s,target,mini;
int data[15];
char f;
string bil;
 
int go(int len,int start) {
  int i,j,k;
  long long res,m1;
  // cout << "length --> " << len << " start --> " <<  start << endl;
  // cout<<"start = s : " << start << " == " <<s<<endl;
  if(start==s) {
    res=0; k=0;
    for(i=0;i<len;i++) {
      //cout << "-------------------------------------------------------------------------------------------" <<endl;
      m1=bil[k]-'0';
      //cout<<"m1 == bil["<< k<< "]-'0'--> " << bil[k]-'0' <<endl;
      //cout<<"j = "<< k+1 << ", j <= " << data[i] <<endl;
      for(j=k+1;j<=data[i];j++){
       // cout<<"j = "<< k+1 << ", j <= " << data[i] <<endl;
        m1=m1*10+(bil[j]-'0');
        //cout << "bil[j]: " << bil[j] <<endl;
        //cout<<"m1.1 = " << m1*10+(bil[j]-'0')<<endl;
      }

      res+=m1; k=data[i]+1;
      //cout<<"res += " << m1 << " res == "<< res <<endl;
      //cout<<"data[i] = " << data[i] << " k == "<< k <<endl;
    }

    if(res==target) {
      f=1;
      if(mini>len-1) mini=len-1;
    }    
  //  cout<<res<<endl;
  }
  for(i=start;i<s;i++) {
    //cout << "-------------------------------------------------------------------------------------------" <<endl;
    data[len]=i;
    //cout << "data[" << len <<"] = " << i << endl;
    //cout << "-------------------------------------------------------------------------------------------" <<endl;
    go(len+1,i+1);
  }
  return 1;
}
 
int minSums (string num, int sum) {
  s=num.size();
  bil=num; mini=1000;
  long long temp;
  target=sum;
  f=0;
  sscanf(num.c_str(),"%lld",&temp);
  if(temp==sum) return 0;
  go(0,0);
  //cout << "!f = " << !f << endl;
  if(!f) return -1;
  return mini;
}
};

int main() {
    QuickSums qs;

    string numbers1 = "99999";
    int sum1 = 45;
    cout << "Minimum additions for " << numbers1 << " to get " << sum1 << ": " << qs.minSums(numbers1, sum1) << endl;
    return 0;
}