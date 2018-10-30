#pragma once
#include <vector>

template <class WordSize>
class IEncoder {
public:
	virtual WordSize encode(const std::vector<WordSize> message, const std::vector<int> key);
	virtual WordSize decode(const std::vector<WordSize> message, const std::vector<int> key);
};

