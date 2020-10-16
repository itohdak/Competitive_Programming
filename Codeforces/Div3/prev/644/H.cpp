#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
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

ll string2ll(string s) {
  ll pw = 1;
  ll ret = 0;
  for(int i=s.size()-1; i>=0; i--, pw*=2) {
    ret += pw * int(s[i]-'0');
  }
  return ret;
}
void solve() {
  int N, M;
  cin >> N >> M;
  vector<ll> A(N);
  set<ll> se;
  rep(i, N) {
    string a;
    cin >> a;
    A[i] = string2ll(a);
    se.insert(A[i]);
  }
  sort(all(A));
  ll ans = pow(2, M-1)-1;

  rep(i, N) {
    // cout << ans << endl;
    if(A[i] < ans) {
      if(i%2==0) ans++;
    } else if(A[i] == ans) {
      if(i%2==0) {
        ans++;
      } else {
        ans--;
        while(se.count(ans)) ans--;
      }
    } else {
      if(i%2==1) {
        ans--;
        while(se.count(ans)) ans--;
      }
    }
  }
  rrep(i, M) cout << ((ans>>i)&1);
  cout << endl;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
