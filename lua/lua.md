

http://www.lua.org
http://lua-users.org/
http://luadist.org/ lua binary ???
https://github.com/LuaDist/Repository lua dist lua包管理系统
https://studio.zerobrane.com/ lua IDE

《Lua程序设计》 第四版 巴西Roberto Ierusalimschy著

1* 2*
3
4
5
6
7
8
9
10

33



# Lua

程序段chunk: 一组命令或表达式组成的序列


```shell

lua hello.lua # 执行lua文件

% lua # 交互模式
> ^D(Linux)/ ^Z(Windows)/ os.exit() # 退出交互模式


% lua
> dofile("l.lua") # 加载文件

# 独立解释器 Stand-alone interpreter 源文件名为lua.c 可执行文件为lua 可以直接执行.lua文件
# 如果第一行为#开头, 方便Linux加载lua文件, 并且寻找到独立解释器
#!/usr/local/bin/lua
#!/usr/bin/env lua

% lua
-e "print(math.sin(12))" # 执行代码
-i l.lua # 执行完程序后进入交互模式
-l name # 加载库
-v # 显示版本

% lua -e "sin=math.sin" l.lua a b
print(arg[-3])
print(arg[-2])
print(arg[-1])
print(arg[0])
print(arg[1])
print(arg[2])



```



# 变量

```lua
-- 标识符, 由字母数字下划线组成(不能以数字开头), 区分大小写, _VERSION(下划线+大写字母)用作特殊用途, 下划线+小写字母用作哑变量

-- 保留字 and break do else elseif end false goto for function
-- if in local nil not or repeat return then true until while

-- 单行注释
--[[
多行注释
]]

--[[ 放开代码变成 ---[[
注释小技巧
]]

-- 可以用分号隔开语句, 但这个并不是必须的
a=1;b=2; 
a=1 b=2

```


```lua
-- 基本类型8种: nil boolean number string userdata function thread table
-- userdata类型允许把C语言数据保存在lua语言变量中
-- 变量没有预定义类型 任何变量可以包含任何类型的值
print(type(nil)) -- nil
print(type(true)) -- boolean
print(type(3.14)) -- number
print(type("hello")) -- string
print(type(io.stdin)) -- userdata
print(type(print)) -- function
print(type(type)) -- thread
print(type({})) -- table
print(type(type(X))) -- string

nil --没有经过初始化的变量是空
b = nil -- 变量b会被回收

Boolean: true false -- 只有false和nil视为假,任何值都视为真,包括空字符串和零

```

```lua
-- 5.3版本之后, 数值类型有两种, 64位的整形integer和浮点型float, Small模式则降为32位
6 -- 整形
0.6 -- 浮点
4.57e-3 -- 科学计数法 0.00457
0.3e12 -- 3*10^11 11个零
5E+20 -- 5e+20
0xff -- 十六进制
0x0.2 -- 0.125 lua语言支持十六进制浮点数
0x1p-1 -- 0.5 可以保存浮点数的精度
0xa.bp2 -- a.b是小数部分,p开头的指数部分

-- number类型可以相互转化
1 == 10 -- true
0.2e3 == 200 -- true

-- 要区分是integer/float不能用type,用math.type
type(3) -- number
math.type(3) -- integer
math.type(3.0) -- float







```



# 运算符
```lua
-- 算术运算符
-- + - * / -取负数 
-- //浮点取整数 %取模 ^指数运算
a % b == a - ((a // b) * b) -- 取模运算定义
pi = math.pi; -- 取模运算对于小数有点不同
pi - pi % 0.01 -- 3.14 保留2位小数
2^2 -- x^0.5平方根 x^(1/3)立方根

-- 关系运算符
-- < > <= >= == ~=

-- 逻辑运算符
-- and 第一个是假返回第一个, 第一个是真返回第二个
-- or 第一个是真返回第一个, 第一个是假返回第二个
-- 第一个符合条件, 第二个就不执行
print(false and ture) -- false
print(false or true) -- true
print(4 and 5) -- 5
print(4 or 5) -- 4
if not x then
    x = 3
end -- 如果没有给x赋值,则进行赋值初始化
x = x or 5 -- 等效语句
a?b:c -- 等价于(a and b or c) and运算符优先级高于or (如果b不是false)
(x > y) and x or y -- 选出较大的那一个
-- not 表示取反 永远返回布尔运算符 not not返回布尔类型
not not nil -- false

-- 运算符优先级
-- 二元运算符中, ^幂运算和..连接操作是右结合, 其他都是左结合
--[[
^
一元运算符 - # ~ not
* / // %
+ -
.. 连接
<< >> 位移
& 与
~ 异或
| 或
< > <= >= ~= ==
and
or
]]







```

# 控制语句

```lua

if n == 0 then
    return 0
else
    return 1
end


















```




# function类型


```lua

-- 函数写法
function foo(x)
    return 2 * x
end
fun1 = foo(9)
print(fun1)

-- 函数简写 语法糖
fun2 = function(x) return 2 * x end

-- 列表属性
lib = {}
lib.foo = function(x, y) return x + y end
lib.goo = function(x, y) return x - y end

-- 表构造器
lib = {
    foo = function(x, y) return x + y end,
    goo = function(x, y) return x - y end
}

-- 另一种语法
lib = {}
function lib.foo(x, y) return x + y end
function lib.goo(x, y) return x - y end

-- 局部递归函数,fact被调用时,还没有被定义,所以这里不适用
local fact = function(n)
    if n == 0 then
        return 1
    else
        return n * fact(n - 1) -- 这里会调用全局函数
    end
end

-- 先定义再调用
local fact
fact = function(n)
    if n == 0 then
        return 1
    else
        return n * fact(n - 1) -- 这里会调用局部函数变量
    end
end

-- 语法糖 lua会自动展开
local function foo(params) return 0 end
local foo; foo = function(params) return 0 end





```



# thread





# libraries

## basic

_G
_VERSION
assert
collectgarbage
dofile
error
getmetatable
ipairs
load
loadfile
next
pairs
pcall
print 
rawequal
rawget
rawlen
rawset
require
select
setmetatable
tonumber
tostring
type
warn
xpcall

## coroutine
coroutine.close
coroutine.create
coroutine.isyieldable
coroutine.resume
coroutine.running
coroutine.status
coroutine.wrap
coroutine.yield

## debug
debug.debug
debug.gethook
debug.getinfo
debug.getlocal
debug.getmetatable
debug.getregistry
debug.getupvalue
debug.getuservalue
debug.sethook
debug.setlocal
debug.setmetatable
debug.setupvalue
debug.setuservalue
debug.traceback
debug.upvalueid
debug.upvaluejoin

## io

io.close
io.flush
io.input
io.lines
io.open
io.output
io.popen
io.read 读取命令行输入或者其他输入内容
io.stderr
io.stdin
io.stdout
io.tmpfile
io.type
io.write
file:close
file:flush
file:lines
file:read
file:seek
file:setvbuf
file:write



## math
这里主要包含了 三角函数 指数函数 取整函数 最大和最小函数 伪随机数函数 常量pi和huge
math.abs
math.acos
math.asin
math.atan
math.ceil 向正无穷方向取整 3.3-->4 -3.3-->-3
math.cos
math.deg
math.exp
math.floor 向负无穷方向取整 3.3-->3 -3.3-->4 floor(x+0.5)四舍五入
math.fmod
math.huge
math.log
math.max
math.maxinteger 整数值的最大值
math.min
math.mininteger 整数值的最小值
math.modf 向零取整 3.3-->3 0.3 返回两个数
math.pi
math.rad
math.random 生成伪随机数
math.randomseed 设置种子 math.randomseed(os.time())
math.sin
math.sqrt
math.tan
math.tointeger 数值类型强制转化成整形
math.type 如果是number类型返回integer或float, 否则返回fail
math.ult

## os
os.clock
os.date
os.difftime
os.execute
os.exit
os.getenv
os.remove
os.rename
os.setlocale
os.time
os.tmpname

## package
package.config
package.cpath
package.loaded
package.loadlib
package.path
package.preload
package.searchers
package.searchpath

## string
string.byte
string.char
string.dump
string.find
string.format 按照固定格式输出,类似ISO C的sprintf函数
string.gmatch
string.gsub
string.len
string.lower
string.match
string.pack
string.packsize
string.rep
string.reverse
string.sub
string.unpack
string.upper

## table
table.concat
table.insert
table.move
table.pack
table.remove
table.sort
table.unpack

## utf-8
utf8.char
utf8.charpattern
utf8.codepoint
utf8.codes
utf8.len
utf8.offset

## metamethods
__add
__band
__bnot
__bor
__bxor
__call
__close
__concat
__div
__eq
__gc
__idiv
__index
__le
__len
__lt
__metatable
__mod
__mode
__mul
__name
__newindex
__pairs
__pow
__shl
__shr
__sub
__tostring
__unm

## environment variables
variables
LUA_CPATH
LUA_CPATH_5_4
LUA_INIT
LUA_INIT_5_4
LUA_PATH
LUA_PATH_5_4

C API
auxiliary libary
standard libary
constants


# other

## C API
lua_Alloc
lua_CFunction
lua_Debug
lua_Hook
lua_Integer
lua_KContext
lua_KFunction
lua_Number
lua_Reader
lua_State
lua_Unsigned
lua_WarnFunction
lua_Writer

lua_absindex
lua_arith
lua_atpanic
lua_call
lua_callk
lua_checkstack
lua_close
lua_closeslot
lua_compare
lua_concat
lua_copy
lua_createtable
lua_dump
lua_error
lua_gc
lua_getallocf
lua_getextraspace
lua_getfield
lua_getglobal
lua_gethook
lua_gethookcount
lua_gethookmask
lua_geti
lua_getinfo
lua_getiuservalue
lua_getlocal
lua_getmetatable
lua_getstack
lua_gettable
lua_gettop
lua_getupvalue
lua_insert
lua_isboolean
lua_iscfunction
lua_isfunction
lua_isinteger
lua_islightuserdata
lua_isnil
lua_isnone
lua_isnoneornil
lua_isnumber
lua_isstring
lua_istable
lua_isthread
lua_isuserdata
lua_isyieldable
lua_len
lua_load
lua_newstate
lua_newtable
lua_newthread
lua_newuserdatauv
lua_next
lua_numbertointeger
lua_pcall
lua_pcallk
lua_pop
lua_pushboolean
lua_pushcclosure
lua_pushcfunction
lua_pushfstring
lua_pushglobaltable
lua_pushinteger
lua_pushlightuserdata
lua_pushliteral
lua_pushlstring
lua_pushnil
lua_pushnumber
lua_pushstring
lua_pushthread
lua_pushvalue
lua_pushvfstring
lua_rawequal
lua_rawget
lua_rawgeti
lua_rawgetp
lua_rawlen
lua_rawset
lua_rawseti
lua_rawsetp
lua_register
lua_remove
lua_replace
lua_resetthread
lua_resume
lua_rotate
lua_setallocf
lua_setfield
lua_setglobal
lua_sethook
lua_seti
lua_setiuservalue
lua_setlocal
lua_setmetatable
lua_settable
lua_settop
lua_setupvalue
lua_setwarnf
lua_status
lua_stringtonumber
lua_toboolean
lua_tocfunction
lua_toclose
lua_tointeger
lua_tointegerx
lua_tolstring
lua_tonumber
lua_tonumberx
lua_topointer
lua_tostring
lua_tothread
lua_touserdata
lua_type
lua_typename
lua_upvalueid
lua_upvalueindex
lua_upvaluejoin
lua_version
lua_warning
lua_xmove
lua_yield
lua_yieldk

## auxiliary library
luaL_Buffer
luaL_Reg
luaL_Stream

