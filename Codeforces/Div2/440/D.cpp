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
  vector<int> res(n);
  vector<int> resP(n), resB(n);
  rep(i, n) {
    cout << "? " << i << ' ' << (i+1)%n << endl;
    cin >> resP[i];
  }
  rep(i, n) {
    cout << "? " << i << ' ' << i << endl;
    cin >> resB[i];
  }
  rep(i, n) res[i] = resP[i] ^ resB[(i+1)%n];
  vector<int> A(n);
  vector<int> ans;
  rep(i, n) {
    vector<int> P(n);
    vector<int> B(n);
    P[0] = i;
    B[P[0]] = 0;
    unordered_set<int> st;
    st.insert(P[0]);
    bool ok = true;
    rep(j, n) {
      if(j) {
        P[j] = res[j-1] ^ P[j-1];
        if(P[j] >= n) {
          ok = false;
          break;
        }
        st.insert(P[j]);
        B[P[j]] = j;
      }
    }
    if(ok && st.size() == n) {
      rep(j, n) {
        if((P[j] ^ B[j]) != resB[j]) ok = false;
      }
      if(ok) {
        // copy(all(P), begin(A));
        ans.push_back(i);
      }
    }
  }
  assert(ans.size() > 0);
  cout << "!" << endl;
  cout << ans.size() << endl;
  cout << ans[0] << ' ';
  int prev = ans[0];
  rep(i, n) if(i) {
    cout << (res[i-1] ^ prev) << ' ';
    prev = (res[i-1] ^ prev);
  }
  cout << endl;
  return 0;
}
