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

