/* pulsar extension for PHP */

#ifndef PHP_PULSAR_H
# define PHP_PULSAR_H

extern zend_module_entry pulsar_module_entry;
# define phpext_pulsar_ptr &pulsar_module_entry

# define PHP_PULSAR_VERSION "0.1.0"

extern "C" {
#include "php.h"
#include "ext/standard/info.h"
}

#include <pulsar/Client.h>

#ifdef ZTS
#include "TSRM.h"
#endif

# if defined(ZTS) && defined(COMPILE_DL_PULSAR)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_PULSAR_H */
