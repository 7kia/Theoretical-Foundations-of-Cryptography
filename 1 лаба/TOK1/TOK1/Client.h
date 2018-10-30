#pragma once
#include "IMessageClient.h"
#include "libSrc/CryptoPrimitives.h"

class Client: public IMessageClient<string> {
public:
	Client();
private:
	std::shared_ptr<IEncoder> m_encoder;
	std::map<string, std::shared_ptr<Channel>> userNameForUserID;
};