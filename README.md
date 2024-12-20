> 这个项目主要是想在 win 上也弄弄 proto，这样用 C++ 算法算出的数据方便传出来给到 py 做的游戏那边使用。

1. 中文路径名死路一条（最好空格也不要），用不了 cmake
2. 记得加 include_directories(${CMAKE_CURRENT_SOURCE_DIR})
3. 本来在 linux 中用 cmake 构建一个项目就只需要 “ cmake -S . -B build; cmake --build build ”，但是在 win 这里需要在其中的第一句 cmake 上加个 “ -G "MinGW Makefiles" ” 来制定使用的编译工具。。
4. 不要用 "bits/stdc++.h" 这个头文件，会变得不幸。。因为这个也会编译不了。。
5. protobuf 版本不要高于 21.12。至于安装 protobuf 的具体流程就更复杂了，下面是一些记录。。
   ```
   protobuf 安装特别麻烦，草。。
   要安装旧版本的才行，新版本一堆垃圾东西需要搞，搞不动。。
   
   先下载到旧版本的 protobuf 代码，然后根目录下的 CMakeLists.txt 里面要把 protobuf_BUILD_TESTS 设置为 off，然后还要把 protobuf_BUILD_LIBPROTOC 设置为 ON，这样才能弄出动态库。。用 cmake 构建（选 mingw32 那套编译器作构建工具），构建完以后再拿其中的产出来做 bin 和 lib。。然后还要拿下载下来的代码里面的 src 的 google 文件夹放到 include。。
   
   东西就放在本文件夹下的 protobuf 里面，要把 lib 和 bin 配到环境变量，将来自己项目就能用了。。
   ```