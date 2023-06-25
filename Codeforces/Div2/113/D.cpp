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
  int n, m, k; cin >> n >> m >> k;
  vector<ll> X(n); rep(i, n) cin >> X[i];
  vector<ll> Y(m); rep(i, m) cin >> Y[i];
  vector<pair<ll, ll>> P(k);
  for(auto& [x, y]: P) {
    cin >> x >> y;
  }
  vector<int> onX, onY;
  rep(i, k) {
    bool onx = *lower_bound(all(X), P[i].first) == P[i].first;
    bool ony = *lower_bound(all(Y), P[i].second) == P[i].second;
    if(onx && ony) continue;
    else if(onx) onX.push_back(i);
    else if(ony) onY.push_back(i);
  }
  ll ans = 0;
  {
    vector<vector<int>> cnt(m);
    for(int i: onX) {
      auto [x, y] = P[i];
      cnt[upper_bound(all(Y), y)-begin(Y)-1].push_back(i);
    }
    rep(i, m) {
      ans += 1LL*cnt[i].size()*(cnt[i].size()-1);
      sort(all(cnt[i]), [&](int i, int j) {
        return P[i] < P[j];
      });
      int l = 0;
      int sz = cnt[i].size();
      while(l < sz) {
        int r = l;
        while(r < sz && P[cnt[i][l]].first == P[cnt[i][r]].first) {
          r++;
        }
        ans -= 1LL*(r-l)*(r-l-1);
        l = r;
      }
    }
  }
  {
    vector<vector<int>> cnt(n);
    for(int i: onY) {
      auto [x, y] = P[i];
      cnt[upper_bound(all(X), x)-begin(X)-1].push_back(i);
    }
    rep(i, n) {
      ans += 1LL*cnt[i].size()*(cnt[i].size()-1);
      sort(all(cnt[i]), [&](int i, int j) {
        return pair<int, int>(P[i].second, P[i].first) < pair<int, int>(P[j].second, P[j].first);
      });
      int l = 0;
      int sz = cnt[i].size();
      while(l < sz) {
        int r = l;
        while(r < sz && P[cnt[i][l]].second == P[cnt[i][r]].second) {
          r++;
        }
        ans -= 1LL*(r-l)*(r-l-1);
        l = r;
      }
    }
  }
  ans /= 2;
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
