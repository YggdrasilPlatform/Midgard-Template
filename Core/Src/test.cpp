#define BOARD MIDGARD
#define YGGDRASIL_PERIPHERAL_DEFS
#include <yggdrasil.h>

extern "C" void test() {
	auto value = bsp::I2CC::read<u8>(0x56, 0xA8);

	printf("%X\n", value);
	while (true);
}
