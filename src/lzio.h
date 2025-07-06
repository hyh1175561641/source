/*
** $Id: lzio.h $
** Buffered streams
缓冲流
** See Copyright Notice in lua.h
*/


#ifndef lzio_h
#define lzio_h

#include "lua.h"

#include "lmem.h" // 内存管理接口


#define EOZ	(-1)			/* end of stream 缓冲结束符号*/

typedef struct Zio ZIO; 
// ZIO定义在下面, 在其他文件中, ZIO的用法是ZIO * Z

#define zgetc(z)  (((z)->n--)>0 ?  cast_uchar(*(z)->p++) : luaZ_fill(z))

// size_t unsigned long
typedef struct Mbuffer {
  char *buffer; // buffer指针
  size_t n; // buff位置?
  size_t buffsize; // buff大小
} Mbuffer; // point u-long u-long

// ldo.c  L的类型是lua_State, buff的类型是Mbuffer, 初始化Mbuff, 设定buff指针为空, buff大小为0
#define luaZ_initbuffer(L, buff) ((buff)->buffer = NULL, (buff)->buffsize = 0)
// llex.c
#define luaZ_buffer(buff)	((buff)->buffer) // 返回buff指针
#define luaZ_sizebuffer(buff)	((buff)->buffsize) // save function
#define luaZ_bufflen(buff)	((buff)->n)
// llex.c
#define luaZ_buffremove(buff,i)	((buff)->n -= (i))
#define luaZ_resetbuffer(buff) ((buff)->n = 0)

// llex.c
#define luaZ_resizebuffer(L, buff, size) \
	((buff)->buffer = luaM_reallocvchar(L, (buff)->buffer, \
				(buff)->buffsize, size), \
	(buff)->buffsize = size)
// ldo.c 
#define luaZ_freebuffer(L, buff)	luaZ_resizebuffer(L, buff, 0)

// LUAI_FUNC luaconf.h extern
LUAI_FUNC void luaZ_init (lua_State *L, ZIO *z, lua_Reader reader,
                                        void *data);
LUAI_FUNC size_t luaZ_read (ZIO* z, void *b, size_t n);	/* read next n bytes */



/* --------- Private Part 私有部分 ------------------ */

struct Zio {
  size_t n;			/* bytes still unread */
  const char *p;		/* current position in buffer */
  lua_Reader reader;		/* reader function 定义在lua.h文件中 */
  void *data;			/* additional data */
  lua_State *L;			/* Lua state (for reader) */
};
// Zio 
// u-long 仍未读区的字节
// 指针p 缓冲的当前位置
// lua_Reader的类型是c语言接口
// 指针 data 附加数据
// lua状态为了读区 指针L



LUAI_FUNC int luaZ_fill (ZIO *z);

#endif
