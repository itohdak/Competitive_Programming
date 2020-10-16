#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int n;
  ll m;
  cin >> n >> m;
  vector<int> D;
  ll sum = 0;
  ll suml = 0;
  
  for(int i=0; i<n; i++){
    ll a, b;
    cin >> a >> b;
    sum += a;
    suml += b;
    D.push_back(a-b);
  }

  if(suml > m){
    cout << -1 << endl;
  } else {
    sort(D.begin(), D.end(), greater<int>());
    vector<ll> E(n+1, 0LL);
    for(int i=0; i<n; i++)
      E[i+1] += E[i] + D[i];

    int l = 0;
    int r = n;
    while(l < r){
      int mid = (l + r) / 2;
      if(sum - E[mid] <= m)
	r = mid;
      else
	l = mid+1;
    }
    cout << l << endl;
  }
  return 0;
}

