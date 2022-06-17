#include "pulsar_message.h"

/* {{{ PulsarMessage_objects_dtor */
void PulsarMessage_object_dtor(zend_object *object)
{
    zend_objects_destroy_object(object);
}
/* }}} */

/* {{{ PulsarMessage_objects_free */
void PulsarMessage_object_free(zend_object *object)
{
    PulsarMessage_object *ptr = php_pulsar_message_fetch_object(object);

    zend_object_std_dtor(&ptr->zo);

//    if (ptr->message) {
//        delete ptr->message;
//        ptr->message = nullptr;
//    }
}
/* }}} */

/* {{{ PulsarMessage_object_create */
zend_object *PulsarMessage_object_create(zend_class_entry *ce)
{
    PulsarMessage_object* intern;

    intern = (PulsarMessage_object*)ecalloc(1, sizeof(PulsarMessage_object) + zend_object_properties_size(ce));

    zend_object_std_init(&intern->zo, ce);
    object_properties_init(&intern->zo, ce);
//    intern->message = nullptr;

    intern->zo.handlers = &PulsarMessage_object_handlers;

    return &intern->zo;
}
/* }}} */

/* {{{ proto Pulsar\MessageMessage::getDataAsString(): string
 */
PHP_METHOD(Pulsar_Message, getDataAsString)
{
    zval *object;
    PulsarMessage_object* ptr;

    ZEND_PARSE_PARAMETERS_START(0, 0)
    ZEND_PARSE_PARAMETERS_END();

    object = getThis();
    ptr = php_pulsar_message_fetch_object(Z_OBJ_P(object));

    std::string data = ptr->message.getDataAsString();
    RETURN_STRING(data.c_str());
}
/* }}} */

/* {{{ proto Pulsar\MessageMessage::getProperties(): array
 */
PHP_METHOD(Pulsar_Message, getProperties)
{
    zval *object;
    PulsarMessage_object* ptr;

    ZEND_PARSE_PARAMETERS_START(0, 0)
    ZEND_PARSE_PARAMETERS_END();

    object = getThis();
    ptr = php_pulsar_message_fetch_object(Z_OBJ_P(object));

    const pulsar::StringMap &data = ptr->message.getProperties();
    zend_array *ret = zend_new_array(data.size());

    for (auto i = data.cbegin(); i != data.cend(); i++) {
        zend_string *key = zend_string_init(i->first.c_str(), i->first.length(), true);
        zval value;
        ZVAL_STRING(&value, i->second.c_str());
        zend_hash_add(ret, key, &value);
    }

    RETVAL_ARR(ret);
}
/* }}} */
