


#include <cstdint>
#include <string>
#include <vector>
#include <sstream>

struct AvoidRoadsTopDown
{
	
	int64_t numWays(int width, int height, std::vector<std::string> bad)
	{
		if (width == 0 || height == 0)
			return 0;

		std::vector<std::vector<int>> blocks;
		for(auto s: bad)
		{
			auto coordinates = split(s, ' ');
			blocks.push_back(coordinates);
		}

		std::vector<std::vector<int64_t>> points(width+1);

		for (int i = 0; i < width + 1;i++)
		{
			points.push_back(std::vector<int64_t>(height + 1,INT64_MIN));
		}

		points[0][0] = 1;

		return numWaysTopDown(width,height,points,blocks);
	}

private:
	bool roadBlockExists(int fromx, int fromy, int tox, int toy, std::vector<std::vector<int>>& blocks)
	{
		return false;
	}

	int64_t numWaysTopDown(int width, int height, std::vector<std::vector<int64_t>> points, std::vector<std::vector<int>>& blocks)
	{
		if (width < 0 || height < 0)
			return 0;

		if (points[width][height]>INT64_MIN)
			return points[width][height];

		int64_t left(0);
		if(!roadBlockExists(width - 1, height, width, height,blocks))
		{
			left= numWaysTopDown(width - 1, height, points, blocks);
		}

		int64_t below(0);
		if (!roadBlockExists(width, height-1, width, height,blocks))
		{
			below = numWaysTopDown(width, height-1, points, blocks);
		}

		points[width][height] = left+below;
		return points[width][height];
	}

	std::vector<int> &split(const std::string &s, char delim, std::vector<int> &elems) {
		std::stringstream ss(s);
		std::string item;
		while (std::getline(ss, item, delim)) {
			elems.push_back(std::stoi(item));
		}
		return elems;
	}

	std::vector<int> split(const std::string &s, char delim) {
		std::vector<int> elems;
		split(s, delim, elems);
		return elems;
	}
};
