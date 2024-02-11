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
  vector<int> A(n), B(n);
  rep(i, n) cin >> A[i];
  rep(i, n) cin >> B[i];
  vector<int> cnt(n+1);
  set<int> st;
  rep(i, n) {
    st.insert(B[i]);
    cnt[i+1] = st.size();
  }
  int q; cin >> q;
  vector<int> X(q), Y(q);
  rep(i, q) {
    cin >> X[i] >> Y[i];
    X[i]--; Y[i]--;
  }
  vector<int> id(q);
  iota(all(id), 0);
  sort(all(id), [&](int i, int j) {
    if(X[i] == X[j]) {
      return Y[i] < Y[j];
    } else {
      return X[i] < X[j];
    }
  });
  map<int, int> mx;
  rep(i, n) {
    if(!mx.count(B[i])) mx[B[i]] = i;
  }
  rep(i, n) {
    if(!mx.count(A[i])) mx[A[i]] = inf;
  }
  vector<string> ans(q);
  int l = 0, r = 0;
  set<int> st2;
  for(int i: id) {
    int x = X[i], y = Y[i];
    while(l <= x) {
      chmax(r, mx[A[l]]+1);
      st2.insert(A[l]);
      l++;
    }
    if(y+1 < r) {
      ans[i] = "No";
    } else {
      ans[i] = (st2.size() == cnt[y+1] ? "Yes" : "No");
    }
  }
  rep(i, q) cout << ans[i] << endk;
  return 0;
}
