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
  int n, m; cin >> n >> m;
  vector<string> S(n); rep(i, n) cin >> S[i];
  int tmpx = 1, tmpy = 1;
  bool swapLR = false, swapUD = false;
  auto move = [&](char d) {
    if(d == 'R') cout << (swapLR ? 'L' : 'R') << endl;
    else if(d == 'L') cout << (swapLR ? 'R' : 'L') << endl;
    else if(d == 'U') cout << (swapUD ? 'D' : 'U') << endl;
    else if(d == 'D') cout << (swapUD ? 'U' : 'D') << endl;
    else assert(false);
    cin >> tmpx >> tmpy;
    if(S[tmpx-1][tmpy-1] == 'F') exit(0);
  };
  auto decideLR = [&]() {
    cout << 'R' << endl;
    int x, y; cin >> x >> y;
    if(tmpy == y) swapLR = true;
    tmpx = x, tmpy = y;
    if(S[tmpx-1][tmpy-1] == 'F') exit(0);
    if(!swapLR) move('L');
  };
  auto decideUD = [&]() {
    cout << 'D' << endl;
    int x, y; cin >> x >> y;
    if(tmpx == x) swapUD = true;
    tmpx = x, tmpy = y;
    if(S[tmpx-1][tmpy-1] == 'F') exit(0);
    if(!swapUD) move('U');
  };
  if((m > 1 && S[0][1] != '*') && (n > 1 && S[1][0] != '*')) {
    decideLR();
    decideUD();
  } else if((m > 1 && S[0][1] != '*')) {
    decideLR();
    int cnt = 0;
    while(n == 1 || S[1][tmpy-1] == '*') {
      move('R');
      cnt++;
    }
    decideUD();
    rep(i, cnt) move('L');
  } else if((n > 1 && S[1][0] != '*')) {
    decideUD();
    int cnt = 0;
    while(m == 1 || S[tmpx-1][1] == '*') {
      move('D');
      cnt++;
    }
    decideLR();
    rep(i, cnt) move('U');
  } else {
    assert(false);
  }
  vector<int> dist(n*m, inf);
  vector<char> from(n*m, '-');
  auto bfs = [&]() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0] = 0;
    int dx[] = {0, -1, 0, 1};
    int dy[] = {-1, 0, 1, 0};
    char df[] = {'L', 'U', 'R', 'D'};
    while(!q.empty()) {
      auto [cur, d] = q.front(); q.pop();
      int x = cur/m;
      int y = cur%m;
      if(dist[cur] != d) continue;
      rep(k, 4) {
        int nx = x+dx[k];
        int ny = y+dy[k];
        int ne = nx*m+ny;
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(S[nx][ny] == '*') continue;
        if(dist[ne] > dist[cur]+1) {
          dist[ne] = dist[cur]+1;
          from[ne] = df[k];
          q.push({ne, dist[ne]});
        }
      }
    }
  };
  bfs();
  // rep(i, n) {
  //   rep(j, m) {
  //     cout << (dist[i*m+j]==inf ? -1 : dist[i*m+j]) << ' ';
  //   }
  //   cout << endk;
  // }
  // rep(i, n) {
  //   rep(j, m) {
  //     cout << from[i*m+j] << ' ';
  //   }
  //   cout << endk;
  // }
  string ans;
  int tmp;
  rep(i, n) rep(j, m) if(S[i][j] == 'F') tmp = i*m+j;
  while(tmp) {
    ans += from[tmp];
    if(from[tmp] == 'R') tmp--;
    else if(from[tmp] == 'L') tmp++;
    else if(from[tmp] == 'U') tmp += m;
    else if(from[tmp] == 'D') tmp -= m;
    else assert(false);
  }
  reverse(all(ans));
  // cout << ans << endk;
  for(char c: ans) move(c);
  return 0;
}
