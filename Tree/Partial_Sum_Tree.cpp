We can also use partial sum on trees.

Example: Having a rooted tree, each vertex has a value (initially 0), 
each query gives you numbers v and u (v is an ancestor of u) and 
asks you to increase the value of all vertices in the path from u to v by 1.

So, we have an array p, and for each query, we increase p[u] by 1 and 
decrease p[par[v]] by 1. The we run this (like a normal partial sum):

void dfs(int v){
	for(auto u : adj[v])
		if(u - par[v])
			dfs(u), p[v] += p[u];
}