/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: a182c3f5ccf9247c9ccdb4a9732b80825e06d2d1 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Pulsar_Client___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, serviceUrl, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Pulsar_Client_createProducer, 0, 1, Pulsar\\Producer, 0)
	ZEND_ARG_TYPE_INFO(0, topic, IS_STRING, 0)
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


ZEND_METHOD(Pulsar_Client, __construct);
ZEND_METHOD(Pulsar_Client, createProducer);
ZEND_METHOD(Pulsar_Producer, send);
ZEND_METHOD(Pulsar_MessageBuilder, __construct);
ZEND_METHOD(Pulsar_MessageBuilder, setContent);
ZEND_METHOD(Pulsar_MessageBuilder, setProperties);
ZEND_METHOD(Pulsar_MessageBuilder, build);


static const zend_function_entry class_Pulsar_Client_methods[] = {
	ZEND_ME(Pulsar_Client, __construct, arginfo_class_Pulsar_Client___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Pulsar_Client, createProducer, arginfo_class_Pulsar_Client_createProducer, ZEND_ACC_PUBLIC)
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
