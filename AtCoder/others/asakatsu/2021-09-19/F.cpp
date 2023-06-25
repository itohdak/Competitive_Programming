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
  vector<pair<ll, ll>> A(n), B(n);
  for(auto& [x, y]: A) cin >> x >> y;
  for(auto& [x, y]: B) cin >> x >> y;
  pair<ld, ld> Am, Bm;
  {
    ll sumX = 0, sumY = 0;
    for(auto [x, y]: A) {
      sumX += x, sumY += y;
    }
    Am.first = (ld)sumX / n;
    Am.second = (ld)sumY / n;
  }
  {
    ll sumX = 0, sumY = 0;
    for(auto [x, y]: B) {
      sumX += x, sumY += y;
    }
    Bm.first = (ld)sumX / n;
    Bm.second = (ld)sumY / n;
  }
  ld sumA = 0;
  ld sumB = 0;
  rep(i, n) {
    ld dx = (A[i].first-Am.first);
    ld dy = (A[i].second-Am.second);
    sumA += sqrt(dx*dx+dy*dy);
  }
  rep(i, n) {
    ld dx = (B[i].first-Bm.first);
    ld dy = (B[i].second-Bm.second);
    sumB += sqrt(dx*dx+dy*dy);
  }
  cout << fixed << setprecision(10) << sumB/sumA << endk;
  return 0;
}
