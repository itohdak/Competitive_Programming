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
  int n; cin >> n;
  vector<string> S(n); rep(i, n) cin >> S[i];
  vector<string> T(n); rep(i, n) cin >> T[i];
  {
    vector<pair<int, int>> P;
    rep(i, n) rep(j, n) {
      if(S[i][j] == '#') P.push_back({i, j});
    }
    sort(all(P));
    vector<pair<int, int>> Q;
    rep(i, n) rep(j, n) {
      if(T[i][j] == '#') Q.push_back({i, j});
    }
    if(P.size() != Q.size()) {
      cout << "No" << endk;
      return 0;
    }
    int dx = Q[0].first - P[0].first;
    int dy = Q[0].second - P[0].second;
    bool ok = true;
    rep(i, P.size()) {
      if(P[i].first+dx == Q[i].first && P[i].second+dy == Q[i].second) continue;
      ok = false;
      break;
    }
    if(ok) {
      cout << "Yes" << endk;
      return 0;
    }
  }
  {
    vector<pair<int, int>> P;
    rep(j, n) rrep(i, n) {
      if(S[i][j] == '#') P.push_back({j, n-1-i});
    }
    sort(all(P));
    vector<pair<int, int>> Q;
    rep(i, n) rep(j, n) {
      if(T[i][j] == '#') Q.push_back({i, j});
    }
    if(P.size() != Q.size()) {
      cout << "No" << endk;
      return 0;
    }
    int dx = Q[0].first - P[0].first;
    int dy = Q[0].second - P[0].second;
    bool ok = true;
    rep(i, P.size()) {
      if(P[i].first+dx == Q[i].first && P[i].second+dy == Q[i].second) continue;
      ok = false;
      break;
    }
    if(ok) {
      cout << "Yes" << endk;
      return 0;
    }
  }
  {
    vector<pair<int, int>> P;
    rrep(i, n) rrep(j, n) {
      if(S[i][j] == '#') P.push_back({n-1-i, n-1-j});
    }
    sort(all(P));
    vector<pair<int, int>> Q;
    rep(i, n) rep(j, n) {
      if(T[i][j] == '#') Q.push_back({i, j});
    }
    if(P.size() != Q.size()) {
      cout << "No" << endk;
      return 0;
    }
    int dx = Q[0].first - P[0].first;
    int dy = Q[0].second - P[0].second;
    bool ok = true;
    rep(i, P.size()) {
      if(P[i].first+dx == Q[i].first && P[i].second+dy == Q[i].second) continue;
      ok = false;
      break;
    }
    if(ok) {
      cout << "Yes" << endk;
      return 0;
    }
  }
  {
    vector<pair<int, int>> P;
    rrep(j, n) rep(i, n) {
      if(S[i][j] == '#') P.push_back({n-1-j, i});
    }
    sort(all(P));
    vector<pair<int, int>> Q;
    rep(i, n) rep(j, n) {
      if(T[i][j] == '#') Q.push_back({i, j});
    }
    if(P.size() != Q.size()) {
      cout << "No" << endk;
      return 0;
    }
    int dx = Q[0].first - P[0].first;
    int dy = Q[0].second - P[0].second;
    bool ok = true;
    rep(i, P.size()) {
      if(P[i].first+dx == Q[i].first && P[i].second+dy == Q[i].second) continue;
      ok = false;
      break;
    }
    if(ok) {
      cout << "Yes" << endk;
      return 0;
    }
  }
  cout << "No" << endk;
  return 0;
}
