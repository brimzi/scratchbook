


#include <cstdint>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <utility>

struct AvoidRoadsTopDown
{
	
	int64_t numWays(int width, int height, std::vector<std::string> bad)
	{
		if (width == 0 || height == 0)
			return 0;

		
		std::set<std::pair<std::pair<int, int>, std::pair<int, int>>> blocks2;
		for(auto s: bad)
		{
			blocks2.insert(split2(s));
		}

		std::vector<std::vector<int64_t>> points(width+1);

		for (int i = 0; i < width + 1;i++)
		{
			points.push_back(std::vector<int64_t>(height + 1,INT64_MIN));
		}

		points[0][0] = 1;

		return numWaysTopDown(width,height,points,blocks2);
	}

private:
	bool roadBlockExists(int fromx, int fromy, int tox, int toy,const std::set<std::pair<std::pair<int, int>, std::pair<int, int>>>& blocks)
	{
		auto from = std::make_pair(fromx, fromy);
		auto to = std::make_pair(tox, tox);
		auto bad = std::make_pair(from, to);

		return blocks.find(bad)!=blocks.end();
	}

	int64_t numWaysTopDown(int width, int height, std::vector<std::vector<int64_t>> points, const std::set<std::pair<std::pair<int, int>, std::pair<int, int>>>& blocks)
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

	

	

	std::pair<std::pair<int, int>, std::pair<int, int>> &split2(const std::string &s) {
		const char delim = ' ';
		std::stringstream ss(s);
		std::string item;
		
		std::getline(ss, item, delim);
		int point1x=std::stoi(item);

		std::getline(ss, item, delim);
		int point1y = std::stoi(item);

		std::getline(ss, item, delim);
		int point2x = std::stoi(item);

		std::getline(ss, item, delim);
		int point2y = std::stoi(item);


		//TODO make sure you follow one scheme(either from < to or to < from) for all bad
		std::pair<int, int> from(point1x,point1y);
		std::pair<int, int> to(point2x, point2y);
		std::pair<std::pair<int,int>, std::pair<int,int>> bad(from, to);

		return bad;
	}
};
