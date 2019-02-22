#pragma once
#include <algorithm>

/**
 *	Functions in this file are for internal dithering usage only.
 *	Client(External) programs should not include this file.
 */

namespace dithering
{
	uint8_t saturated_add(uint8_t val1, int8_t val2);
}