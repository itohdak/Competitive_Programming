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
  int n; ll w; cin >> n >> w;
  vector<ll> W(n);
  map<ll, int> cnt;
  rep(i, n) {
    cin >> W[i];
    cnt[W[i]]++;
  }
  auto bsearch = [&]() {
    auto test = [&](ll mid) {
      vector<ll> A(mid, w);
      for(auto itr=cnt.rbegin(); itr!=cnt.rend(); itr++) {
        int c = 0;
        rep(i, mid) {
          if(c == itr->second) break;
          int can = min((ll)itr->second-c, A[i]/itr->first);
          A[i] -= can * itr->first;
          c += can;
        }
        if(c != itr->second) return false;
      }
      return true;
    };
    ll ok = 100005, ng = 0;
    while(ok-ng>1) {
      ll mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  cout << bsearch() << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
