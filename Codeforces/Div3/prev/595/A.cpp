#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REP(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int Q;
  cin >> Q;
  rep(q, Q) {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    sort(all(A));
    bool ok = true;
    rep(i, N-1)
      if(A[i+1] - A[i] == 1) ok = false;
    if(ok) cout << 1 << endl;
    else cout << 2 << endl;
  }
  return 0;
}

