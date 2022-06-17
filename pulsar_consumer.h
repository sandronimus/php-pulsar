#ifndef PULSAR_PHP_PULSAR_CONSUMER_H
#define PULSAR_PHP_PULSAR_CONSUMER_H

#include "php.h"
#include "php_pulsar.h"

extern zend_class_entry *PulsarConsumer_ce;
extern zend_object_handlers PulsarConsumer_object_handlers;

typedef struct {
    pulsar::Consumer *consumer;
    zend_object zo;
} PulsarConsumer_object;

static inline PulsarConsumer_object *php_pulsar_consumer_fetch_object(zend_object *obj) {
    return (PulsarConsumer_object *)((char*)(obj) - XtOffsetOf(PulsarConsumer_object, zo));
}

void PulsarConsumer_object_dtor(zend_object *object);
void PulsarConsumer_object_free(zend_object *object);
zend_object *PulsarConsumer_object_create(zend_class_entry *ce);

#endif //PULSAR_PHP_PULSAR_CONSUMER_H
