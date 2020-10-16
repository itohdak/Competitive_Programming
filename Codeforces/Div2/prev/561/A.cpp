#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main() {
  int n;
  cin >> n;
  vector<string> S(n);
  vector<int> A(26, 0);
  for(int i=0; i<n; i++) {
    cin >> S[i];
    A[int(S[i][0]-'a')]++;
  }
  int ans = 0;
  for(int i=0; i<26; i++) {
    int a1, a2;
    a1 = A[i] / 2;
    a2 = A[i] - a1;
    ans += a1 * (a1-1) / 2 + a2 * (a2-1) / 2;
  }
  cout << ans << endl;
  return 0;
}

