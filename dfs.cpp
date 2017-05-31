
#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Graph;

void dfs(const Graph& g, int u, 
			vector<char>& s, vector<int>& v)
{
	s[u] = 'G';
	v.push_back(u);
	for(int i = 0; i < g[u].size(); ++i)
	{
		if(s[g[u][i]] == 'W')
		{
			dfs(g, g[u][i], s, v);
		}
	}
	s[u] = 'B';
}

int main() 
{
	int n; cin >> n;
	Graph g(n);
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			int c; cin >> c;
			if(c == 1)
			{
				g[i].push_back(j);
			}
		}
	}
  
	vector<char> state(n, 'W');
	int numOfComponents = 0;
	for(int i = 0; i < n; ++i)
	{
		if(state[i] == 'W')
		{
			++numOfComponents;
			vector<int> vertices; // W = white/untouched; G = gray/visitted; B = black/done
			dfs(g, i, state, vertices);
			cout << numOfComponents << ": ";
			for(auto e: vertices)
			{
				cout << " " << e + 1;
			}
			cout << endl;
		}
	}
	return 0;
}
