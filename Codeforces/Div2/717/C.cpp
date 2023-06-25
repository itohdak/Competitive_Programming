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
  vector<int> A(n); rep(i, n) cin >> A[i];
  while(true) {
    unordered_set<int> st;
    st.insert(0);
    vector<int> odd;
    rep(i, n) {
      if(A[i]%2) odd.push_back(i);
      unordered_set<int> next;
      for(int cur: st) {
        next.insert(cur);
        next.insert(cur+A[i]);
      }
      st = next;
    }
    ll sum = accumulate(all(A), 0);
    if(sum % 2 || !st.count(sum/2)) {
      cout << 0 << endk;
      return;
    } else if(odd.size()) {
      cout << 1 << endk;
      cout << odd[0] + 1 << endk;
      return;
    } else {
      rep(i, n) A[i] /= 2;
      // cout << 1 << endk;
      // cout << min_element(all(A)) - begin(A) + 1 << endk;
    }
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
