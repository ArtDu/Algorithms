// img/x.pdf problem 7


/**
 * In this code we have a very large array called arr, and very large set of operations
 * Operation #1: Increment the elements within range [i, j] with value val
 * Operation #2: Get max element within range [i, j]
 * Build tree: build_tree(1, 0, N-1)
 * Update tree: update_tree(1, 0, N-1, i, j, value)
 * Query tree: query_tree(1, 0, N-1, i, j)
 * Actual space required by the tree = 2*2^ceil(log_2(n)) - 1
 */

#include<iostream>
#include<algorithm>
using namespace std;

#include<string.h>
#include<math.h>

const int N = 1e5+5;
const int MAX = 1e5+5;
#define inf 0x7fffffff

struct Node{
    int idx;
    int mx;
};

int arr[N];
int _time[N];
Node tree[4 * MAX];
int lazy[4 * MAX];

/**
 * Build and init tree
 */
void build_tree(int node, int a, int b) {
    if(a > b) return; // Out of range

    if(a == b) { // Leaf node
        tree[node].mx = arr[a]; // Init value
        tree[node].idx = a;
        return;
    }

    build_tree(node*2, a, (a+b)/2); // Init left child
    build_tree(node*2+1, 1+(a+b)/2, b); // Init right child

    if(tree[node*2].mx >= tree[node*2+1].mx) {
        tree[node].mx = tree[node*2].mx;
        tree[node].idx = tree[node*2].idx;
    } else {
        tree[node].mx = tree[node*2+1].mx;
        tree[node].idx = tree[node*2+1].idx;
    }
    //tree[node].mx = max(tree[node*2].mx, tree[node*2+1].mx); // Init root value
}

/**
 * Increment elements within range [i, j] with value value
 */
void update_tree(int node, int a, int b, int i, int j, int value) {

    if(lazy[node] != 0) { // This node needs to be updated
        tree[node].mx += lazy[node]; // Update it

        if(a != b) {
            lazy[node*2] += lazy[node]; // Mark child as lazy
            lazy[node*2+1] += lazy[node]; // Mark child as lazy
        }

        lazy[node] = 0; // Reset it
    }

    if(a > b || a > j || b < i) // Current segment is not within range [i, j]
        return;

    if(a >= i && b <= j) { // Segment is fully within range
        tree[node].mx += value;

        if(a != b) { // Not leaf node
            lazy[node*2] += value;
            lazy[node*2+1] += value;
        }

        return;
    }

    update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
    update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

    if(tree[node*2].mx >= tree[node*2+1].mx) {
        tree[node].mx = tree[node*2].mx;
        tree[node].idx = tree[node*2].idx;
    } else {
        tree[node].mx = tree[node*2+1].mx;
        tree[node].idx = tree[node*2+1].idx;
    }
    //tree[node].mx = max(tree[node*2].mx, tree[node*2+1].mx); // Updating root with max value
}

/**
 * Query tree to get max element value within range [i, j]
 */
Node query_tree(int node, int a, int b, int i, int j) {

    if(a > b || a > j || b < i) {
        Node tmp{}; tmp.mx = -inf;
        return tmp; // Out of range
    }

    if(lazy[node] != 0) { // This node needs to be updated
        tree[node].mx += lazy[node]; // Update it

        if(a != b) {
            lazy[node*2] += lazy[node]; // Mark child as lazy
            lazy[node*2+1] += lazy[node]; // Mark child as lazy
        }

        lazy[node] = 0; // Reset it
    }

    if(a >= i && b <= j) // Current segment is totally within range [i, j]
        return tree[node];

    Node q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
    Node q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

    Node res;
    if(q1.mx >= q2.mx){
        res = q1;
    } else {
        res = q2;
    }
//    int res = max(q1, q2); // Return final result

    return res;
}

int main() {

    int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }


    build_tree(1, 0, n-1);

    memset(lazy, 0, sizeof lazy);

    for (int i = 0; i < t; ++i) {
        Node tmp = query_tree(1, 0, n-1, 0, n-1);
        int idx = tmp.idx; int mx = tmp.mx;
        _time[idx]++;
        update_tree(1, 0, n-1, idx, idx, arr[idx] - mx);
        if(idx != 0)
            update_tree(1, 0, n-1, 0, idx - 1, 1);
        if(idx != n - 1)
            update_tree(1, 0, n-1, idx+1, n - 1, 1);

    }

    for (int i = 0; i < n; ++i) {
        cout << _time[i] << " ";
    }
    cout << "\n";
    return 0;
}
