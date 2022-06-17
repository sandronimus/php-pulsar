/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 1754bf22ce1fe6f198796b1f4d01ba8e10ab0e74 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pulsar_Client___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, serviceUrl, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pulsar_Client_createProducer, 0, 1, Pulsar\\Producer, 0)
	ZEND_ARG_TYPE_INFO(0, topic, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pulsar_Client_subscribe, 0, 2, Pulsar\\Consumer, 0)
	ZEND_ARG_TYPE_INFO(0, topic, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, subscriptionName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pulsar_Producer_send, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, message, Pulsar\\Message, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pulsar_MessageBuilder___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pulsar_MessageBuilder_setContent, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, content, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pulsar_MessageBuilder_setProperties, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, properties, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pulsar_MessageBuilder_build, 0, 0, Pulsar\\Message, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pulsar_Message_getDataAsString, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pulsar_Message_getProperties, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Pulsar_Consumer_receive arginfo_class_Pulsar_MessageBuilder_build

#define arginfo_class_Pulsar_Consumer_acknowledge arginfo_class_Pulsar_Producer_send

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Pulsar_Consumer_negativeAcknowledge, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, message, Pulsar\\Message, 0)
ZEND_END_ARG_INFO()


ZEND_METHOD(Pulsar_Client, __construct);
ZEND_METHOD(Pulsar_Client, createProducer);
ZEND_METHOD(Pulsar_Client, subscribe);
ZEND_METHOD(Pulsar_Producer, send);
ZEND_METHOD(Pulsar_MessageBuilder, __construct);
ZEND_METHOD(Pulsar_MessageBuilder, setContent);
ZEND_METHOD(Pulsar_MessageBuilder, setProperties);
ZEND_METHOD(Pulsar_MessageBuilder, build);
ZEND_METHOD(Pulsar_Message, getDataAsString);
ZEND_METHOD(Pulsar_Message, getProperties);
ZEND_METHOD(Pulsar_Consumer, receive);
ZEND_METHOD(Pulsar_Consumer, acknowledge);
ZEND_METHOD(Pulsar_Consumer, negativeAcknowledge);


static const zend_function_entry class_Pulsar_Client_methods[] = {
	ZEND_ME(Pulsar_Client, __construct, arginfo_class_Pulsar_Client___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Pulsar_Client, createProducer, arginfo_class_Pulsar_Client_createProducer, ZEND_ACC_PUBLIC)
	ZEND_ME(Pulsar_Client, subscribe, arginfo_class_Pulsar_Client_subscribe, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Pulsar_Producer_methods[] = {
	ZEND_ME(Pulsar_Producer, send, arginfo_class_Pulsar_Producer_send, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Pulsar_MessageBuilder_methods[] = {
	ZEND_ME(Pulsar_MessageBuilder, __construct, arginfo_class_Pulsar_MessageBuilder___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Pulsar_MessageBuilder, setContent, arginfo_class_Pulsar_MessageBuilder_setContent, ZEND_ACC_PUBLIC)
	ZEND_ME(Pulsar_MessageBuilder, setProperties, arginfo_class_Pulsar_MessageBuilder_setProperties, ZEND_ACC_PUBLIC)
	ZEND_ME(Pulsar_MessageBuilder, build, arginfo_class_Pulsar_MessageBuilder_build, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Pulsar_Message_methods[] = {
	ZEND_ME(Pulsar_Message, getDataAsString, arginfo_class_Pulsar_Message_getDataAsString, ZEND_ACC_PUBLIC)
	ZEND_ME(Pulsar_Message, getProperties, arginfo_class_Pulsar_Message_getProperties, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_Pulsar_Consumer_methods[] = {
	ZEND_ME(Pulsar_Consumer, receive, arginfo_class_Pulsar_Consumer_receive, ZEND_ACC_PUBLIC)
	ZEND_ME(Pulsar_Consumer, acknowledge, arginfo_class_Pulsar_Consumer_acknowledge, ZEND_ACC_PUBLIC)
	ZEND_ME(Pulsar_Consumer, negativeAcknowledge, arginfo_class_Pulsar_Consumer_negativeAcknowledge, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Pulsar_Client(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pulsar", "Client", class_Pulsar_Client_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	return class_entry;
}

static zend_class_entry *register_class_Pulsar_Producer(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pulsar", "Producer", class_Pulsar_Producer_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	return class_entry;
}

static zend_class_entry *register_class_Pulsar_MessageBuilder(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pulsar", "MessageBuilder", class_Pulsar_MessageBuilder_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	return class_entry;
}

static zend_class_entry *register_class_Pulsar_Message(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pulsar", "Message", class_Pulsar_Message_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	return class_entry;
}

static zend_class_entry *register_class_Pulsar_Consumer(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Pulsar", "Consumer", class_Pulsar_Consumer_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

	return class_entry;
}
