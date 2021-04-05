#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()

// https://visualgo.net/en/matching

// idea:
// recall that bipartite graph is free from odd-length cycles

// example problem:
// topcoder open 2009 qualifying 1, 
// abridged problem statment:
// given a list of numbers N, return a list of all the elements in N that
// can be paired with N[0] successfully as a part of complete prime pairing
// ie each element paired with one another, all the pair sums should be prime
// constraints: even number of elements, all elements are distinct, 1 <= N_i <= 1000, 2 <= |N| <= 50
// for N = {1, 4, 7, 10, 11, 12}, ans is {4, 10} for obvious reasons

// sol: there are only 168 primes, complete search and bitmask dp not possible cuz of the constraints
// what we should see is that the pairing is done on a bipartite graph, because if you sum two odd or two even numbers,
// there is no way that they will be prime(except {1, 1} but all elements are distinct), so we should pair odds with evens
// so, we can split odd/even numbers and add edge a between them if even[i] + odd[j] is prime

// after we build this graph, the solution is fairly simple:
// if sizes of the sets are different, then the pairing is not possible.

// try to match odd[0] with even[k] for all k : [0, n/2 - 1] and do mcbm for the rest, if we obtain n/2-1 more matchings, add
// even[k] to the answer

// augmenting path algorithm for MCBM

// what is an augmenting path? 

// -> an augmenting path is a path that stars from a free(ie unmatched) vertex on the left set, alternates between a free edge
// (now on the right set), then a matched edge(now on left set again), a free edge... until the path finally arrives a free vertex
// on the right set of the bipartite graph  

// TBD ~ come back when you learn flows (you'll)

int aug(int l){
	if(vis[l]) return 0;
	vis[l] = 1;
	for(auto &r:  adj[l])
		if((match[r] == -1) || aug(match[r])){
			match[r] = l;
			return 1;
		}
	return 0;
}



int main(){
	ios::sync_with_stdio(0); cin.tie(0);
}
