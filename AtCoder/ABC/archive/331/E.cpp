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
  int n, m, l; cin >> n >> m >> l;
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<int> B(m); rep(i, m) cin >> B[i];
  vector<int> idA(n), idB(m);
  iota(all(idA), 0);
  iota(all(idB), 0);
  sort(all(idA), [&](int i, int j) {
    return A[i] > A[j];
  });
  sort(all(idB), [&](int i, int j) {
    return B[i] > B[j];
  });
  multiset<int> st;
  for(int i: idA) {
    for(int j: idB) {
      int tmp = A[i] + B[j];
      if(st.size() < l+1) {
	st.insert(tmp);
      } else {
	if(*st.begin() < tmp) {
	  st.erase(st.begin());
	  st.insert(tmp);
	} else {
	  break;
	}
      }
    }
  }
  rep(i, l) {
    int c, d; cin >> c >> d;
    c--; d--;
    if(st.count(A[c]+B[d])) {
      st.erase(st.find(A[c]+B[d]));
    }
  }
  assert(st.size());
  cout << *(--st.end()) << endk;
  return 0;
}
