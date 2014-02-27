#include "stdafx.h"

#include "ZeroMQWrapper.h"

#include "zmq.h"
#include "zmq_utils.h"


ZeroMQWrapper::ZeroMQWrapper(void)
{
}


ZeroMQWrapper::~ZeroMQWrapper(void)
{
}

int ZeroMQWrapper::init()
{
	context = zmq_ctx_new();
	publisher = zmq_socket(context, ZMQ_PUB);

	int rc = zmq_bind(publisher, "tcp://*:5556");
	if (rc != 0)
	{
		
	}

	return rc;
}

int ZeroMQWrapper::pub(const void* buf, size_t len)
{
	int rc = 0;

	rc = zmq_send(publisher, buf, len, 0);

	return rc;
}



void ZeroMQWrapper::cleanup()
{
	if(publisher != NULL)
	{
		zmq_close(publisher);
	}

	if (context != NULL)
	{
		zmq_ctx_destroy(context);
	}
}
