using namespace std;
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
#define tot(a) a.begin(), a.end()
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define mod 1000000007
#define mini(a) *min_element(tot(a))
#define maxi(a) *max_element(tot(a))
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define coutl(a) cout << a << endl
#define vi vector<int>
#define vll vector<ll>
#define yes coutl("YES")
#define no coutl("NO")

class DisjointSet{
    vector<int> size,parent;
    
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        
        for(int i=0;i<=n;i++){
            size[i] = 1 ;
            parent[i] = i;
        }
    }
    
    
    int findUPar(int node ){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    
    void UnionBySize(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        
        if(ulp_u == ulp_v) return ;
        
        if(size[ulp_u] < size[ulp_v] ){
            size[ulp_v] += size[ulp_u];
            parent[ulp_u ] = ulp_v;
        }
        else {
            size[ulp_u] += size[ulp_v];
            parent[ulp_v] = ulp_u;
        }
    }
};


// ------------------------------------------------------------------------------------



void solver(){

}


// ------------------------------------------------------------------------------------

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll testCases;
    cin >> testCases; while (testCases--)
    {
        solver();
    }
    return 0;
}



// ------------------------------------------------------------------------------------
/*






*/
