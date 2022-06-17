#include "pulsar_consumer.h"
#include "pulsar_message.h"

/* {{{ PulsarConsumer_objects_dtor */
void PulsarConsumer_object_dtor(zend_object *object)
{
    zend_objects_destroy_object(object);
}
/* }}} */

/* {{{ PulsarConsumer_objects_free */
void PulsarConsumer_object_free(zend_object *object)
{
    PulsarConsumer_object *ptr = php_pulsar_consumer_fetch_object(object);

    zend_object_std_dtor(&ptr->zo);

    if (ptr->consumer) {
        delete ptr->consumer;
        ptr->consumer = nullptr;
    }
}
/* }}} */

/* {{{ PulsarConsumer_object_create */
zend_object *PulsarConsumer_object_create(zend_class_entry *ce)
{
    PulsarConsumer_object* intern;

    intern = (PulsarConsumer_object*)ecalloc(1, sizeof(PulsarConsumer_object) + zend_object_properties_size(ce));

    zend_object_std_init(&intern->zo, ce);
    object_properties_init(&intern->zo, ce);
    intern->consumer = nullptr;

    intern->zo.handlers = &PulsarConsumer_object_handlers;

    return &intern->zo;
}
/* }}} */

/* {{{ proto Pulsar\Consumer::receive(): Pulsar\Message
 */
PHP_METHOD(Pulsar_Consumer, receive)
{
    zval *object;
    PulsarConsumer_object *ptr;

    ZEND_PARSE_PARAMETERS_START(0, 0)
    ZEND_PARSE_PARAMETERS_END();

    object = getThis();
    ptr = php_pulsar_consumer_fetch_object(Z_OBJ_P(object));

    object_init_ex(return_value, PulsarMessage_ce);
    PulsarMessage_object *pulsarMessageObject = php_pulsar_message_fetch_object(Z_OBJ_P(return_value));
    ptr->consumer->receive(pulsarMessageObject->message);
}
/* }}} */

/* {{{ proto Pulsar\Client::acknowledge(Pulsar\Message $message): int
 */
PHP_METHOD(Pulsar_Consumer, acknowledge)
{
    zend_object *message;
    zval *object;
    PulsarConsumer_object *ptr;

    ZEND_PARSE_PARAMETERS_START(1, 1)
            Z_PARAM_OBJ(message)
    ZEND_PARSE_PARAMETERS_END();

    object = getThis();
    ptr = php_pulsar_consumer_fetch_object(Z_OBJ_P(object));

    PulsarMessage_object *pulsarMessageObject = php_pulsar_message_fetch_object(message);
    RETURN_LONG(ptr->consumer->acknowledge(pulsarMessageObject->message));
}
/* }}} */

/* {{{ proto Pulsar\Client::negativeAcknowledge(Pulsar\Message $message): void
 */
PHP_METHOD(Pulsar_Consumer, negativeAcknowledge)
{
    zend_object *message;
    zval *object;
    PulsarConsumer_object *ptr;

    ZEND_PARSE_PARAMETERS_START(1, 1)
            Z_PARAM_OBJ(message)
    ZEND_PARSE_PARAMETERS_END();

    object = getThis();
    ptr = php_pulsar_consumer_fetch_object(Z_OBJ_P(object));

    PulsarMessage_object *pulsarMessageObject = php_pulsar_message_fetch_object(message);
    ptr->consumer->negativeAcknowledge(pulsarMessageObject->message);
}
/* }}} */