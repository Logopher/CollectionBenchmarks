#include <vector>
#include <utility>

template<typename K, typename V>
class ArrayMap
{
	using Vector = std::vector<std::pair<K, V>>;

public:
	using iterator = typename Vector::iterator;

	ArrayMap();
};

template<typename K, typename V>
ArrayMap<K, V>::ArrayMap()
{

}