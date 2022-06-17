#include "pulsar_producer.h"
#include "pulsar_message.h"

/* {{{ PulsarProducer_objects_dtor */
void PulsarProducer_object_dtor(zend_object *object)
{
    zend_objects_destroy_object(object);
}
/* }}} */

/* {{{ PulsarProducer_objects_free */
void PulsarProducer_object_free(zend_object *object)
{
    PulsarProducer_object *ptr = php_pulsar_producer_fetch_object(object);

    zend_object_std_dtor(&ptr->zo);

    if (ptr->producer) {
        delete ptr->producer;
        ptr->producer = nullptr;
    }
}
/* }}} */

/* {{{ PulsarProducer_object_create */
zend_object *PulsarProducer_object_create(zend_class_entry *ce)
{
    PulsarProducer_object* intern;

    intern = (PulsarProducer_object *)ecalloc(1, sizeof(PulsarProducer_object) + zend_object_properties_size(ce));

    zend_object_std_init(&intern->zo, ce);
    object_properties_init(&intern->zo, ce);
    intern->producer = nullptr;

    intern->zo.handlers = &PulsarProducer_object_handlers;

    return &intern->zo;
}
/* }}} */

/* {{{ proto Pulsar\Producer::send(Pulsar\Message $message): int
 */
PHP_METHOD(Pulsar_Producer, send)
{
    zend_object *messageZendObject;
    PulsarMessage_object *message;

    zval *object;
    PulsarProducer_object *producer;

    ZEND_PARSE_PARAMETERS_START(1, 1)
            Z_PARAM_OBJ(messageZendObject)
    ZEND_PARSE_PARAMETERS_END();

    object = getThis();
    message = php_pulsar_message_fetch_object(messageZendObject);
    producer = php_pulsar_producer_fetch_object(Z_OBJ_P(object));

    RETURN_LONG(producer->producer->send(message->message));
}
/* }}} */
