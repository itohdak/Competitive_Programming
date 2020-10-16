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
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  string S;
  cin >> S;
  vector<set<int> > pos(26);
  rep(i, S.size()) pos[int(S[i]-'a')].insert(i);
  int Q;
  cin >> Q;
  rep(q, Q) {
    int i;
    cin >> i;
    if(i == 1) {
      int j;
      char c;
      cin >> j >> c;
      j--;
      pos[int(S[j]-'a')].erase(j);
      S[j] = c;
      pos[int(c-'a')].insert(j);
    } else {
      int l, r;
      cin >> l >> r;
      l--; r--;
      int cnt = 0;
      rep(i, 26) {
        if(pos[i].empty()) continue;
        auto itr = pos[i].lower_bound(l);
        if(itr == pos[i].end()) continue;
        int L = *itr;
        if(l <= L && L <= r) cnt++;
      }
      cout << cnt << endl;
    }
  }
  return 0;
}

