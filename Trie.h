#ifndef TRIE_H
#define TRIE_H

#include <unordered_map>
#include <string>
#include <memory>

class Trie
{
public:
	Trie();

	template <typename Iterator>
	Trie(Iterator begin, Iterator end)
	{
		for (; begin != end; ++begin) {
			insert(*begin);
		}
	}

	~Trie();

	void insert(const std::string &str);
	bool contains(const std::string &str);
	bool remove(const std::string &str);

private:
	bool removeHelper(const std::string &str, int depth);

private:
	std::unordered_map<char, std::unique_ptr<Trie>> m_children;
	bool m_isTerminal;
};

#endif