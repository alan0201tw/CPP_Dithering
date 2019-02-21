#pragma once
#include <algorithm>

uint8_t saturated_add(uint8_t val1, int8_t val2)
{
	int16_t val1_int = val1;
	int16_t val2_int = val2;
	int16_t tmp = val1_int + val2_int;

	return static_cast<uint8_t>(std::min(std::max((int16_t)0, tmp), (int16_t)255));
}