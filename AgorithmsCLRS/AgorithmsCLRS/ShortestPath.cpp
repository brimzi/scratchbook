//Scrap about shortest path using DP


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>


struct Edge
{
	int32_t weight;
	int32_t from, to;
	Edge(int32_t v1,int32_t v2,int32_t weight):weight(weight),from(from),to(to){}
};

struct vertex
{
	int32_t Id;
	std::vector<int32_t>* neighbours;
	std::vector<int32_t>* weightTo;
	vertex():Id(-1)
	{
		neighbours = nullptr;
		weightTo = nullptr;
	}
	vertex(vertex&& v) :Id(v.Id)
	{
		neighbours = v.neighbours;
		v.neighbours = nullptr;

		weightTo = v.weightTo;
		v.weightTo = nullptr;
	}
	

	vertex& operator=(vertex&& v)
	{
		Id = v.Id;
		neighbours = v.neighbours;
		v.neighbours = nullptr;
		return *this;
	}

	~vertex()
	{
		if (neighbours)
		{
			delete neighbours;
			
		}
		if(weightTo)
		{
			delete weightTo;
		}
			
	}

private:
	vertex(const vertex& v);

	vertex& operator=(const vertex& v);
	

};


struct Graph
{
	
	
	

	void addVertex(vertex& v)
	{
		vertices[v.Id]= std::move(v);
	}

	vertex& getVertex(int32_t v)
	{
		auto r=vertices.find(v);
		if (r == vertices.end())
			return nothing;

		return r->second;
	}

	size_t size()
	{
		return vertices.size();
	}


private:
	std::map<int32_t, vertex> vertices;
	vertex nothing;
};


struct ShortestPath
{
	std::vector<int32_t> operator()(Graph& g,int32_t root,int32_t target) const
	{
		std::vector<int32_t> res;
		std::vector<int32_t> pathcost;
		auto visited{ std::vector<bool>(g.size()) };
		
		pathcost[root] = 0;
		dfs(g, target, visited, res, pathcost);



		return res;
	}
private:
	
	int32_t dfs(Graph& g, int32_t root, std::vector<bool>& visited, std::vector<int32_t>& res, std::vector<int32_t>& pathcost) const
	{
		if (pathcost[root] < INT_MAX)
			pathcost[root];

		if (visited[root])
			return INT_MAX;

		visited[root] = true;

		int32_t w{ 0 };
		
		for (int32_t i = 0; i < g.getVertex(root).neighbours->size(); i++)
		{
			int32_t q = dfs(g, i, visited, res, pathcost);

			if(w> g.getVertex(root).weightTo->operator[](i) + q)
			{
				w = g.getVertex(root).weightTo->operator[](i) + q;
				res[root] = i;
			}
			


		}
		
		pathcost[root] = w;
		return pathcost[root];
	}
};