#include <boost/lambda/lambda.hpp>
#include <boost/format.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>

int main()
{
	using namespace boost;
	typedef std::istream_iterator<int> in;

	///std::for_each(in(std::cin), in(), std::cout << (_1 * 3) << " ");

	
	std::cout << format("%-20s %-20s %8.4f\n") % "Artist" % "Title" % -1.0233;
	std::cout << format("%-20s %-20s %8.2f\n") % "Merle" % "Blue" % 12.99;
}