#include<bits/stdc++.h>
// --===Amit pandey--===
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define endl			"\n"
#define pb 				push_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				make_pair
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define all(n) 			n.begin(),n.end()
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n) 		__builtin_popcount(n)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}


std::vector<std::vector<std::pair<int,int> > >graph;
//we want to have adjacency list of pair pair is for adjacent edge and weight

void addEdge(int u,int v,bool bidir=true,int wt=0){
    graph[u].push_back(std::make_pair(v,wt));
    if(bidir){
        graph[u].push_back(std::make_pair(u,wt));
    }
}
void Disp(){
    for(auto i:graph){
        //i is vector of pair
        for(auto j:i){
            std::cout<<"{"<<j.first<<","<<j.second<<"}";
        }
        std::cout<<"\n";
    }
}
void display(int src,int vertices){
    std::queue<int> qu;
    std::vector<bool>visited(vertices,false);
    qu.push(src);
    visited[src]=true;
    while (not qu.empty()){
        int currentNode=qu.front();
        qu.pop();
        std::cout<<currentNode<<" ";
        for(auto neighbour:graph[currentNode]){
            // neighbour is a pair
            if(not visited[neighbour.first]){
                if(not visited[neighbour.first]){
                    qu.push(neighbour.first);
                    visited[neighbour.first]=true;
                }
            }
        }
    }
    
}
int main(int argc, char const *argv[]){
    /* code */
    int vertices,edges;
    std::cin>>vertices>>edges;
    graph.resize(vertices);
    while (edges--){
        int u,v,wt;
        std::cin>>u>>v>>wt;
        addEdge(u,v,true,wt);
    }
    Disp();
    
    return 0;
}

