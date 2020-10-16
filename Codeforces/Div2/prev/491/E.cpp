#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

ll fact(int n){
  ll ret = 1;
  for(int i=n; i>0; i--){
    ret *= i;
  }
  return ret;
}

int main(){
  ll n;
  cin >> n;
  vector<int> number(10, 0);
  vector<int> begin(10, 0);
  while(n > 0){
    if(number[n % 10] == 0)
      begin[n % 10] = 1;
    number[n % 10]++;
    n /= 10;
  }
  ll ans = 0;
  for(int a=begin[0]; a<=number[0]; a++)
    for(int b=begin[1]; b<=number[1]; b++)
      for(int c=begin[2]; c<=number[2]; c++)
	for(int d=begin[3]; d<=number[3]; d++)
	  for(int e=begin[4]; e<=number[4]; e++)
	    for(int f=begin[5]; f<=number[5]; f++)
	      for(int g=begin[6]; g<=number[6]; g++)
		for(int h=begin[7]; h<=number[7]; h++)
		  for(int i=begin[8]; i<=number[8]; i++)
		    for(int j=begin[9]; j<=number[9]; j++){
		      int sum = a + b + c + d + e + f + g + h + i + j;
		      ll tmp = (sum-a) * fact(sum-1);
		      if(a > 1) tmp /= fact(a);
		      if(b > 1) tmp /= fact(b);
		      if(c > 1)	tmp /= fact(c);
		      if(d > 1)	tmp /= fact(d);
		      if(e > 1)	tmp /= fact(e);
		      if(f > 1)	tmp /= fact(f);
		      if(g > 1)	tmp /= fact(g);
		      if(h > 1)	tmp /= fact(h);
		      if(i > 1)	tmp /= fact(i);
		      if(j > 1)	tmp /= fact(j);
		      ans += tmp;
		    }
  cout << ans << endl;
  return 0;
}

