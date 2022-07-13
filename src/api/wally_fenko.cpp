#include "api/wally_fenko.hpp"
#include "wally/std/native_utils.h"
#include "wally/data_structs/value.h"
#include "wally/misc/common.h"

// region Render
NATIVE_FUNCTION(draw)
{
    CHECK_ARG_COUNT("render.draw", 0);
}

// endregion