luaL_addchar
luaL_addgsub
luaL_addlstring
luaL_addsize
luaL_addstring
luaL_addvalue
luaL_argcheck
luaL_argerror
luaL_argexpected
luaL_buffaddr
luaL_buffinit
luaL_buffinitsize
luaL_bufflen
luaL_buffsub
luaL_callmeta
luaL_checkany
luaL_checkinteger
luaL_checklstring
luaL_checknumber
luaL_checkoption
luaL_checkstack
luaL_checkstring
luaL_checktype
luaL_checkudata
luaL_checkversion
luaL_dofile
luaL_dostring
luaL_error
luaL_execresult
luaL_fileresult
luaL_getmetafield
luaL_getmetatable
luaL_getsubtable
luaL_gsub
luaL_len
luaL_loadbuffer
luaL_loadbufferx
luaL_loadfile
luaL_loadfilex
luaL_loadstring
luaL_newlib
luaL_newlibtable
luaL_newmetatable
luaL_newstate
luaL_openlibs
luaL_opt
luaL_optinteger
luaL_optlstring
luaL_optnumber
luaL_optstring
luaL_prepbuffer
luaL_prepbuffsize
luaL_pushfail
luaL_pushresult
luaL_pushresultsize
luaL_ref
luaL_requiref
luaL_setfuncs
luaL_setmetatable
luaL_testudata
luaL_tolstring
luaL_traceback
luaL_typeerror
luaL_typename
luaL_unref
luaL_where

## standard library
luaopen_base
luaopen_coroutine
luaopen_debug
luaopen_io
luaopen_math
luaopen_os
luaopen_package
luaopen_string
luaopen_table
luaopen_utf8

## constants
LUA_ERRERR
LUA_ERRFILE
LUA_ERRMEM
LUA_ERRRUN
LUA_ERRSYNTAX
LUA_HOOKCALL
LUA_HOOKCOUNT
LUA_HOOKLINE
LUA_HOOKRET
LUA_HOOKTAILCALL
LUA_LOADED_TABLE
LUA_MASKCALL
LUA_MASKCOUNT
LUA_MASKLINE
LUA_MASKRET
LUA_MAXINTEGER
LUA_MININTEGER
LUA_MINSTACK
LUA_MULTRET
LUA_NOREF
LUA_OK
LUA_OPADD
LUA_OPBAND
LUA_OPBNOT
LUA_OPBOR
LUA_OPBXOR
LUA_OPDIV
LUA_OPEQ
LUA_OPIDIV
LUA_OPLE
LUA_OPLT
LUA_OPMOD
LUA_OPMUL
LUA_OPPOW
LUA_OPSHL
LUA_OPSHR
LUA_OPSUB
LUA_OPUNM
LUA_PRELOAD_TABLE
LUA_REFNIL
LUA_REGISTRYINDEX
LUA_RIDX_GLOBALS
LUA_RIDX_MAINTHREAD
LUA_TBOOLEAN
LUA_TFUNCTION
LUA_TLIGHTUSERDATA
LUA_TNIL
LUA_TNONE
LUA_TNUMBER
LUA_TSTRING
LUA_TTABLE
LUA_TTHREAD
LUA_TUSERDATA
LUA_USE_APICHECK
LUA_YIELD
LUAL_BUFFERSIZE


# eightqueen

```lua
-- eightqueen
N = 8 -- 棋盘大小
count = 0

-- 检查(n,c)是否不会被攻击
function isplaceok(a, n, c)
    for i = 1, n - 1 do
        -- 对于每个已经被放置的皇后
        if (a[i] == c) or -- 同一列
                (a[i] - i == c - n) or -- 同一对角线
                (a[i] + i == c + n) then
            -- 同一对角线
            return false -- 位置会被攻击
        end
    end
    return true -- 不会被攻击, 位置有效
end

-- 打印棋盘
function printsolution(a)
    count = count + 1;
    print("这是第", count, "个结果")
    for i = 1, N do
        -- 每一行
        for j = 1, N do
            -- 每一列
            io.write(a[i] == j and "Q" or "_", "")
        end
        io.write("\n")
    end
    io.write("\n")
end

function addqueen(a, n)
    if n > N then
        printsolution(a)
    else
        for c = 1, N do
            if isplaceok(a, n, c) then
                a[n] = c
                addqueen(a, n + 1)
            end
        end
    end
end

addqueen({}, 1)

```