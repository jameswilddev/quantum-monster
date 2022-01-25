#ifndef QM_STATIC_DATA_H

#define QM_STATIC_DATA_H

#include <stdint.h>
#include <stddef.h>

#ifndef QM_STATIC_DATA
  #error QM_STATIC_DATA must be defined globally.
#endif

#ifndef QM_STATIC_DATA_ADDRESS_TYPE
  #error QM_STATIC_DATA_ADDRESS_TYPE must be defined globally.
#endif

/**
 * @brief A target-defined data type which is a reference to a specific byte of static data.  On von Neumann architectures, this will be an ordinary pointer, but on Harvard architectures, this may instead be an offset into a different memory space.
 */
typedef QM_STATIC_DATA_ADDRESS_TYPE qm_static_data_address_t;

/**
 * @brief Reads one or more bytes of static data.
 * @param from The address of the static data from which to read (see qm_static_data_address_t).
 * @param bytes The number of bytes to copy.
 * @param to The buffer to which to write the contents of the static data.
 */
extern void qm_static_data_read(qm_static_data_address_t from, size_t bytes, void * to);

#endif
