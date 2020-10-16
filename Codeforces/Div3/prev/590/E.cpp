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
  int N, M;
  cin >> N >> M;
  vector<int> X(M);
  vector<ll> cnt(N), cnt2(N);
  ll ans1 = 0;
  rep(i, M) {
    cin >> X[i];
    X[i]--;
    if(i != 0) {
      int l = min(X[i-1], X[i]);
      int r = max(X[i-1], X[i]);
      if(l != r) {
        cnt[l+1]++;
        cnt[r]--;

        cnt2[l] += l;
        cnt2[r] += (l+1) - (r-l);
      }

      ans1 += r-l;
    }
  }
  REP(i, 1, N) cnt[i] += cnt[i-1];
  // rep(i, N) cout << cnt[i] << ' ';
  // cout << endl;
  // rep(i, N) cout << cnt2[i] << ' ';
  // cout << endl;
  // cout << ans1 << endl;
  rep(i, N)
    cout << ans1 - cnt[i] + cnt2[i] << ' ';
  cout << endl;
  return 0;
}

