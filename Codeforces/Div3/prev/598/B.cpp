#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
template<class t, class u>
ostream& operator<<(ostream& os, const pair<t, u>& p) {
  return os << "{" << p.first << ", " << p.second << "}";
}
template<class t> ostream& operator<<(ostream& os, const vector<t>& v) {
  os << "{";
  rep(i, v.size()) { if(i) os << ", "; os << v[i]; }
  return os << "}";
}
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

void solve() {
  int N;
  cin >> N;
  vector<int> A(N);
  map<int, int> mp;
  rep(i, N) {
    cin >> A[i];
    mp[A[i]] = i;
  }
  int tmp = 0;
  while(!mp.empty()) {
    int j = mp.begin()->first;
    int idx = mp.begin()->second;
    cout << j << ' ';
    mp.erase(j);
    if(idx == tmp) {
      tmp = idx+1;
    } else {
      REP(i, tmp, idx) {
        if(i == idx-1) {
          mp[A[i]] = idx;
          A[idx] = A[i];
        } else {
          cout << A[i] << ' ';
          mp.erase(A[i]);
        }
      }
      tmp = idx;
    }
    // cout << endl;
    // if(tmp == N) break;
  }
  cout << endl;
}

int main() {
  int Q;
  cin >> Q;
  rep(q, Q) solve();
  return 0;
}

