



#include <vector>

struct FlowerGarden
{
	

	std::vector<int> getOrdering(std::vector<int> height, std::vector<int> bloom, std::vector<int> wilt)
	{
		
		
	}

	bool overlaps(int a ,int b,std::vector<int> bloom,std::vector<int>wilt)
	{
		return bloom[a] <= bloom[b] && wilt[a] >= bloom[b] || bloom[b] <= bloom[a] && wilt[b] >= bloom[a];
	}
};
