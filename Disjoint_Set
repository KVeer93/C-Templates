class disjoint_sets {

vector<int> parent, rank, size;

public:
disjoint_sets(int n){
    parent.resize(n+1, 0);
    rank.resize(n+1, 0);
    size.resize(n+1, 0);
    for(int i = 0; i <= n; i++){
        parent[i] = i;
    }
}

int findPar(int node){
if(node == parent[node]){
    return node;
}

return parent[node] = findPar(parent[node]);
}


void UnionByRank(int u, int v){
    int ulp_u = findPar(u);
    int ulp_v = findPar(v);

    if(ulp_u == ulp_v) return;

    if(rank[ulp_u] < rank[ulp_v]){
        parent[ulp_u] = ulp_v;
    }
    else if(rank[ulp_u] > rank[ulp_v]){
        parent[ulp_v] = ulp_u;
    }
    else{
        parent[ulp_v] = ulp_u;
        rank[ulp_u]++;
    }
}

void UnionBySize(int u, int v){
    int ulp_u = findPar(u);
    int ulp_v = findPar(v);

    if(ulp_u == ulp_v) return;

    if(size[ulp_u] < size[ulp_v]){
        parent[ulp_u] = ulp_v;
        size[ulp_v] += size[ulp_u];
    }else{
        parent[ulp_v] = ulp_u;
        size[ulp_u] += size[ulp_v];
    }
}


};
