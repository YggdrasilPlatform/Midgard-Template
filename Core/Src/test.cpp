#define BOARD MIDGARD
#define YGGDRASIL_PERIPHERAL_DEFS
#include <yggdrasil.h>

#include <stdio.h>
#include <array>
#include <cstdio>

using namespace bsp;
using namespace bsp::ygg::prph;

extern "C" void test() {

	auto data = ProfileCounter.getFormattedTimeToOverflow();
	printf("Time to an overflow: %s \n", data.c_str());
	u64 meanValue;
	u32 cnt = 1;
	while (cnt < 1000) {
		ProfileCounter.start();
		core::delay(1);
		ProfileCounter.stop();
		meanValue += (ProfileCounter.getPassedTime());
		ProfileCounter.reset();
		cnt++;
	}

	meanValue /= cnt;

	printf("Mean value for 1ms: %s \n", ProfileCounter.formatToString(meanValue).c_str());

	ProfileCounter.start();
	core::delay(100);
	ProfileCounter.stop();
	data = ProfileCounter.getFormattedPassedTime();
	printf("Measure 100ms: %s \n", data.c_str());

	while (true);
}
