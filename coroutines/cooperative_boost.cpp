#include <boost/coroutine2/all.hpp>
#include <iostream>

// This requires the installation of boost
// for example: brew install boost will solve this

using namespace boost::coroutines2;

void cooperative(coroutine<std::string>::push_type &sink, const std::string &value)
{
	std::cout << "This is ";

	sink(value);
	
	std::cout << " world!";
}

int main()
{
	auto fn = std::bind(cooperative, std::placeholders::_1, "hello");
	coroutine<std::string>::pull_type source{ fn };
	auto v = source.get();
	std::cout << v;
	source();
	std::cout << std::endl;
}

