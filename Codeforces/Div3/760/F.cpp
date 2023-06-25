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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  ll x, y; cin >> x >> y;
  vector<int> A, B;
  while(x) {
    A.push_back(x&1);
    x >>= 1;
  }
  while(y) {
    B.push_back(y&1);
    y >>= 1;
  }
  // cout << A << endk << B << endk;
  auto check = [&]() {
    rep(i, B.size()) {
      if(i+A.size() > B.size()) break;
      if(i+A.size() == B.size() && i && A.back() == 0) continue;
      if(!i && i+A.size() < B.size() && A.front() == 0) continue;
      bool ok = true;
      rep(j, i) if(B[j] == 0) ok = false;
      rep(j, A.size()) if(B[i+j] != A[j]) ok = false;
      REP(j, i+A.size(), B.size()) if(B[j] == 0) ok = false;
      if(ok) {
        return true;
      }
    }
    return false;
  };
  if(check()) {
    cout << "YES" << endk;
    return;
  };
  reverse(all(A));
  if(check()) {
    cout << "YES" << endk;
    return;
  };
  while(A.back() == 0) A.pop_back();
  if(check()) {
    cout << "YES" << endk;
    return;
  };
  reverse(all(A));
  if(check()) {
    cout << "YES" << endk;
    return;
  };
  cout << "NO" << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
