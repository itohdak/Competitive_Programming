#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int n;
  cin >> n;
  vector<ll> A(n);
  int nOdd = 0, nEven = 0;
  rep(i, n) {
    cin >> A[i];
    if(A[i] % 2 == 0) nEven++;
    else nOdd++;
  }
  if(nOdd > 0 && nEven > 0)
    sort(A.begin(), A.end());
  rep(i, n) cout << A[i] << ' ';
  cout << endl;
  return 0;
}

