// lua.hpp
// Lua header files for C++
// 外部C 不是自动提供,因为lua也编译为C++
// <<extern "C">> not supplied automatically because Lua also compiles as C++

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}
