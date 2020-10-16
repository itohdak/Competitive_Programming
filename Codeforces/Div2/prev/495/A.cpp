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
  ll d;
  cin >> n >> d;
  vector<ll> X(n);
  for(int i=0; i<n; i++)
    cin >> X[i];
  int ans = 2;
  for(int i=0; i<n-1; i++){
    if(X[i+1] - X[i] == 2 * d)
      ans++;
    else if(X[i+1] - X[i] > 2 * d)
      ans += 2;
    else
      ans += 0;
  }
  cout << ans << endl;
  return 0;
}

