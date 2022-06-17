#ifndef PULSAR_PHP_PULSAR_PRODUCER_H
#define PULSAR_PHP_PULSAR_PRODUCER_H

#include "php.h"
#include "php_pulsar.h"

extern zend_class_entry *PulsarProducer_ce;
extern zend_object_handlers PulsarProducer_object_handlers;

typedef struct {
    pulsar::Producer *producer;
    zend_object zo;
} PulsarProducer_object;

static inline PulsarProducer_object *php_pulsar_producer_fetch_object(zend_object *obj) {
    return (PulsarProducer_object *)((char*)(obj) - XtOffsetOf(PulsarProducer_object, zo));
}

void PulsarProducer_object_dtor(zend_object *object);
void PulsarProducer_object_free(zend_object *object);
zend_object *PulsarProducer_object_create(zend_class_entry *ce);

#endif //PULSAR_PHP_PULSAR_PRODUCER_H
