#ifdef LOCAL
#include <iostream>
#define debug(x) cerr<<"["<<#x<<"]: "<<x<<endl;
#define EPS 0.0000001
#else
#include <bits/stdc++.h>
#define debug(x) 42
#define debug_c(a) 42
#endif

using namespace std;
#include <vector>
#include <iomanip>

typedef struct {
   unsigned int originalIndex; 
   float pb; // weight- profit
   unsigned int weight;
   unsigned int profit;
} Item;

bool comparePB(Item i1, Item i2) {
   return (i1.pb > i2.pb);
} 


void solve(unsigned int n, vector<Item> &items, unsigned int k){
	//Knapsack 0-1
	//Dados los weights y profits, encuentra el máximo profit que
	//puede lograr una mochila con cierta capacidad tomando máximo 1 elemento.
    vector<int> usedItems (n);
    sort(items.begin(), items.end(), comparePB);

    unsigned int maxprofit = 0, 
                 carriedWeight = 0;
	Item currentItem;

    for (int i=0; i<n; i++) {
        currentItem = items[i];
        if (currentItem.weight + carriedWeight > k) break; //si se pasa del peso
        else {
            maxprofit += currentItem.profit;
            carriedWeight += currentItem.weight;
            usedItems[currentItem.originalIndex] = 1; // accedes al vector original
            items[i] = {}; // elimina registro temporal
        }
    }

    cout << maxprofit << endl;
    for (int j=0; j<n; j++) cout << usedItems[j] << " ";
    cout << endl;
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(0);
    cout.tie(0);

	unsigned int n; // Num. de elementos
	cin>>n;
    vector<unsigned int> p(n); // profits
    for(unsigned int i=0; i<n; i++) cin>>p[i];
    
	vector<Item> items(n); // Items
    unsigned int w; // weight

	for(unsigned int i=0; i<n; i++) {
        cin >> w;
        items[i].pb = p[i] / w;
        items[i].originalIndex = i;
        items[i].weight = w;
        items[i].profit = p[i];
    }

	unsigned int k; // Capacidad de mochila
	cin>>k;

	solve(n, items, k);

}

