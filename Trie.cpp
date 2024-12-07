#include "Trie.h"
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

Trie::Trie() : m_isTerminal(false) {}

Trie::~Trie() {}

void Trie::insert(const std::string &str)
{
    Trie *node = this;
    for (char c : str)
	{
        if (node->m_children.find(c) == node->m_children.end()) {
            node->m_children[c] = std::make_unique<Trie>();
        }
        node = node->m_children[c].get();
    }
    node->m_isTerminal = true;
}

bool Trie::contains(const std::string &str)
{
	Trie *node = this;
	for (char c : str)
	{
		if (node->m_children.find(c) == node->m_children.end()) { 
			return false;
		}
		node = node->m_children[c].get();
	}
	return node->m_isTerminal;
}

bool Trie::remove(const std::string &str)
{
	return removeHelper(str, 0);
}

bool Trie::removeHelper(const std::string &str, int depth)
{
    if (depth == static_cast<int>(str.size()))
	{
        if (!m_isTerminal) {
            return false;
        }

        m_isTerminal = false;
        return m_children.empty();
    }

    char c = str[depth];
    auto it = m_children.find(c);
    if (it == m_children.end()) {
        return false;
    }

    bool child_can_be_deleted = it->second->removeHelper(str, depth + 1);
    if (child_can_be_deleted)
	{
        m_children.erase(it);
        return !m_isTerminal && m_children.empty();
    }

    return false;
}

// Explicit template instantiation for commonly used iterator types

// std::vector
template Trie::Trie<vector<string>::iterator>(
    vector<string>::iterator begin, vector<string>::iterator end);
template Trie::Trie<vector<string>::const_iterator>(
    vector<string>::const_iterator begin, vector<string>::const_iterator end);

// std::set
template Trie::Trie<set<string>::iterator>(
    set<string>::iterator begin, set<string>::iterator end);

// std::unordered_set
template Trie::Trie<unordered_set<string>::iterator>(
    unordered_set<string>::iterator begin, unordered_set<string>::iterator end);
template Trie::Trie<unordered_set<string>::const_iterator>(
    unordered_set<string>::const_iterator begin, unordered_set<string>::const_iterator end);