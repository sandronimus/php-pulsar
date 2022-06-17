#ifndef PULSAR_PHP_PULSAR_MESSAGE_BUILDER_H
#define PULSAR_PHP_PULSAR_MESSAGE_BUILDER_H

#include "php.h"
#include "php_pulsar.h"

extern zend_class_entry *PulsarMessageBuilder_ce;
extern zend_object_handlers PulsarMessageBuilder_object_handlers;

typedef struct {
    pulsar::MessageBuilder *message_builder;
    zend_object zo;
} PulsarMessageBuilder_object;

static inline PulsarMessageBuilder_object *php_pulsar_message_builder_fetch_object(zend_object *obj) {
    return (PulsarMessageBuilder_object *)((char*)(obj) - XtOffsetOf(PulsarMessageBuilder_object, zo));
}

void PulsarMessageBuilder_object_dtor(zend_object *object);
void PulsarMessageBuilder_object_free(zend_object *object);
zend_object *PulsarMessageBuilder_object_create(zend_class_entry *ce);

#endif //PULSAR_PHP_PULSAR_MESSAGE_BUILDER_H
