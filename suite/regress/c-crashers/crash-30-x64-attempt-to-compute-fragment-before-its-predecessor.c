#include <keystone/keystone.h>
int main(int argc, char **argv) {
  int ks_arch = KS_ARCH_X86, ks_mode = KS_MODE_64;
  char *assembly = ".=x;.=x;1:";
  ks_engine *ks;
  ks_err err = ks_open(ks_arch, ks_mode, &ks);
  if (!err) {
    size_t count, size;
    unsigned char *insn;
    ks_asm(ks, assembly, 0, &insn, &size, &count);
    ks_free(insn);
  }
  ks_close(ks);
}
