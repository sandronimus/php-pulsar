#ifndef PULSAR_PHP_PULSAR_MESSAGE_H
#define PULSAR_PHP_PULSAR_MESSAGE_H

#include "php.h"
#include "php_pulsar.h"

extern zend_class_entry *PulsarMessage_ce;
extern zend_object_handlers PulsarMessage_object_handlers;

typedef struct {
    pulsar::Message message;
    zend_object zo;
} PulsarMessage_object;

static inline PulsarMessage_object *php_pulsar_message_fetch_object(zend_object *obj) {
    return (PulsarMessage_object *)((char*)(obj) - XtOffsetOf(PulsarMessage_object, zo));
}

void PulsarMessage_object_dtor(zend_object *object);
void PulsarMessage_object_free(zend_object *object);
zend_object *PulsarMessage_object_create(zend_class_entry *ce);

#endif //PULSAR_PHP_PULSAR_MESSAGE_H
