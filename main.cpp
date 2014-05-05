#include <iostream>
#include <functional>
#include <map>
#include <random>
#include <chrono>

#include <cstdio>
#include <cinttypes>

#include "benchmark.h"

#include "MapSpotter.h"
#include "ArrayMap.h"

template<typename Map>
void insert(Map map)
{
	int key;
	Map::iterator it;
	do
	{
		key = std::rand();
		it = map.find(key);
	}
	while (it != map.end());

	map[key] = std::rand();
}

void main()
{
	std::cout << std::chrono::high_resolution_clock::period::den << std::endl;

	getchar();

	MapSpotter spotter{};

	printf("Reps, std::map, std::unordered_map, prealloc'd std::unordered_map,\n");

	for (int i = 1; i <= 500; i++)
	{
		printf("%i, %"PRId64", %"PRId64", %"PRId64", \n", i,
			spotter.spotStlMap<int, int>(i, insert),
			spotter.spotStlUnorderedMap<int, int>(i, insert),
			spotter.spotStlUnorderedMap_prealloc<int, int>(i, insert));
	}

	getchar();
}