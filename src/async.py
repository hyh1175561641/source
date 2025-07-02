# 我想要读取本文件夹的所有c文件, 并观察他们的头文件依赖
# I want read this folder all of .c file, and 分析 they depends
# https://docs.python.org/3.9/library/os

import os
 
def traverse_folder(path):
    for root, dirs, files in os.walk(path):
        for file in files:
            # 处理文件
            print(os.path.join(root, file))


# traverse_folder("./")
# print(os.walk)
# print(os.walk())
# print(os.walk(""))
# print(os.walk(""))
# print(os.walk("./"))
print(os.listdir)
print(os.listdir())
