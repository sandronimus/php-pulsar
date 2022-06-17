dnl config.m4 for extension pulsar

PHP_ARG_ENABLE(pulsar, whether to enable pulsar support,
    [  --enable-pulsar           Enable pulsar support])

if test "$PHP_pulsar" != "no"; then
    PHP_REQUIRE_CXX()

    SEARCH_PATH="/usr/local /usr /opt/local"
    SEARCH_FOR="/include/pulsar/Client.h"

    if test -r $PHP_pulsar/$SEARCH_FOR; then
        PULSAR_DIR=$PHP_pulsar
    else
        AC_MSG_CHECKING([for pulsar in default path])
        for i in $SEARCH_PATH ; do
            if test -r $i/$SEARCH_FOR; then
                PULSAR_DIR=$i
                AC_MSG_RESULT(found in $i)
                break
            fi
        done
    fi

    if test -z "$PULSAR_DIR"; then
        AC_MSG_RESULT([not found])
        AC_MSG_ERROR([Please reinstall the Pulsar distribution])
    fi

    PHP_ADD_LIBRARY_WITH_PATH(pulsar, $PULSAR_DIR/lib, PULSAR_SHARED_LIBADD)

    PHP_SUBST(PULSAR_SHARED_LIBADD)

    PULSAR_PHP_SOURCES="pulsar.cpp pulsar_client.cpp pulsar_producer.cpp pulsar_message_builder.cpp pulsar_message.cpp"
    PHP_NEW_EXTENSION(pulsar, $PULSAR_PHP_SOURCES, $ext_shared,, -std=c++0x -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi