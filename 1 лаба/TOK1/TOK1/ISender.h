#pragma once
#include <memory> 

class Channel;

template <class MessageType>
class ISender {
public:
	virtual bool SendMessage(std::shared_ptr<Channel> channel, const MessageType messeage);
};