# 一、题目

## 完整目标

首先使用`gdb`调试并修正一个关于判断三角形的程序。然后编写一个简单的 OJ 核心判断这个程序或者其他一个仅操作与标准输入输出的程序是否正确。

## 给出的结构

- `Makefile` 可以运行 `make` 自测
- `src` 编写和编译代码的目录，要求所有的任务都在这里完成。
  - `Makefile` 给出的正确的用于编译 OJ 的`Makefile`。
  - `angle.c` 是需要被调试的判断三角形的程序代码。
  - `oj.c` 在这里编写 OJ 的主程序。
  - `run.c` 提供函数 `void run(const char *program, const char *filein, const char *fileout)`，其中第一个参数表示要运行的程序的路径是`program`，第二个参数表示把路径为`file_in` 的文件的内容作为`program`的标准输入内容，第三个参数表示`program` 的标准输出会输出到路径为 `file_out`的文件。
  - `run.h` 是 `run.c` 对应的头文件。
- `srctestbyscript` (若存在) 运行自测用的目录，不必阅读和修改其中内容。
- `usertest.sh` 与自测相关的文件，不必阅读和修改其中内容。

![](C:\Users\Qiao\AppData\Roaming\Typora\typora-user-images\image-20200910021039329.png)

（其中in.txt、out.txt、right.txt都是自己新建的文件，program是自己编译angle出来的可执行文件）

## 第一部分

先修正angle的编译和链接错误。通过`gdb`来调试，把`angle.c` 修正为下述题目的正确代码：（已经完成修正）

- 判断三角形

  - 输入三个小于一万的正整数表示三角形的三个边长。
    - 若不存在这样的三角形，输出 `It's not a triangle`
    - 若存在这样一个锐角三角形，输出 `It's an acute triangle`
    - 若存在这样一个钝角三角形，输出 `It's an obtuse triangle`
    - 若存在这样一个直角三角形，输出 `It‘s a right triangle`

- 样例输入

  ```
  5 4 3
  ```

- 样例输出

  ```
  It‘s a right triangle
  ```

## 第二部分

测试`./program`输入为 `in.txt`，输出到 `out.txt`，正确答案是 `right.txt`的情况下的正确性。如果争取，输出`Accept`，否则输出`Wrong Answer`。

# 二、程序执行过程

​	1、先编译`angle.c`文件为可执行文件`program`

```shell
gcc -o program angle.c
```

​	2、编译目标文件`oj`

```shell
make oj
```

​	3、执行`oj`

```shell
./oj
```

