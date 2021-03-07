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
  int n, k; cin >> n >> k;
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<int> Aorg(n);
  copy(all(A), begin(Aorg));
  sort(all(Aorg));
  int med = Aorg[(n-1)/2];
  auto test = [&](int mid) {
    vector<int> sum(n+1);
    rep(i, n) sum[i+1] = sum[i] + (A[i] >= mid ? 1 : -1);
    vector<int> mn(n+1);
    rep(i, n) chmin(mn[i+1], mn[i]);
    rep(i, n) {
      if(i+k > n) continue;
      if(sum[i+k] - mn[i] >= 0) return true;
    }
    return false;
  };
  int ok = med, ng = n+1;
  while(abs(ok-ng)>1) {
    int mid = (ok+ng)/2;
    (test(mid) ? ok : ng) = mid;
  }
  cout << ok << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
