#include<bits/stdc++.h>
using namespace std;

class Disjoint_set {
public:
    vector<int> parent, rank, size;

    Disjoint_set(int n){
        parent.resize(n+1);
        rank.resize(n+1, 0);
        size.resize(n+1,1);

        for(int i=1; i <= n; i++) {
            parent[i] = i;
            // size[i] = 1;
        }
    }

    //function to find ultimate parent
    int findParent(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    //function to perform union by rank for two nodes
    void union_by_rank(int u, int v) {
        int ult_pu = findParent(u);
        int ult_pv = findParent(v);

        if(ult_pu == ult_pv) return;

        if(rank[ult_pu] < rank[ult_pv]) parent[ult_pu] = ult_pv;
        else if(rank[ult_pv] < rank[ult_pu]) parent[ult_pv] = ult_pu;
        else {
            parent[ult_pu] = ult_pv;
            rank[ult_pv]++;
        }
    }

    //function to perform union by size for two nodes
    void union_by_size(int u, int v) {
        int ult_pu = findParent(u);
        int ult_pv = findParent(v);

        if(ult_pu == ult_pv) return;

        if(size[ult_pu] < size[ult_pv]){
            parent[ult_pu] = ult_pv;
            size[ult_pv] += size[ult_pu];
        } 
        else {
            parent[ult_pv] = ult_pu;
            size[ult_pu] += size[ult_pv];
        }
    }
};

//driver code
int main()
{
    int n; //number of nodes
    Disjoint_set ds(n);
    ds.union_by_size(1, 2); //to add the edge between node 1 and node 2

    return 0;
}