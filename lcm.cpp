//Link: https://putka-upm.acm.si/tasks/t/lcm_seznami/

//Note: This code was written during the official timed competition 

#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <vector>

#include <algorithm>

#include <set>

#include <map>

#include <string>

#include <bitset>

using namespace std;

const int mx = 1000009;

const int sieveMX = 10000009;

typedef long long ll;

 

#define mid (l+r)/2

int sgtmx[mx * 3];

 

 

vector<pair<int, int> > queries[mx];

ll sol[mx];

int prv[mx];

int sieve[sieveMX];

int arr[mx];

int n, q;

void buildSeive() {

  for (ll i = 2; i < sieveMX; ++i) {

    if (sieve[i]) { continue; }

    for (ll j = i * i; j < sieveMX; j += i) {

      sieve[j] = i;

    }

  }

}

set<int> generatePrimes(int x) {

  set<int> ans;

  while (x > 1 && sieve[x]) {

    ans.insert(sieve[x]);

    x /= sieve[x];

  }

  if (x > 1) {

    ans.insert(x);

  }

  return ans;

}

void build(int x, int l, int r) {

  if (l == r) {

    sgtmx[x] = prv[l];

    return;

  }

  int left = x * 2;

  int right = x * 2 + 1;

  build(left, l, mid);

  build(right, mid + 1, r);

  sgtmx[x] = max(sgtmx[left], sgtmx[right]);

}

int querymx(int x, int l, int r, int s, int e) {

  if (r < s || l>e)

    return -1;

  if (s <= l && e >= r)

    return sgtmx[x];

  int a = querymx(x * 2, l, mid, s, e);

  int b = querymx(x * 2 + 1, mid + 1, r, s, e);

  return max(a, b);

}

void generatePrev() {

  map<int, int> prs;

  for (int i = 0; i < n; ++i) {

    set<int> s = generatePrimes(arr[i]);

    int lst = -1;

    for (auto& it : s) {

      if (prs.find(it) != prs.end()) {

        int a = prs[it];

        lst = max(lst, a);

      }

      prs[it] = i;

    }

    prv[i] = lst;

  }

}

 

// Returns sum of arr[0..index]. This function assumes 

// that the array is preprocessed and partial sums of 

// array elements are stored in BITree[] 

ll getSum(ll BITree[], int index) {

  ll sum = 0; // Initialize result 

 

  // index in BITree[] is 1 more than the index in arr[] 

  index = index + 1;

 

  // Traverse ancestors of BITree[index] 

  while (index > 0) {

    // Add current element of BITree to sum 

    sum += BITree[index];

 

    // Move index to parent node in getSum View 

    index -= index & (-index);

  }

  return sum;

}

 

// Updates a node in Binary Index Tree (BITree) at given 

// index in BITree.  The given value 'val' is added to 

// BITree[i] and all of its ancestors in tree. 

void updateBIT(ll BITree[], int n, int index, ll val) {

  // index in BITree[] is 1 more than the index in arr[] 

  index = index + 1;

 

  // Traverse all ancestors and add 'val' 

  while (index <= n) {

    // Add 'val' to current node of BI Tree 

    BITree[index] += val;

 

    // Update index to that of parent in update View 

    index += index & (-index);

  }

}

 

// Returns the sum of array from [0, x] 

ll sum(int x, ll BITTree1[], ll BITTree2[]) {

  return (getSum(BITTree1, x) * x) - getSum(BITTree2, x);

}

 

 

void updateRange(ll BITTree1[], ll BITTree2[], int n,

  int val, int l, int r) {

  // Update Both the Binary Index Trees 

  // As discussed in the article 

 

  // Update BIT1 

  updateBIT(BITTree1, n, l, val);

  updateBIT(BITTree1, n, r + 1, -val);

 

  // Update BIT2 

  updateBIT(BITTree2, n, l, val * (l - 1));

  updateBIT(BITTree2, n, r + 1, -val * r);

}

 

ll rangeSum(int l, int r, ll BITTree1[], ll BITTree2[]) {

  // Find sum from [0,r] then subtract sum 

  // from [0,l-1] in order to find sum from 

  // [l,r] 

  return sum(r, BITTree1, BITTree2) -

    sum(l - 1, BITTree1, BITTree2);

}

 

 

ll *constructBITree(int n) {

  // Create and initialize BITree[] as 0 

  ll *BITree = new ll[n + 1];

  for (int i = 1; i <= n; i++)

    BITree[i] = 0;

 

  return BITree;

}

int main() {

  scanf("%d%d", &n, &q);

  for (int i = 0; i < n; ++i) {

    scanf("%d", arr + i);

  }

  // Construct two BIT 

  ll *BITTree1, *BITTree2;

 

  // BIT1 to get element at any index 

  // in the array 

  BITTree1 = constructBITree(n);

 

  // BIT 2 maintains the extra term 

  // which needs to be subtracted 

  BITTree2 = constructBITree(n);

 

  buildSeive();

  generatePrev();

  build(1, 0, n - 1);

  int a, b;

  for (int i = 0; i < q; ++i) {

    scanf("%d%d", &a, &b);

    queries[b - 1].push_back({ a - 1,i });

  }

  for (int i = 0; i < n; ++i) {

    int be = querymx(1, 0, n - 1, prv[i], i);

    //update(1, 0, n - 1, be + 1, i, 1);

    updateRange(BITTree1, BITTree2, n, 1, be + 1, i);

    for (auto& k : queries[i]) {

      //ll ans = query(1, 0, n - 1, k.first, i);

      ll ans = rangeSum(k.first, i, BITTree1, BITTree2);

      sol[k.second] = ans;

    }

  } 

  for (int i = 0; i < q; ++i) {

    printf("%lld\n", sol[i]);

  }

}
