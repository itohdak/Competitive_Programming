#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  sort(all(A));
  ll l1 = pow(accumulate(A.begin(), A.begin()+N/2, 0LL), 2);
  ll l2 = pow(accumulate(A.begin()+N/2, A.end(), 0LL), 2);
  ll l3 = pow(accumulate(A.begin(), A.begin()+N/2+1, 0LL), 2);
  ll l4 = pow(accumulate(A.begin()+N/2+1, A.end(), 0LL), 2);
  if(N % 2 == 0)
    cout << l1 + l2 << endl;
  else
    cout << max(l1 + l2, l3 + l4) << endl;
  return 0;
}

