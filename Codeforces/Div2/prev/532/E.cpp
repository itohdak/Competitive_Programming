#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)
#include <deque>

using namespace std;
#define ll long long

#define MAX_N 100000
int C[MAX_N];
bool visited[MAX_N];

int dx[] = { 0, 0, -1, 1};
int dy[] = {-1, 1,  0, 0};
int H, W;
bool reached;

bool valid(int x) {
  return !visited[x]; // modify here
}

// depth first search without recursion
deque<int> D; // stack when dfs, queue when bfs
vector<vector<int> > to(MAX_N);
void search(int x, int type=0) {
  visited[x] = true;
  D.push_back(x);
  while(D.size() > 0) {
    int v;
    if(type == 0) v = D.back();  // dfs
    else          v = D.front(); // bfs
    // if(type == 0) D.pop_back();  // dfs
    // else          D.pop_front(); // bfs
    if(to[v].size() == 0) {
      D.pop_back();
    } else {
      for(int i=0; i<to[v].size(); i++) {
	int nx = to[v][i];
	if(valid(nx)) {
	  visited[nx] = true;
	  D.push_back(nx);
	} else { // loop
	}
      }
    }
  }
}

struct edge {
  int from;
  int to;
  ll cost;
  edge(int f, int t, ll c) : from(f), to(t), cost(c) {};
};

int main(){
  int n, m;
  cin >> n >> m;
  for(int i=0; i<m; i++) {
    int u, v;
    ll c;
    cin >> u >> v >> c;
    // edge e(u, v, c);
    to[u-1].push_back(v-1);
  }
  return 0;
}

