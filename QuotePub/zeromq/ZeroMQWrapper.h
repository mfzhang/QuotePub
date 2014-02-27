#pragma once
class ZeroMQWrapper
{
public:
	ZeroMQWrapper(void);
	~ZeroMQWrapper(void);
	int init();
	void cleanup();
	int pub(const void* buf, size_t len);

private:
	void *context;
	void *publisher;
};

