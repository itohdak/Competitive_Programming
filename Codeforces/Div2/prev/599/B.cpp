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
  string S, T;
  cin >> S >> T;
  vector<int> cnt(26);
  rep(i, N) {
    cnt[int(S[i]-'a')]++;
    cnt[int(T[i]-'a')]++;
  }
  rep(i, 26) {
    if(cnt[i] & 1) {
      cout << "No" << endl;
      return;
    }
  }
  cout << "Yes" << endl;
  vector<pair<int, int> > ans;
  rep(i, N) {
    if(S[i] == T[i]) continue;
    bool found = false;
    REP(j, i+1, N) {
      if(S[j] == S[i]) {
        ans.push_back(make_pair(j, i));
        char tmp = S[j];
        S[j] = T[i];
        T[i] = tmp;
        found = true;
        break;
      }
    }
    if(found) continue;
    REP(j, i+1, N) {
      if(T[j] == S[i]) {
        ans.push_back(make_pair(i+1, j));
        char tmp = S[i+1];
        S[i+1] = T[j];
        T[j] = tmp;
        ans.push_back(make_pair(i+1, i));
        tmp = S[i+1];
        S[i+1] = T[i];
        T[i] = tmp;
        break;
      }
    }
  }
  cout << ans.size() << endl;
  for(auto a: ans) cout << a.first+1 << ' ' << a.second+1 << endl;
}

int main() {
  int K;
  cin >> K;
  rep(k, K) solve();
  return 0;
}

