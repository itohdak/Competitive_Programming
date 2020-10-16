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
  vector<ll> A(n);
  vector<ll> B(n);
  for(int i=0; i<n; i++)
    cin >> A[i];
  for(int i=0; i<n; i++)
    cin >> B[i];

  vector<ll> S(n, 0LL); // sum
  S[0] = A[0] + B[0];
  for(int i=1; i<n; i++)
    S[i] = S[i-1] + A[i] + B[i];
  // for(int i=0; i<n; i++)
  //   cout << S[i] << ' ';
  // cout << endl;

  vector< vector<ll> > C(n+1, vector<ll>(2, 0LL));
  for(int i=0; i<n; i++){
    if(i == 0){
      C[i+1][0] = (2 * i) * A[i] + (2 * i + 1) * B[i];
      C[i+1][1] = (2 * i) * B[i] + (2 * i + 1) * A[i];
    } else {
      C[i+1][0] = C[i][1] + (2 * i) * A[i] + (2 * i + 1) * B[i];
      C[i+1][1] = C[i][0] + (2 * i) * B[i] + (2 * i + 1) * A[i];
    }
  }
  // for(int i=0; i<n; i++)
  //   cout << C[i][0] << ' ';
  // cout << endl;
  // for(int i=0; i<n; i++)
  //   cout << C[i][1] << ' ';
  // cout << endl;

  vector< vector<ll> > D(n, vector<ll>(2, 0LL));
  for(int i=n-1; i>=0; i--){
    if(i == n-1){
      D[i][0] = (2 * i) * A[i] + (2 * n - 1) * B[i];
      D[i][1] = (2 * i) * B[i] + (2 * n - 1) * A[i];
    } else {
      D[i][0] = (2 * i) * A[i] + (D[i+1][0] - (S[n-1] - S[i])) + (2 * n - 1) * B[i];
      D[i][1] = (2 * i) * B[i] + (D[i+1][1] - (S[n-1] - S[i])) + (2 * n - 1) * A[i];
    }
  }
  // for(int i=0; i<n; i++)
  //   cout << D[i][0] << ' ';
  // cout << endl;
  // for(int i=0; i<n; i++)
  //   cout << D[i][1] << ' ';
  // cout << endl;

  ll ret = 0;
  for(int i=0; i<n; i++){
    ll tmp;
    if(i % 2 == 0)
      tmp = C[i][1] + D[i][0];
    else
      tmp = C[i][0] + D[i][1];
    if(ret < tmp)
      ret = tmp;
  }
  if(ret < C[n][n % 2 == 0])
    ret = C[n][n % 2 == 0];
  cout << ret << endl;
  return 0;
}

