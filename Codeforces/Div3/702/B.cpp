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
  vector<int> cnt(3);
  rep(i, n) cnt[A[i]%3]++;
  vector<int> over, under;
  rep(i, 3) {
    if(cnt[i] > n/3) over.push_back(i);
    if(cnt[i] < n/3) under.push_back(i);
  }
  if(over.size() == 0) {
    cout << 0 << endk;
  } else if(over.size() == 1) {
    int i = over[0];
    cout << (n/3-cnt[(i+1)%3]) + (n/3-cnt[(i+2)%3])*2 << endk;
  } else {
    assert(under.size() == 1);
    int i = under[0];
    cout << (cnt[(i+2)%3]-n/3) + (cnt[(i+1)%3]-n/3)*2 << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
