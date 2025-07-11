https://www.runoob.com/cprogramming/c-standard-library.html

https://en.cppreference.com/w/c/header
https://cplusplus.com/reference/

# ISO C include

```c
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <dlfcn.h>
#include <unistd.h>
#include <io>
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <windows.h>


```

# include and depended

```c





lprefix.h: No include
luaconf.h: No include
ljumptab.h: No include
lopnames.h: No include

lua.h: luaconf.h
llimits.h: lua.h
lopcodes.h: llimits.h
lualib.h: lua.h
lauxlib.h: luaconf.h lua.h
lobject.h llimits.h lua.h
lfunc.h: lobject.h
ltable.h: lobject.h



lstate.h: lua.h lobject.h ltm.h lzio.h
ldebug.h: lstate.h


lapi.h: llimits.h lstate.h
lcode.h: llex.h lobject.h lopcodes.h lparser.h
lctype.h: lua.h llimits.h
ldo.h: llimits.h lobject.h lstate.h lzio.h
lgc.h: lobject.h lstate.h



llex.h: lobject.h lzio.h
lmem.h: llimits.h lua.h


lparser.h: llimits.h lobject.h lzio.h


lstring.h: lgc.h lobject.h lstate.h
ltm.h: lobject.h lstate.h
lua.hpp: lua.h lualib.h lauxlib.h
lundump.h: llimits.h lobject.h lzio.h
lvm.h: ldo.h lobject.h ltm.h
lzio.h: lua.h lmem.h






lua.c: lprefix.h lua.h lauxlib.h lualib.h
lapi.c: lprefix.h lua.h lapi.h ldebug.h ldo.h lfunc.h lgc.h lmem.h lobject.h lstate.h lstring.h ltable.h ltm.h lundump.h lvm.h
lauxlib.c: lprefix.h lua.h lauxlib.h
lbaselib.c: lprefix.h lua.h lauxlib.h lualib.h
lcode.c: lprefix.h lua.h lcode.h ldebug.h ldo.h lgc.h llex.h lmem.h lobject.h lopcodes.h lparser.h lstring.h ltable.h lvm.h
lcorolib.c
lctype.c
ldblib.c
ldebug.c
ldo.c
ldump.c
lfunc.c
lgc.c
linit.c
liolib.c
llex.c
lmathlib.c
lmem.c
loadlib.c
lobject.c
lopcodes.c
loslib.c
lparser.c
lstate.c
lstring.c
lstrlib.c
ltable.c
ltablib.c
ltm.c
luac.c
lundump.c
lutf8lib.c: lprefix.h lua.h lauxlib.h lualib.h
lvm.c: lprefix.h lua.h ldebug.h ldo.h lfunc.h lgc.h lobject.h lopcodes.h lstate.h lstring.h ltable.h ltm.h lvm.h ljumptab.h
lzio.c: lprefix.h lua.h llimits.h lmem.h lstate.h lzio.h

















```

# source

