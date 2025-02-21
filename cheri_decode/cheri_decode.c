#include <stdio.h>
#include "sail.h"
#include "riscv_sail.h"

void zprint_decoded_cap(uint64_t hi, uint64_t lo);

int main() {
  printf("test from C\n");
  zprint_decoded_cap(1, 0);
  printf("test from C\n");
  return 0;
}
