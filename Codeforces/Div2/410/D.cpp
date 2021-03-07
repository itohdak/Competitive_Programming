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
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<ll> B(n); rep(i, n) cin >> B[i];
  vector<int> id(n); rep(i, n) id[i] = i;
  sort(all(id), [&](int i, int j) {
    return A[i] > A[j];
  });
  if(n&1) {
    vector<int> ans;
    ans.push_back(id[0]);
    for(int i=1; i<n; i+=2) {
      ans.push_back((B[id[i]] > B[id[i+1]] ? id[i] : id[i+1]));
    }
    assert(ans.size() == n/2+1);
    cout << ans.size() << endk;
    for(int a: ans) cout << a+1 << ' ';
    cout << endk;
  } else {
    vector<int> ans;
    for(int i=0; i<n; i+=2) {
      if(i == 0) {
        ans.push_back(id[i]);
        ans.push_back(id[i+1]);
      } else {
        ans.push_back((B[id[i]] > B[id[i+1]] ? id[i] : id[i+1]));
      }
    }
    assert(ans.size() == n/2+1);
    cout << ans.size() << endk;
    for(int a: ans) cout << a+1 << ' ';
    cout << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while(T--) solve();
  return 0;
}
