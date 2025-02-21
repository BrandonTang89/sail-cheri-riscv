#include <stdio.h>
#include <string.h>
#include "sail.h"
#include "riscv_sail.h"

void zprint_decoded_cap(uint64_t hi, uint64_t lo);

void usage() {
  printf("Usage:\ncheri_decode <cap_hex_string>\n");
  printf("<cap_hex_string> should be 128-bits, no tag\n");
  printf("tag always set to false in displayed decoded capability\n");
}

void get_cap_halves(const char *hex_str, uint64_t *p_hi, uint64_t *p_lo) {
  size_t len = strnlen(hex_str, 32);
  char buff[33];
  memset(buff, '0', 32);
  buff[32] = '\0';
  strncpy(buff+32-len, hex_str, len);
  // extract capability lo bits
  *p_lo = strtol(buff+16, NULL, 16);
  // extract capability hi bits
  buff[16] = '\0';
  *p_hi = strtol(buff, NULL, 16);
}

int main(int argc, char * argv[]) {
  if (argc != 2) {
    usage();
    return -1;
  }
  uint64_t hi, lo;
  get_cap_halves(argv[1], &hi, &lo);
  printf("cap hi: 0x%016llx, cap lo: 0x%016llx\n", hi, lo);
  model_init();
  printf("----\n");
  zprint_decoded_cap(hi, lo);
  return 0;
}
