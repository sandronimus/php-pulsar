#include "pulsar_client.h"
#include "pulsar_producer.h"

/* {{{ PulsarClient_objects_dtor */
void PulsarClient_object_dtor(zend_object *object)
{
    zend_objects_destroy_object(object);
}
/* }}} */

/* {{{ PulsarClient_objects_free */
void PulsarClient_object_free(zend_object *object)
{
    PulsarClient_object *ptr = php_pulsar_client_fetch_object(object);

    zend_object_std_dtor(&ptr->zo);

    if (ptr->client) {
        delete ptr->client;
        ptr->client = nullptr;
    }
}
/* }}} */

/* {{{ PulsarClient_object_create */
zend_object *PulsarClient_object_create(zend_class_entry *ce)
{
    PulsarClient_object* intern;

    intern = (PulsarClient_object*)ecalloc(1, sizeof(PulsarClient_object) + zend_object_properties_size(ce));

    zend_object_std_init(&intern->zo, ce);
    object_properties_init(&intern->zo, ce);
    intern->client = nullptr;

    intern->zo.handlers = &PulsarClient_object_handlers;

    return &intern->zo;
}
/* }}} */

/* {{{ proto void Pulsar\Client::__construct(string $serviceUrl)
 * PulsarClient object constructor.
 */
PHP_METHOD(Pulsar_Client, __construct)
{
    zend_string *serviceUrl;
    zval *object;
    PulsarClient_object* ptr = nullptr;

    ZEND_PARSE_PARAMETERS_START(1, 1)
            Z_PARAM_STR(serviceUrl)
    ZEND_PARSE_PARAMETERS_END();

    object = getThis();
    ptr = php_pulsar_client_fetch_object(Z_OBJ_P(object));

    ptr->client = new pulsar::Client(ZSTR_VAL(serviceUrl));
}
/* }}} */

/* {{{ proto Pulsar\Client::createProducer(string $topic): Pulsar\Producer
 */
PHP_METHOD(Pulsar_Client, createProducer)
{
    zend_string *topic;
    zval *object;
    PulsarClient_object* ptr = nullptr;

    ZEND_PARSE_PARAMETERS_START(1, 1)
            Z_PARAM_STR(topic)
    ZEND_PARSE_PARAMETERS_END();

    object = getThis();
    ptr = php_pulsar_client_fetch_object(Z_OBJ_P(object));

    object_init_ex(return_value, PulsarProducer_ce);
    PulsarProducer_object *pulsarProducerObject = php_pulsar_producer_fetch_object(Z_OBJ_P(return_value));
    pulsarProducerObject->producer = new pulsar::Producer();
    if (ptr->client->createProducer(ZSTR_VAL(topic), *pulsarProducerObject->producer) != pulsar::ResultOk) {
        RETURN_THROWS();
    }
}
/* }}} */
