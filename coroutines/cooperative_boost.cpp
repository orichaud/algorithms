#include <boost/coroutine2/all.hpp>
#include <iostream>
#include <map>

// This requires the installation of boost
// for exampel: brew install boost will solve this

using namespace boost::coroutines2;

typedef int value_t;
typedef std::string _key_t;
typedef std::map<_key_t, value_t> map_t;

const map_t&  get_map() noexcept
{
	static const map_t map = {
		{ "hello", 1 },
		{ "world", 2 },
		{ "it's",  3 },
		{ "me",    4 },
	};
	return map;
}

void cooperative(coroutine<value_t>::push_type &sink, const std::string &init)
{
	std::cout << "1 ";
	const auto &map = get_map();
	auto it = map.find(init);
	if(it != map.end()) {
		const auto &value = (*it).second;
		sink(value);
	}
	std::cout << "3 ";
}

int main()
{
	for (const auto& [ k, v ] : get_map()) {
		std::cout << "k=" << k << " v=" << v << '\n';
	}
	
	coroutine<value_t>::pull_type source{ std::bind(cooperative, std::placeholders::_1, "hello") };
	
	auto v = source.get();
	std::cout << "2(" << v << ") ";
	
	source();
	
	std::cout << "!\n";
}

