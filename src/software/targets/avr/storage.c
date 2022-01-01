#include <stdint.h>
#include <avr/io.h>
#include "../target.h"

uint8_t qm_storage_read(qm_storage_address_t address)
{
    return eeprom_read_byte((uint8_t*)address);
}

void qm_storage_write(qm_storage_address_t address, uint8_t byte)
{
    return eeprom_update_byte((uint8_t*)address, byte);
}