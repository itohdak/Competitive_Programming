#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int n, m, r;
  cin >> n >> m >> r;
  vector<int> S(n), B(m);
  for(int i=0; i<n; i++)
    cin >> S[i];
  for(int i=0; i<m; i++)
    cin >> B[i];
  sort(S.begin(), S.end());
  sort(B.begin(), B.end());
  cout << max(r % S[0] + r / S[0] * B[m-1], r) << endl;
  return 0;
}

