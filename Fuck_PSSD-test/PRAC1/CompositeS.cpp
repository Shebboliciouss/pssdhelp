#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class CompositeS{
  public:
  
  int howMany(int n)
  {
    int i;
    int count=0;
    int ret=0;
    
    if(n==1)
      return 0;
    
    for(i=1;i<n;i++)
    {
      if(n%i==0)
      {  
        count=howMany(i);
        count=pow(2,i)-count;
        ret=ret+count;
      }
    }
    return ret;    
  }
};

class RedundantStrings {
public:
	int howMany(int);
};

int RedundantStrings::howMany(int length) 
{

	if (length == 1)
		return 0;
		
	int total = 0;
		
	for (int sub = 1; sub <= length/2; sub++)
	{
		if (length%sub != 0 || length/sub < 2)
			continue;
		// how many strings of length sub? 2^sub
		total += (1<<sub) - howMany(sub);
	}
	return total;	
}

int main (){
  RedundantStrings  s;
  cout << s.howMany(1) << endl;
  cout << s.howMany(2) << endl;
  cout << s.howMany(4) << endl;
  cout << s.howMany(10) << endl;
  cout << s.howMany(30) << endl;
  return 0;
}