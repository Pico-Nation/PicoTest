#pragma once

#include <stdint.h>
#include <setjmp.h>
#include <string.h>

#include <picoio/chain/webassembly/pico-vm-oc/pico-vm-oc.h>

#ifdef __clang__
   #define GS_PTR __attribute__((address_space(256)))
#else
   #define GS_PTR __seg_gs
#endif

//This is really rather unfortunate, but on the upside it does allow a static assert to know if
//the values ever slide which would be a PIC breaking event we'd want to know about at compile
//time.
#define PICO_VM_OC_CONTROL_BLOCK_OFFSET (-18944)
#define PICO_VM_OC_MEMORY_STRIDE (UINT64_C(4329598976))

#ifdef __cplusplus
extern "C" {
#endif

int32_t pico_vm_oc_grow_memory(int32_t grow, int32_t max);
sigjmp_buf* pico_vm_oc_get_jmp_buf();
void* pico_vm_oc_get_exception_ptr();
void* pico_vm_oc_get_bounce_buffer_list();

#ifdef __cplusplus
}
#endif