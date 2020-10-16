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
  cin >> n;
  vector<int> A(n);
  for(int i=0; i<n; i++)
    cin >> A[i];
  vector<int> memo(n,0);
  vector<bool> memo2(n, false);
  for(int i=n-2; i>=0; i--){
    if(!memo2[A[i+1]-1]){
      memo2[A[i+1]-1] = true;
      memo[i] = memo[i+1] + 1;
      // for(int i=0; i<n; i++)
      // 	cout << memo2[i] << ' ';
      // cout << endl;
    } else {
      memo[i] = memo[i+1];
    }
  }
  vector<bool> done(n, false);
  ll ans = 0;
  for(int i=0; i<n; i++){
    if(!done[A[i]-1]){
      ans += memo[i];
      done[A[i]-1] = true;
    }
  }
  cout << ans << endl;
  return 0;
}

