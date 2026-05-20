#include <iostream>  
#include <vector>  
#include <unordered_set>  
using namespace std;  
  
class UnionFind {  
    vector<int> Parent, Rank;  
public:  
    UnionFind(int n) {  
        Parent.resize(n);  
        Rank.resize(n, 0);  
        for (int i = 0; i < n; i++)  
            Parent[i] = i;  
    }  
  
    int find(int i) {  
        if (Parent[i] != i)  
            Parent[i] = find(Parent[i]);  
        return Parent[i];  
    }  
  
    void unionByRank(int i, int j) {  
        int irep = find(i), jrep = find(j);  
        if (irep == jrep) return;  
        if (Rank[irep] < Rank[jrep])  
            Parent[irep] = jrep;  
        else if (Rank[irep] > Rank[jrep])  
            Parent[jrep] = irep;  
        else {  
            Parent[jrep] = irep;  
            Rank[irep]++;  
        }  
    }  
};  
  
int main() {  
    ios::sync_with_stdio(false);  
    cin.tie(0);  
  
    int villages, roads, newroads;  
    cin >> villages >> roads >> newroads;  
  
    UnionFind horia(villages + 1);  
  
    for (int i = 0; i < roads; i++) {  
        int k, j;  
        cin >> k >> j;  
        horia.unionByRank(k, j);  
    }  
  
    unordered_set<int> omades;  
    for (int u = 1; u <= villages; ++u)  
        omades.insert(horia.find(u));  
  
    int groups = omades.size() - newroads;  
    cout << (groups <= 1 ? 1 : groups) << "\n";  
    return 0;  
}  