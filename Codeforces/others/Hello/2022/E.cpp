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
  int n, m; cin >> n >> m;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  sort(all(A), greater<ll>());
  while(A.size() > m) A.pop_back();
  vector<vector<ll>> B(m);
  vector<double> ave(m), ave_sorted(m);
  rep(i, m) {
    int k; cin >> k;
    B[i] = vector<ll>(k);
    rep(j, k) cin >> B[i][j];
    ll sum = accumulate(all(B[i]), 0LL);
    ave[i] = (double)1*sum/k;
  }
  copy(all(ave), begin(ave_sorted));
  sort(all(ave_sorted), greater<double>());
  vector<int> id(m);
  iota(all(id), 0);
  sort(all(id), [&](int i, int j) {
    return ave[i] > ave[j];
  });
  vector<bool> ok(m), ok_up(m), ok_down(m);
  rep(i, m) {
    ok[i] = (ave[id[i]] <= A[i]);
    ok_up[i] = (i == 0 || ave[id[i]] <= A[i-1]);
    ok_down[i] = (i == m-1 || ave[id[i]] <= A[i+1]);
  }
  vector<int> cum(m+1), cum_up(m+1), cum_down(m+1);
  rep(i, m) {
    cum[i+1] = cum[i] + ok[i];
    cum_up[i+1] = cum_up[i] + ok_up[i];
    cum_down[i+1] = cum_down[i] + ok_down[i];
  }
  vector<int> pos(m);
  rep(i, m) pos[id[i]] = i;
  vector<bool> ans;
  int cur = 0;
  rep(i, m) {
    ll sum = accumulate(all(B[i]), 0LL);
    rep(j, B[i].size()) {
      double ave_ = (double)1*(sum-B[i][j])/(B[i].size()-1);
      int lb = ave_sorted.rend() - lower_bound(ave_sorted.rbegin(), ave_sorted.rend(), ave_);
      bool ok = true;
      if(pos[i] == lb) {
        int l = pos[i];
        ok &= (cum[l] == l);
        ok &= (cum[m]-cum[l+1] == m-(l+1));
        ok &= (ave_ <= A[lb]);
      } else if(pos[i] < lb) {
        int l = pos[i], r = lb;
        ok &= (cum[l] == l);
        ok &= (cum_up[r]-cum_up[l+1] == r-(l+1));
        ok &= (cum[m]-cum[r] == m-r);
        ok &= (ave_ <= A[lb-1]);
      } else {
        int l = lb, r = pos[i];
        ok &= (cum[l] == l);
        ok &= (cum_down[r]-cum_down[l] == r-l);
        ok &= (cum[m]-cum[r+1] == m-(r+1));
        ok &= (ave_ <= A[lb]);
      }
      ans.push_back(ok);
      cur++;
    }
  }
  for(bool a: ans) cout << a;
  cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
