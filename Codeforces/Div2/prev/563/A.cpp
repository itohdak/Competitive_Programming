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
  vector<ll> A(2*n);
  ll sumAll = 0LL;
  rep(i, 2*n) { cin >> A[i]; sumAll += A[i]; }
  sort(A.begin(), A.end());
  ll sumN = accumulate(A.begin(), A.begin()+n, 0LL);
  if(sumN * 2 == sumAll)
    cout << -1 << endl;
  else {
    rep(i, 2*n)
      cout << A[i] << ' ';
    cout << endl;
  }
  return 0;
}

