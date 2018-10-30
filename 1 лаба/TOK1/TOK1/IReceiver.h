#pragma once
#include <memory> 

class Channel;

template <class MessageType>
class IReceiver {
public:
	virtual void acceptMessage(const std::shared_ptr<Channel> channel, const MessageType message);
};