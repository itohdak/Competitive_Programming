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
  int n, m; cin >> n >> m;
  vector<int> A(n), B(n), C(m), D(m);
  rep(i, n) cin >> A[i];
  rep(i, n) cin >> B[i];
  rep(i, m) cin >> C[i];
  rep(i, m) cin >> D[i];
  vector<int> id(n);
  iota(all(id), 0);
  sort(all(id), [&](int i, int j) {
    if(A[i] == A[j]) {
      return B[i] > B[j];
    } else {
      return A[i] > A[j];
    }
  });
  vector<int> id2(m);
  iota(all(id2), 0);
  sort(all(id2), [&](int i, int j) {
    return C[i] > C[j];
  });
  multiset<int> st;
  int l = 0;
  rep(i, n) {
    while(l < m && C[id2[l]] >= A[id[i]]) {
      st.insert(D[id2[l]]);
      l++;
    }
    // cout << A[id[i]] << ' ' << B[id[i]] << ' ' << st << endk;
    auto itr = st.lower_bound(B[id[i]]);
    if(itr == st.end()) {
      cout << "No" << endk;
      return 0;
    }
    st.erase(itr);
  }
  cout << "Yes" << endk;
  return 0;
}
