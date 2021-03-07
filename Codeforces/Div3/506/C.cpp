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
  vector<pair<ll, ll>> P(n);
  vector<ll> p;
  rep(i, n) {
    cin >> P[i].first >> P[i].second;
    P[i].first--;
    p.push_back(P[i].first);
    p.push_back(P[i].second);
  }
  sort(all(p));
  p.erase(unique(all(p)), end(p));
  vector<pair<int, int>> pi(n);
  vector<int> cnt(p.size());
  rep(i, n) {
    pi[i].first = lower_bound(all(p), P[i].first) - begin(p);
    pi[i].second = lower_bound(all(p), P[i].second) - begin(p);
    cnt[pi[i].first]++;
    cnt[pi[i].second]--;
  }
  vector<ll> sum_n_1(p.size()+1);
  ll sum_n = 0;
  int tmp = 0;
  rep(i, p.size()) {
    tmp += cnt[i];
    sum_n_1[i+1] += sum_n_1[i];
    if(tmp == n-1) sum_n_1[i+1] += p[i+1] - p[i];
    if(tmp == n) sum_n += p[i+1] - p[i];
  }

  // cout << p << endk;
  // cout << cnt << endk;
  // cout << sum_n_1 << endk;

  ll ans = 0;
  // cout << pi << endk;
  rep(i, n) {
    // cout << sum_n + sum_n_1.back() - (sum_n_1[pi[i].second] - sum_n_1[pi[i].first]) << endk;
    chmax(ans, sum_n + sum_n_1.back() - (sum_n_1[pi[i].second] - sum_n_1[pi[i].first]));
  }
  cout << max(0LL, ans-1) << endk;
  return 0;
}
