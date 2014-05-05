#include <map>
#include <unordered_map>

class MapSpotter
{
public:
	template<typename K, typename V>
	long long spotStlMap(int reps, void(&callback)(std::map<K, V>));

	template<typename K, typename V>
	long long spotStlUnorderedMap(int reps, void(&callback)(std::unordered_map<K, V>));

	template<typename K, typename V>
	long long spotStlUnorderedMap_prealloc(int reps, void(&callback)(std::unordered_map<K, V>));
};

template<typename K, typename V>
long long MapSpotter::spotStlMap(int reps, void(&callback)(std::map<K, V>))
{
	std::map<K, V> map{};

	auto results = benchmark<std::chrono::microseconds>([map, reps, &callback]()
	{
		for (int i = 0; i < reps; i++)
		{
			callback(map);
		}
	});

	return results / reps;
}

template<typename K, typename V>
long long MapSpotter::spotStlUnorderedMap(int reps, void(&callback)(std::unordered_map<K, V>))
{
	std::unordered_map<K, V> map{};

	auto results = benchmark<std::chrono::microseconds>([map, reps, &callback]()
	{
		for (int i = 0; i < reps; i++)
		{
			callback(map);
		}
	});

	return results / reps;
}

template<typename K, typename V>
long long MapSpotter::spotStlUnorderedMap_prealloc(int reps, void(&callback)(std::unordered_map<K, V>))
{
	std::unordered_map<K, V> map{};

	map.reserve(reps);

	auto results = benchmark<std::chrono::microseconds>([map, reps, &callback]()
	{
		for (int i = 0; i < reps; i++)
		{
			callback(map);
		}
	});

	return results / reps;
}