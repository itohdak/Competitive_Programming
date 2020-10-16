#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main() {
  int Q;
  cin >> Q;
  for(int q=0; q<Q; q++) {
    ll a, b, m;
    cin >> a >> b >> m;
    bool ok = false;
    for(int i=1; i<=50; i++) {
      if((a+1)*i <= b && b <= (a+m)*i) {
	vector<ll> ans;
	ll tmp = b - a;
	ll pwr = 1;
	for(int j=0; j<i; j++) {
	  ll mod = tmp % pwr;
	  mod += (m - mod) / 2 * 2;
	  ans.push_back(a+tmp);
	  tmp -= pwr * mod;
	  tmp /= 2;
	  if(j != 0) pwr *= 2;
	}
	cout << i << ' ';
	for(int j=0; j<i; j++)
	  cout << ans[i-1-j] << ' ';
	cout << endl;
	ok = true;
	break;
      }
    }
    if(!ok)
      cout << -1 << endl;
  }
  return 0;
}

