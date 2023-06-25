#include "header.hpp"
#include <atcoder/all>
using namespace atcoder;

using mint = modint998244353;
mint op(mint a, mint b) {
  return a + b;
}
mint e() {
  return (mint)0;
}
mint mapping(mint f, mint x) {
  return f + x;
}
mint composition(mint f, mint g) {
  return f + g;
}
mint id() {
  return (mint)0;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n = 10;
  lazy_segtree<mint, op, e, mint, mapping, composition, id> seg(n);
}
