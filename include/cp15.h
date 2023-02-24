#define __STRINGIFY(x) #x

#define __MCR(coproc, opcode_1, src, CRn, CRm, opcode_2)                          \
    __ASM volatile ("MCR " __STRINGIFY(p##coproc) ", " __STRINGIFY(opcode_1) ", " \
                    "%0, " __STRINGIFY(c##CRn) ", " __STRINGIFY(c##CRm) ", "      \
                    __STRINGIFY(opcode_2)                                         \
                    : : "r" (src) )

#define __MRC(coproc, opcode_1, CRn, CRm, opcode_2)                               \
  ({                                                                              \
    uint32_t __dst;                                                               \
    __ASM volatile ("MRC " __STRINGIFY(p##coproc) ", " __STRINGIFY(opcode_1) ", " \
                    "%0, " __STRINGIFY(c##CRn) ", " __STRINGIFY(c##CRm) ", "      \
                    __STRINGIFY(opcode_2)                                         \
                    : "=r" (__dst) );                                             \
    __dst;                                                                        \
  })