```md
lapi Lua API 接口 Auxiliary functions from Lua API 辅助函数来自接口
lauxlib Auxiliary functions for building Lua libraries 辅助函数为构建 lua 库
lbaselib.c Basic library 基础库
lcode Code generator for Lua 代码生成器为 lua
lcorolib.c Coroutine Library 协同程序库
lctype 'ctype' functions for Lua ctype 函数为 lua
ldblib.c Interface from Lua to its debug API 接口从 lua 到它调试 API
ldebug Debug Interface 调试接口 Auxiliary functions from Debug Interface module 辅助函数从调试接口模块
ldo Stack and Call structure of Lua lua 的堆栈和回调结构
ldump.c save precompiled Lua chunks 保存预编译 lua 组块
lfunc Auxiliary functions to manipulate prototypes and closures 辅助函数去操作原型和闭包
lgc Garbage Collector 垃圾回收
linit.c Initialization of libraries for lua.c and other clients 初始化库 为 lua.c 和其他客户端
liolib.c Standard I/O (and system) library 标准 IO 和系统库
ljumptab.h Jump Table for the Lua interpreter 跳转表为 lua 编译器
llex Lexical Analyzer 词法分析器
llimits.h Limits, basic types, and some other 'installation-dependent' definitions 限制,基本类型,和安装依赖 定义
lmathlib.c Standard mathematical library 标准数学库
lmem Interface to Memory Manager 内存管理器接口
loadlib.c Dynamic library loader for Lua 动态库加载为 lua
lobject Some generic functions over Lua objects 一些泛型函数在 lua 对象上 Type definitions for Lua objects 类型定义为 lua 对象
lopcodes Opcodes for Lua virtual machine 伪代码 weilua 虚拟机
lopnames.h Opcode names 伪代码名字
loslib.c Standard Operating System library 标准操作系统库
lparser Lua Parser lua 语法解析器
lprefix.h Definitions for Lua code that must come before any other header file 必须在任何其他头文件之前的 lua 代码的定义
lstate Global State 全局状态
lstring String table (keeps all strings handled by Lua) 字符串表(保持所有字符串处理通过 lua)
lstrlib.c Standard library for string operations and pattern-matching 标准库为字符串操作和模式匹配
ltable Lua tables (hash) lua 哈希表
ltablib.c Library for Table Manipulation 库为了表操作
ltm Tag methods 标签方法
lua Lua stand-alone interpreter lua 独立编译器 Lua - A Scripting Language lua 是一个脚本语言
lua.hpp C++头文件
luac.c Lua compiler (saves bytecodes to files; also lists bytecodes) lua 编译器(保存字节码到文件,也列出字节码)
luaconf.h Configuration file for Lua 配置文件为 lua
lualib.h Lua standard libraries lua 标准库
lundump load precompiled Lua chunks 加载预编译 lua 块
lutf8lib.c Standard library for UTF-8 manipulation 标准库为 UTF-8 操作
lvm Lua virtual machine lua 虚拟机
lzio.c Buffered streams 缓冲流
```

```md
Includes
lua.h
lauxlib.h
lualib.h
luaconf.h
Core
lapi.c
lcode.c
lctype.c
ldebug.c
ldo.c
ldump.c
lfunc.c
lgc.c
llex.c
lmem.c
lobject.c
lopcodes.c
lparser.c
lstate.c
lstring.c
ltable.c
ltm.c
lundump.c
lvm.c
lzio.c

lapi.h
lcode.h
lctype.h
ldebug.h
ldo.h
lfunc.h
lgc.h
ljumptab.h
llex.h
llimits.h
lmem.h
lobject.h
lopcodes.h
lopnames.h
lparser.h
lprefix.h
lstate.h
lstring.h
ltable.h
ltm.h
lundump.h
lvm.h
lzio.h
Libraries
lauxlib.c
lbaselib.c
lcorolib.c
ldblib.c
liolib.c
lmathlib.c
loadlib.c
loslib.c
lstrlib.c
ltablib.c
lutf8lib.c
linit.c
Interpreter
lua.c
Compiler
luac.c
```

# OpName and OpMode

```c
static const char *const opnames[] = {
  "MOVE", //
  "LOADI",
  "LOADF",
  "LOADK",
  "LOADKX",
  "LOADFALSE",
  "LFALSESKIP",
  "LOADTRUE",
  "LOADNIL",
  "GETUPVAL",
  "SETUPVAL",
  "GETTABUP",
  "GETTABLE",
  "GETI",
  "GETFIELD",
  "SETTABUP",
  "SETTABLE",
  "SETI",
  "SETFIELD",
  "NEWTABLE",
  "SELF",
  "ADDI",
  "ADDK",
  "SUBK",
  "MULK",
  "MODK",
  "POWK",
  "DIVK",
  "IDIVK",
  "BANDK",
  "BORK",
  "BXORK",
  "SHRI",
  "SHLI",
  "ADD",
  "SUB",
  "MUL",
  "MOD",
  "POW",
  "DIV",
  "IDIV",
  "BAND",
  "BOR",
  "BXOR",
  "SHL",
  "SHR",
  "MMBIN",
  "MMBINI",
  "MMBINK",
  "UNM",
  "BNOT",
  "NOT",
  "LEN",
  "CONCAT",
  "CLOSE",
  "TBC",
  "JMP",
  "EQ",
  "LT",
  "LE",
  "EQK",
  "EQI",
  "LTI",
  "LEI",
  "GTI",
  "GEI",
  "TEST",
  "TESTSET",
  "CALL",
  "TAILCALL",
  "RETURN",
  "RETURN0",
  "RETURN1",
  "FORLOOP",
  "FORPREP",
  "TFORPREP",
  "TFORCALL",
  "TFORLOOP",
  "SETLIST",
  "CLOSURE",
  "VARARG",
  "VARARGPREP",
  "EXTRAARG",
  NULL
};
```
