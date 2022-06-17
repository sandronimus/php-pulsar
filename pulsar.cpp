/* pulsar extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_pulsar.h"
#include "pulsar_arginfo.h"

#include "pulsar_client.h"
#include "pulsar_producer.h"
#include "pulsar_message_builder.h"
#include "pulsar_message.h"

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

zend_class_entry *PulsarClient_ce;
zend_object_handlers PulsarClient_object_handlers;

zend_class_entry *PulsarProducer_ce;
zend_object_handlers PulsarProducer_object_handlers;

zend_class_entry *PulsarMessageBuilder_ce;
zend_object_handlers PulsarMessageBuilder_object_handlers;

zend_class_entry *PulsarMessage_ce;
zend_object_handlers PulsarMessage_object_handlers;

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(pulsar)
{
#if defined(ZTS) && defined(COMPILE_DL_PULSAR)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

    REGISTER_NS_LONG_CONSTANT("Pulsar", "ResultOk", pulsar::ResultOk, CONST_CS | CONST_PERSISTENT);

    PulsarClient_ce = register_class_Pulsar_Client();
    if (!PulsarClient_ce) {
        zend_error(E_ERROR, "Failed to register Pulsar\\Client class");
        return FAILURE;
    }
    PulsarClient_ce->create_object = PulsarClient_object_create;
    memcpy(&PulsarClient_object_handlers, zend_get_std_object_handlers(),
           sizeof PulsarClient_object_handlers);
    PulsarClient_object_handlers.offset =
            XtOffsetOf(PulsarClient_object, zo);
    PulsarClient_object_handlers.clone_obj = NULL; //no clone support
    PulsarClient_object_handlers.dtor_obj = PulsarClient_object_dtor;
    PulsarClient_object_handlers.free_obj = PulsarClient_object_free;

    PulsarProducer_ce = register_class_Pulsar_Producer();
    PulsarProducer_ce->create_object = PulsarProducer_object_create;
    if (!PulsarProducer_ce) {
        zend_error(E_ERROR, "Failed to register Pulsar\\Producer class");
        return FAILURE;
    }
    memcpy(&PulsarProducer_object_handlers, zend_get_std_object_handlers(),
           sizeof PulsarProducer_object_handlers);
    PulsarProducer_object_handlers.offset =
            XtOffsetOf(PulsarProducer_object, zo);
    PulsarProducer_object_handlers.clone_obj = NULL; //no clone support
    PulsarProducer_object_handlers.dtor_obj = PulsarProducer_object_dtor;
    PulsarProducer_object_handlers.free_obj = PulsarProducer_object_free;

    PulsarMessageBuilder_ce = register_class_Pulsar_MessageBuilder();
    PulsarMessageBuilder_ce->create_object = PulsarMessageBuilder_object_create;
    if (!PulsarMessageBuilder_ce) {
        zend_error(E_ERROR, "Failed to register Pulsar\\MessageBuilder class");
        return FAILURE;
    }
    memcpy(&PulsarMessageBuilder_object_handlers, zend_get_std_object_handlers(),
           sizeof PulsarMessageBuilder_object_handlers);
    PulsarMessageBuilder_object_handlers.offset =
            XtOffsetOf(PulsarMessageBuilder_object, zo);
    PulsarMessageBuilder_object_handlers.clone_obj = NULL; //no clone support
    PulsarMessageBuilder_object_handlers.dtor_obj = PulsarMessageBuilder_object_dtor;
    PulsarMessageBuilder_object_handlers.free_obj = PulsarMessageBuilder_object_free;

    PulsarMessage_ce = register_class_Pulsar_Message();
    PulsarMessage_ce->create_object = PulsarMessage_object_create;
    if (!PulsarMessage_ce) {
        zend_error(E_ERROR, "Failed to register Pulsar\\Message class");
        return FAILURE;
    }
    memcpy(&PulsarMessage_object_handlers, zend_get_std_object_handlers(),
           sizeof PulsarMessage_object_handlers);
    PulsarMessage_object_handlers.offset =
            XtOffsetOf(PulsarMessage_object, zo);
    PulsarMessage_object_handlers.clone_obj = NULL; //no clone support
    PulsarMessage_object_handlers.dtor_obj = PulsarMessage_object_dtor;
    PulsarMessage_object_handlers.free_obj = PulsarMessage_object_free;

    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(pulsar)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "pulsar support", "enabled");
	php_info_print_table_header(2, "pulsar client version", PHP_PULSAR_VERSION);
	php_info_print_table_end();
}
/* }}} */

/* {{{ pulsar_module_entry */
zend_module_entry pulsar_module_entry = {
	STANDARD_MODULE_HEADER,
	"pulsar",					/* Extension name */
	class_Pulsar_Client_methods,					/* zend_function_entry */
    PHP_MINIT(pulsar),							/* PHP_MINIT - Module initialization */
	NULL,							/* PHP_MSHUTDOWN - Module shutdown */
	NULL,			/* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(pulsar),			/* PHP_MINFO - Module info */
	PHP_PULSAR_VERSION,		/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_PULSAR
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(pulsar)
#endif
