#Readme
##程序说明
一个简单的大数加法以及输出~~`毕竟只是测试一下`~~
依次输入A和B就行了。
>只实现了`+,<<,=`的运算符重载，不过减法也可以用


主要是vim的配置，这里上网找了一个不需要插件的vimrc
[vim配置](https://blog.csdn.net/jun2016425/article/details/52356897)
使用方法：在home里建一个 .vimrc文件，把东西复制粘贴即可
vim的使用，可以参考vim使用手册或者其他网站的东西
[vim使用](http://www.runoob.com/linux/linux-vim.html)
##关于编译
首先是*gcc/g++编译*：以test.c为例（.c == .cpp）
>在终端上分步操作： 
>>gcc -E test.c >test.i //预处理
>>gcc -S test.i >test.s //汇编
>>gcc -c test.s >test.o //转二进制
>>gcc test.o -o test //执行
>>第二个 用于对 c++的编译
>
>一步到位：gcc test.c -o test

然后是用*make*编译
>在当前文件夹建立makefile文件，一个文件比较简单
>>目标文件 ： 所需文件
>>tab 编译规则
>
>还是以test.c为例
>> test: test.c
>>[tab] g++ test.c -o test
>
>在终端上输入 make test
>然后就好啦
>高端操作正在摸索，扔个教材
>[makefile编写规则](https://www.cnblogs.com/wang_yb/p/3990952.html)

*cmake编译*
>现在官网上整一个cmake
>[cmake 安装](https://www.cnblogs.com/weiqinglan/p/5681539.html)
>或者，sudo apt install cmake
>cmake 其实就是自动生成makefile的一个东西 
>使用时建立一个CMakeLists.txt 再用相应的语法进行编译即可
