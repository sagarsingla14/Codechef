// CPP implementation of the approach
#include <bits/stdc++.h>
using namespace std;
#define ll int

// Table for storing 2^ith parent
ll **table;

// To store the height of the tree
ll height;

// initializing the table and
// the height of the tree
void initialize(ll n)
{
	height = (ll)ceil(log2(n));
	table = new ll *[n + 1];
}

// Filling with -1 as initial
void preprocessing(ll n)
{
	for (ll i = 0; i < n + 1; i++)
	{
		table[i] = new ll[height + 1];
		memset(table[i], -1, sizeof table[i]);
	}
}

// Calculating sparse table[][] dynamically
void calculateSparse(ll u, ll v)
{
	// Using the recurrence relation to
	// calculate the values of table[][]
	table[v][0] = u;
	for (ll i = 1; i <= height; i++)
	{
		table[v][i] = table[table[v][i - 1]][i - 1];

		// If we go out of bounds of the tree
		if (table[v][i] == -1)
			break;
	}
}

// Function to return the Kth ancestor of V
ll kthancestor(ll V, ll k)
{
	// Doing bitwise operation to
	// check the set bit
	for (ll i = 0; i <= height; i++)
	{
		if (k & (1 << i))
		{
			V = table[V][i];
			if (V == -1)
				break;
		}
	}
	return V;
}

int main() {
	ll n , q;
	cin >> n >> q;

	initialize(n);

	preprocessing(n);

	cout << 1 << endl;
	for(ll i = 0 ; i < n - 1 ; i ++) {
		ll u , v;
		cin >> u >> v;
		calculateSparse(u , v);
	}

	while(q--) {
		ll node , anc;
		cin >> node >> anc;
		cout << kthancestor(node , anc) << endl;
	}

	return 0;
}
