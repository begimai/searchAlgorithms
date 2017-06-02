#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

typedef unordered_map<int, vector<int>> Graph;

void dfs(Graph& g, int ver, unordered_map<int, char>& statesVec, list<int>& order)
{
	statesVec[ver] = 'g';
	
	for(auto& it: g[ver])
	{
		if(statesVec[it] == 'w')
		{
			dfs(g, it, statesVec, order);
		}
	}
	order.push_front(ver);
	statesVec[ver] = 'b';
}

void printGraph(const Graph& g)
{
	for(auto it: g)
	{
		cout << it.first << ":";
		for(auto v: it.second)
		{
			cout << " " << v;
		}
		cout << endl;
	}
}

int main()
{
	int n, m; cin >> n >> m;
	Graph g(n);
	
	list<int> order;
	
	unordered_map<int, char> states(n);
	
	for(int i = 0; i < m; i++)
	{
		int prereq; cin >> prereq;
		int course; cin >> course;
		
		g[prereq].push_back(course);
		g.insert({course, vector<int>()});
		
		states[prereq] = 'w';
		states[course] = 'w';
	}
	
	printGraph(g);
	// vector<char>  states(n, 'w'); // w - not visited, g - visited, will be used later, b - visited, not used further
	
	for(auto& edge: g)
	{
		if(states[edge.first] == 'w')
		{
			// order.push_front(edge.first);			
			dfs(g, edge.first, states, order);
		}
	}
	
	cout << "Order:";
	for(int e: order)
	{
		cout << " " << (e);
	}
	cout << endl;
	
	return 0;
}
