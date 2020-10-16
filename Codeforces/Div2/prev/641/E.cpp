#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
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

int N, M;
vector<vector<int>> D;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void bfs() {
  queue<pair<int, int>> Q;
  vector<vector<bool>> vis(N, vector<bool>(M));
  rep(i, N) rep(j, M) if(D[i][j]==0) {
    Q.push(make_pair(i, j));
  }
  while(!Q.empty()) {
    auto tmp = Q.front();
    int tmpx = tmp.first, tmpy = tmp.second;
    Q.pop();
    if(vis[tmpx][tmpy]) continue;
    vis[tmpx][tmpy] = true;
    rep(k, 4) {
      int nx = tmpx+dx[k], ny = tmpy+dy[k];
      if(0 <= nx && nx < N && 0 <= ny && ny < M &&
         !vis[nx][ny]) {
        D[nx][ny] = min(D[tmpx][tmpy] + 1, D[nx][ny]);
        Q.push(make_pair(nx, ny));
      }
    }
  }
}
int main() {
  int T;
  cin >> N >> M >> T;
  vector<string> B(N);
  D = vector<vector<int>>(N, vector<int>(M, inf));
  rep(i, N) cin >> B[i];
  int cnt = 0;
  rep(i, N) rep(j, M) {
    rep(k, 4) {
      int nx = i+dx[k], ny = j+dy[k];
      if(0 <= nx && nx < N && 0 <= ny && ny < M &&
         B[nx][ny] == B[i][j]) {
        D[i][j] = 0;
        cnt++;
      }
    }
  }
  bfs();
  // cout << D << endl;
  rep(t, T) {
    int i, j;
    ll p;
    cin >> i >> j >> p;
    i--, j--;
    if(cnt == 0) {
      cout << B[i][j] << endl;
    } else if(D[i][j] >= p) {
      cout << B[i][j] << endl;
    } else {
      cout << char('0'+(int(B[i][j]-'0')+(p-D[i][j])%2)%2) << endl;
    }
  }
  return 0;
}
