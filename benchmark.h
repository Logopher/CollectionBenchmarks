#include <chrono>
#include <functional>

template<typename Unit>
long long benchmark(std::function<void()> callback);

template<typename Unit>
long long benchmark(std::function<void()> callback)
{
	auto start = std::chrono::high_resolution_clock::now();

	callback();

	auto end = std::chrono::high_resolution_clock::now();

	auto diff = end - start;

	return std::chrono::duration_cast<Unit>(diff).count();
}