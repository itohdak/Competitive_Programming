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

void solve() {
  int n; cin >> n;
  vector<pair<ll, ll>> P(n);
  rep(i, n) cin >> P[i].first >> P[i].second;
  if(n%2) {
    cout << "No" << endk;
    return;
  }
  P.push_back(P[0]);
  rep(i, n/2) {
    ll dx1 = P[i+1].first-P[i].first, dy1 = P[i+1].second-P[i].second;
    ll dx2 = P[i+n/2+1].first-P[i+n/2].first, dy2 = P[i+n/2+1].second-P[i+n/2].second;
    if(dx1 * dy2 != dx2 * dy1 || dx1*dx1+dy1*dy1 != dx2*dx2+dy2*dy2) {
      cout << "No" << endk;
      return;
    }
  }
  cout << "Yes" << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
