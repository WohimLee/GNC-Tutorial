&emsp;
# 1 Fundamental Compiling
>编译 C 语言相关的后缀
<div align=center>
<image src='imgs/filenamesuffixes1.png' width=600>
</div>
&emsp;


&emsp;
# 2 Compiling C

## 2.1 Preprocessing

```shell
gcc -E helloworld.c
gcc -E helloworld.c -o helloworld.i
```
- -E 选项告诉编译器只进行预处理操作
- -o 选项把预处理的结果输出到指定文件      



&emsp;
## 2.2 Generating Assembly Language
```shell
gcc -S helloworld.c
gcc -S helloworld.c -o helloworld.s
```
- -S 选项告诉编译器，进行预处理和编译成汇编语言操作

每个平台对应的汇编语言的形式是不同的，例如有很多型号的开发板，有很多型号的 CPU


&emsp;
## 2.3 Source File to Object File
```shell
gcc -c helloworld.c
gcc -c helloworld.c -o harumph.o
# 编译多个 .c 文件
gcc -c helloworld.c helloworld1.c helloworld2.c
```


&emsp;
## 2.4 Single Source to Executable
- 注意：后面三个命令执行后并没有按编译过程出现 .i .s 或 .o 文件，并不意味着没有经历这些过程


```shell
gcc helloworld.c
gcc helloworld.c -o howdy
```

执行程序
```
./可执行文件
```

&emsp;
## 2.5 Multiple Source to Executable

```
$ gcc hellomain.c sayhello.c -o hello
```


&emsp;
# 3 Creating a Static Library

- 编译成 .o 的文件
    ```shell
    gcc -c [.c] -o [自定义文件名] 
    gcc -c [.c] [.c] ...
    ```
- 编静态库
    ```shell
    ar -r [lib自定义库名.a] [.o] [.o] ...
    ```
- 链接成可执行文件
    ```shell
    gcc [.c] [.a] -o [自定义输出文件名]
    gcc [.c] -o [自定义输出文件名] -l[库名] -L[库所在路径]
    ```


&emsp;
# 4 Creating a Shared Library

- 编译二进制.o文件
    ```shell
    gcc -c -fpic [.c/.cpp][.c/.cpp]... 
    ```
- 编库
    ```shell
    gcc -shared [.o][.o]... -o [lib自定义库名.so]
    ```
- 连接动态库到可执行文件
    ```shell
    gcc [.c/.cpp] -o [自定义可执行文件名]  -l[库名] -L[库路径] -Wl,-rpath=[库路径]
    ```

&emsp;
# 总结
## 1 编译过程
源文件.c文件 -> 预编译成.i文件 -> 编译成汇编语言.s -> 汇编成.o文件 -> 链接成可执行文件（名字自定义，后缀没关系）

## 2 编译过程命令
- 预处理： 
    ```
    gcc -E [.c源文件] -o [自定义输出文件名.i]
    ```
- 编译成汇编语言(隐藏了预处理操作) :
    ```
    gcc -S [.c源文件] 
    ```
- 会变成.o的object文件（二进制文件，可用于链接） :
    ```
    gcc -c [.c源文件] [.c源文件] [...] (可选选项：-o [自定文件名])
    ```
## 3 库
>静态库
- 编库（先转成.o文件，再编成lib[自定库名].a）
    ```
    gcc -c [.c源文件] [.c源文件] [...] (可选选项：-o [自定文件名])
    ```
    ```
    ar -r lib[自定库名].a [.o文件] [.o文件] [...]
    ```
- 链接
    ```
    gcc [main文件] -o [自定义输出可执行文件名] -l[库名] -L[库的路径]
    ```
>动态库
- 编库      
    - 第一种做法， 先转成.o文件，再编成.so文件
        ```shell
        gcc -c -fpic [.c源文件] [.c源文件] [...]
        ```
        ```shell
        gcc -shared [.o文件] [.o文件] [...] -o lib[库名].so
        ```
    - 第二种做法，直接转成.so
        ```shell
        gcc -fpic -shared [.c源文件] [.c源文件] [...] -o lib[库名].so
        ```
- 链接

    ```shell
    gcc [main文件] -o [自定义输出可执行文件名] -l[库名] -L[库所在路径] -Wl,-rpath=[库所在路径]
    ```
        