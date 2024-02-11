#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll h, w, n; cin >> h >> w >> n;
  vector<pair<ll, ll>> P(n);
  vector<ll> H, W;
  for(auto& [a, b]: P) {
    cin >> a >> b;
    a--; b--;
    H.push_back(a);
    W.push_back(b);
  }
  sort(all(H));
  sort(all(W));
  H.erase(unique(all(H)), end(H));
  W.erase(unique(all(W)), end(W));
  rep(i, n) {
    cout << lower_bound(all(H), P[i].first) - H.begin() + 1 << ' ';
    cout << lower_bound(all(W), P[i].second) - W.begin() + 1 << endk;
  }
  return 0;
}
