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

vector<string> S;
int N;
bool dfs(int x, int y, int parX, int parY) {
  if(y == N) {
    if(x == 0) return false;
    else       return true;
  }
  if(S[x][y] == '1' || S[x][y] == '2') {
    if(x == parX) return dfs(x, y+1, x, y);
    else return false;
  } else {
    if(x == parX) return dfs((x+1)%2, y, x, y);
    else return dfs(x, y+1, x, y);
  }
}
void solve() {
  cin >> N;
  S = vector<string>(2);
  cin >> S[0] >> S[1];
  cout << (dfs(0, 0, 0, -1) ? "YES" : "NO") << endl;
}
int main() {
  int Q;
  cin >> Q;
  rep(q, Q) solve();
  return 0;
}

