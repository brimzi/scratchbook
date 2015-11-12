#include "stdafx.h"
#include <iostream>
#include <array>
#include <vector>
#include <algorithm>


struct topDownCuttingRod {

	template<size_t SIZE>
	uint32_t operator()(std::array<uint32_t, SIZE> prices, size_t length) {
		std::vector<uint32_t> derivedPrices(length + 1);
		return calculateDownCuttingRod(prices, derivedPrices, length);
	}

private:
	template<size_t SIZE>
	uint32_t calculateDownCuttingRod(std::array<uint32_t, SIZE>& prices, std::vector<uint32_t>& derivedPrices, size_t length) {
		if (length == 0)
			return 0;
		if (length == 1)
			return prices[1];
		if (derivedPrices[length] > 0)
			return derivedPrices[length];

		uint32_t q{ 0 };
		
		for (size_t i = 1; i <= length; i++) {
			q = std::max(q, prices[i] + calculateDownCuttingRod(prices, derivedPrices, length - i));
		}
		derivedPrices[length] = q;
		return q;
	}
};

struct bottomUpCuttingRod {
	template<size_t SIZE>
	uint32_t operator()(std::array<uint32_t, SIZE> prices, size_t length) {
		
		uint32_t p;
		std::vector<uint32_t> optimal(length+1);

		for (uint32_t i = 1; i <= length; i++) {
			uint32_t q{ 0 };
			for (uint32_t j = 1; j <= i; j++) {
				q = std::max(q, prices[j] + optimal[i - j]);
			}
			optimal[i] = q;
		}
		return optimal[length];
	}


};




int main() {
	topDownCuttingRod topdown;
	bottomUpCuttingRod bottomup;
	std::array<uint32_t, 11> prices{0,1,5,8,9,10,17,17,20,24,30};
	
	auto max1=topdown(prices, 9);
	std::cout << max1 << std::endl;

	auto max2 = bottomup(prices, 9);
	std::cout << max2 << std::endl;


	char k;
	std::cin>>k;


}