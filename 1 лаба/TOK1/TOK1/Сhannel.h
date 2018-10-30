#pragma once
#include "IMessageClient.h"
#include <string>

class Channel : public IMessageClient<std::string> {
public:
	void decipher();
public:

private:
};