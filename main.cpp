#include <cstdio>
#include <cassert>
typedef unsigned char  uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int   uint32_t;

namespace c {

union Register
{
    uint32_t raw;
    struct B
    {
        uint32_t bits_0_7   :  8;
        uint32_t bits_8_15  :  8;
        uint32_t bits_16_31 : 16;
    } bits;
};

} //namespace c

int main(int argc, char* argv[])
{
    volatile uint32_t value = 0x11223344;

    printf("\n\nC style\n\n");
    ::c::Register reg2 = { value };
    printf("0x%08X\n", (int)reg2.raw);
    printf("0x%08X\n", (int)reg2.bits.bits_0_7);
    printf("0x%08X\n", (int)reg2.bits.bits_8_15);
    printf("0x%08X\n", (int)reg2.bits.bits_16_31);
    reg2.bits.bits_0_7 = 0x99;
    printf("0x%08X\n", (int)reg2.raw);
    reg2.bits.bits_8_15 = 0x88;
    printf("0x%08X\n", (int)reg2.raw);
    reg2.bits.bits_16_31 = 0x7777;
    printf("0x%08X\n", (int)reg2.raw);
    printf("0x%08X\n", (int)reg2.bits.bits_0_7);
    printf("0x%08X\n", (int)reg2.bits.bits_8_15);
    printf("0x%08X\n", (int)reg2.bits.bits_16_31);

	return 0;
}
