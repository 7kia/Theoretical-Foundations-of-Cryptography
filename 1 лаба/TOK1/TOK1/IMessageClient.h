#pragma once
#include <memory>
#include "ISender.h"
#include "IReceiver.h"
#include "Ñhannel.h"

template <class MessageType>
class IMessageClient : public ISender<MessageType>, public IReceiver<MessageType> {
public:
	virtual bool connectToChannel(std::shared_ptr<Channel> channel, MessageType name);
}