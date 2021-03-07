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
  auto query = [&](int l, int r) {
    cout << "? " << l+1 << ' ' << r << endl;
    int p; cin >> p;
    p--;
    return p;
  };
  int p2 = query(0, n);
  int pl = (p2 == 0 ? -1 : query(0, p2+1));
  if(pl == p2) { // left
    auto test = [&](int mid) {
      int p = query(mid, p2+1);
      return p == p2;
    };
    int ok = 0, ng = p2;
    while(abs(ok-ng)>1) {
      int mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    cout << "! " << ok+1 << endl;
  } else { // right
    auto test = [&](int mid) {
      int p = query(p2, mid);
      return p == p2;
    };
    int ok = n, ng = p2+1;
    while(abs(ok-ng)>1) {
      int mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    cout << "! " << ok << endl;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
