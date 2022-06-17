#include "pulsar_message_builder.h"
#include "pulsar_message.h"
#include <iostream>

/* {{{ PulsarMessageBuilder_objects_dtor */
void PulsarMessageBuilder_object_dtor(zend_object *object)
{
    zend_objects_destroy_object(object);
}
/* }}} */

/* {{{ PulsarMessageBuilder_objects_free */
void PulsarMessageBuilder_object_free(zend_object *object)
{
    PulsarMessageBuilder_object *ptr = php_pulsar_message_builder_fetch_object(object);

    zend_object_std_dtor(&ptr->zo);

    if (ptr->message_builder) {
        delete ptr->message_builder;
        ptr->message_builder = nullptr;
    }
}
/* }}} */

/* {{{ PulsarMessageBuilder_object_create */
zend_object *PulsarMessageBuilder_object_create(zend_class_entry *ce)
{
    PulsarMessageBuilder_object* intern;

    intern = (PulsarMessageBuilder_object*)ecalloc(1, sizeof(PulsarMessageBuilder_object) + zend_object_properties_size(ce));

    zend_object_std_init(&intern->zo, ce);
    object_properties_init(&intern->zo, ce);
    intern->message_builder = nullptr;

    intern->zo.handlers = &PulsarMessageBuilder_object_handlers;

    return &intern->zo;
}
/* }}} */

/* {{{ proto void Pulsar\MessageBuilder::__construct()
 * PulsarMessageBuilder object constructor.
 */
PHP_METHOD(Pulsar_MessageBuilder, __construct)
{
    zval *object;
    PulsarMessageBuilder_object* ptr = nullptr;

    ZEND_PARSE_PARAMETERS_START(0, 0)
    ZEND_PARSE_PARAMETERS_END();

    object = getThis();
    ptr = php_pulsar_message_builder_fetch_object(Z_OBJ_P(object));

    ptr->message_builder = new pulsar::MessageBuilder();
}
/* }}} */

/* {{{ proto Pulsar\MessageBuilder::setContent(string $content): void
 */
PHP_METHOD(Pulsar_MessageBuilder, setContent)
{
    zend_string *content;
    zval *object;
    PulsarMessageBuilder_object * ptr = nullptr;

    ZEND_PARSE_PARAMETERS_START(1, 1)
            Z_PARAM_STR(content)
    ZEND_PARSE_PARAMETERS_END();

    object = getThis();
    ptr = php_pulsar_message_builder_fetch_object(Z_OBJ_P(object));

    ptr->message_builder->setContent(ZSTR_VAL(content));
}
/* }}} */

/* {{{ proto Pulsar\MessageBuilder::setProperties(array $properties): void
 */
PHP_METHOD(Pulsar_MessageBuilder, setProperties)
{
    zval *properties;
    zval *object;
    PulsarMessageBuilder_object * ptr = nullptr;

    ZEND_PARSE_PARAMETERS_START(1, 1)
            Z_PARAM_ARRAY(properties)
    ZEND_PARSE_PARAMETERS_END();

    object = getThis();
    ptr = php_pulsar_message_builder_fetch_object(Z_OBJ_P(object));

    zend_ulong idx;
    zend_string *key;
    zval *val;

    pulsar::StringMap pulsarProperties;
    ZEND_HASH_FOREACH_KEY_VAL(Z_ARR_P(properties), idx, key, val) {
        if (Z_TYPE_P(val) != IS_STRING) {
            zend_argument_value_error(1, "array values must be string");
            RETURN_THROWS();
        }
        pulsarProperties[ZSTR_VAL(key)] = ZSTR_VAL(Z_STR_P(val));
    } ZEND_HASH_FOREACH_END();

    ptr->message_builder->setProperties(pulsarProperties);
}
/* }}} */

/* {{{ proto Pulsar\MessageBuilder::build(): Pulsar\Message
 */
PHP_METHOD(Pulsar_MessageBuilder, build)
{
    zval *object;
    PulsarMessageBuilder_object* ptr = nullptr;

    ZEND_PARSE_PARAMETERS_START(0, 0)
    ZEND_PARSE_PARAMETERS_END();

    object = getThis();
    ptr = php_pulsar_message_builder_fetch_object(Z_OBJ_P(object));

    object_init_ex(return_value, PulsarMessage_ce);
    PulsarMessage_object *pulsarMessageObject = php_pulsar_message_fetch_object(Z_OBJ_P(return_value));
    pulsarMessageObject->message = ptr->message_builder->build();
}
/* }}} */

