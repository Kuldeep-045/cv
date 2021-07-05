#include <bits/stdc++.h>
using namespace std;
class Graph {
	map<int, vector<pair<int, int>>>m;
public:
	void addEdge(int x, int y, int wt)
	{
		m[x].push_back({y, wt});
		m[y].push_back({x, wt});
	}
	void print_graph()
	{
		for (auto p : m)
		{
			cout << p.first << "--> ";
			for (auto v : m[p.first])
			{
				cout << "(" << v.first << "," << v.second << ") ";
			}
			cout << "\n";
		}
	}
	void Dijkstra_S(int src)
	{
		unordered_map<int, int>dist;
		for (auto p : m)
		{
			dist[p.first] = INT_MAX;
		}
		dist[src] = 0;
		set<pair<int, int>>st;
		st.insert({0, src});
		while (st.size())
		{
			auto rem = *(st.begin());
			auto node = rem.second;
			int node_distance = rem.first;
			st.erase(st.begin());

			// iterate over neighbour/child node
			for (auto child_pair : m[node])
			{
				if (child_pair.second + node_distance < dist[child_pair.first])
				{
					// in the set of a particular node is not possible
					// now we have to remove the old pair if it is present and add the new pair int the set
					int dest = child_pair.first;
					auto it = st.find({dist[dest], dest});
					if (it != st.end())
					{
						st.erase(it);
					}
					// insert a new pair
					dist[dest] = node_distance + child_pair.second;
					st.insert({dist[dest], dest});
				}
			}
		}
	}
};
void solve()
{
	Graph g;
	g.addEdge(1, 2, 1);
	g.addEdge(1, 3, 4);
	g.addEdge(2, 3, 1);
	g.addEdge(3, 4, 2);
	g.addEdge(1, 4, 7);
	// g.print_graph(); print the graph
	g.Dijkstra_S(1);
}
int main(int argc, char const *argv[])
{
	solve();
	return 0;
}