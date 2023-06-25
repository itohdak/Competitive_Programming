#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

vector<ll> find_divisor(ll N) {
  vector<ll> divisor;
  for(int i=1; i<=sqrt(N); i++) {
    if(N % i == 0)
      divisor.push_back(i);
  }
  int n = divisor.size();
  for(int i=n-1; i>=0; i--) {
    if(N != (ll)pow(divisor[i], 2))
      divisor.push_back(N / divisor[i]);
  }
  return divisor;
}
void solve() {
  int n; cin >> n;
  vector<int> A(n);
  rep(i, n) cin >> A[i];
  sort(all(A));
  int ans = 1;
  REP(i, 0, n/2+1) {
    map<int, int> cnt;
    REP(j, i, n) {
      cnt[A[j]-A[i]]++;
    }
    map<int, int> cnt2;
    for(auto [m, c]: cnt) {
      auto div = find_divisor(m);
      for(auto d: div) cnt2[d] += c;
    }
    if(cnt[0] >= n/2) chmax(ans, inf);
    for(auto [m, c]: cnt2) {
      if(c+cnt[0] >= n/2) chmax(ans, m);
    }
  }
  cout << (ans==inf ? -1 : ans) << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
