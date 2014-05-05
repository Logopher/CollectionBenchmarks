#ifndef ARRAYMAP_H
#define ARRAYMAP_H

#include <vector>
#include <utility>
#include <algorithm>

template<typename K, typename V>
class ArrayMap
{
	using Pair = std::pair<K, V>;
	using PairVector = std::vector<Pair>;

	PairVector data;

public:
	using iterator = typename PairVector::iterator;
	using const_iterator = typename PairVector::const_iterator;
	using size_type = typename PairVector::size_type;

	iterator begin()
	{
		return data.begin();
	}

	iterator end()
	{
		return data.end();
	}

	iterator cbegin()
	{
		return data.cbegin();
	}

	iterator cend()
	{
		return data.cend();
	}

private:
	iterator findSlot(const K & key)
	{
		return std::find_if(begin(), end(), [&key](const Pair & p)
		{
			return p.first >= key;
		});
	}
	const_iterator findSlot(const K & key) const
	{
		return std::find_if(cbegin(), cend(), [&key](const Pair & p)
		{
			return p.first >= key;
		});
	}

public:
	ArrayMap();

	void reserve(size_type size)
	{
		data.reserve(size);
	}

	iterator find(const K & key)
	{
		return std::find_if(begin(), end(), [&key](const Pair & p)
		{
			return p.first == key;
		});
	}

	const_iterator find(const K & key) const
	{
		return std::find_if(cbegin(), cend(), [&key](const Pair & p)
		{
			return p.first == key;
		});
	}

	V & operator[](const K & key)
	{
		auto it = findSlot(key);
		if (it == end() || it->first != key)
		{
			it = data.insert(it, Pair(key, V()));
		}

		return it->second;
	}

	V & operator[](K && key)
	{
		auto it = findSlot(key);
		if (it == end() || it->first != key)
		{
			it = data.insert(it, Pair(key, V()));
		}

		return it->second;
	}
};

template<typename K, typename V>
ArrayMap<K, V>::ArrayMap()
{

}

#endif // ARRAYMAP_H