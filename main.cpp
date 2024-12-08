#include "Trie.h"
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

int main(void)
{
	const std::vector<std::string>			words {"he", "hell", "hello", "wo", "world"};
	// const std::set<std::string>				words {"he", "hell", "hello", "wo", "world"};
	// const std::unordered_set<std::string>	words {"he", "hell", "hello", "wo", "world"};
	
	Trie trie(words.begin(), words.end());

	std::cout << "Contains \"hello\" : " << std::boolalpha << trie.contains("hello") << std::noboolalpha << std::endl;
	std::cout << "Contains \"hel\"   : " << std::boolalpha << trie.contains("hel"  ) << std::noboolalpha << std::endl;
	std::cout << "Contains \"hell\"  : " << std::boolalpha << trie.contains("hell" ) << std::noboolalpha << std::endl;
	std::cout << "Contains \"wor\"   : " << std::boolalpha << trie.contains("wor"  ) << std::noboolalpha << std::endl;
	std::cout << "Contains \"world\" : " << std::boolalpha << trie.contains("world") << std::noboolalpha << std::endl;
	std::cout << "Contains \"wo\"    : " << std::boolalpha << trie.contains("wo"   ) << std::noboolalpha << std::endl;

	std::cout << "\nRemove \"hello\" : " << std::boolalpha << trie.remove("hello"   ) << std::noboolalpha << std::endl;
	std::cout << "Remove \"worl\"  : "   << std::boolalpha << trie.remove("worl"    ) << std::noboolalpha << std::endl;

	std::cout << "\nContains \"hello\" : " << std::boolalpha << trie.contains("hello") << std::noboolalpha << std::endl;

	return 0;
}