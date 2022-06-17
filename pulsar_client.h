#ifndef PULSAR_PHP_PULSAR_CLIENT_H
#define PULSAR_PHP_PULSAR_CLIENT_H

#include "php.h"
#include "php_pulsar.h"

extern zend_class_entry *PulsarClient_ce;
extern zend_object_handlers PulsarClient_object_handlers;

typedef struct {
    pulsar::Client *client;
    zend_object zo;
} PulsarClient_object;

static inline PulsarClient_object *php_pulsar_client_fetch_object(zend_object *obj) {
    return (PulsarClient_object *)((char*)(obj) - XtOffsetOf(PulsarClient_object, zo));
}

void PulsarClient_object_dtor(zend_object *object);
void PulsarClient_object_free(zend_object *object);
zend_object *PulsarClient_object_create(zend_class_entry *ce);

#endif //PULSAR_PHP_PULSAR_CLIENT_H
