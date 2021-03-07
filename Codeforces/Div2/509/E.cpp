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
  vector<pair<int, int>> P(n-1);
  rep(i, n-1) {
    cin >> P[i].first >> P[i].second;
    if(P[i].first > P[i].second) {
      swap(P[i].first, P[i].second);
    }
  }
  bool ok = true;
  vector<int> v;
  rep(i, n-1) {
    if(P[i].second != n) ok = false;
    v.push_back(P[i].first);
  }
  if(!ok) {
    cout << "NO" << endk;
    return 0;
  }
  sort(all(v));
  if(v.back() != n-1) {
    cout << "NO" << endk;
    return 0;
  }
  rep(i, v.size()) {
    if(i+1 > v[i]) {
      cout << "NO" << endk;
      return 0;
    }
  }
  cout << "YES" << endk;
  set<int> st;
  int prev = 0;
  // cout << v << endl;
  rep(i, v.size()) {
    if(i && v[i] == v[i-1]) {
      // cout << st << endl;
      assert(st.size());
      cout << prev << ' ' << *st.begin() << endk;
      prev = *st.begin();
      st.erase(st.begin());
    } else {
      if(i) cout << prev << ' ' << v[i] << endk;
      prev = v[i];
      for(int j=(i ? v[i-1]+1 : 1); j<v[i]; j++) st.insert(j);
    }
  }
  assert(st.empty());
  cout << prev << ' ' << n << endk;
  return 0;
}
