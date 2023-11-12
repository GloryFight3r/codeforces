#include <iostream>

using namespace std;

const int mxN = (1 << 20);

int tree[mxN];
int a[] = {2, 5, 10, 12, 16};

void update(int k, int l, int r, int index, int value) {
  if (r < index || l > index || l > r) return;
  if (l == r) {
    tree[k] = value;
    return;
  }

  int middle = (l + r) >> 1;
  update(k << 1, l, middle, index, value);
  update(k << 1 | 1, middle + 1, r, index, value);

  tree[k] = tree[k << 1] + tree[k << 1 | 1];
}

int query(int k, int l, int r, int i, int j) {
  if (r < i || l > j || l > r) return 0;

  if (r <= j && l >= i) {
    return tree[k];
  }
  int middle = (l + r) >> 1;

  return query(k << 1, l, middle, i, j) + query(k << 1 | 1, middle + 1, r, i, j);
}

int main() {

  for (int i = 0; i < 5; i++) {
    update(1, 0, 4, i, a[i]);
  }

  cout << query(1, 0, 4, 1, 3) << "\n";

  return 0;
}
