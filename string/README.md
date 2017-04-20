这个项目是在window上使用clion编写C++项目,并且使用boost库
--

讲一下思路
1.安装clion
2.安装MinGW ,请自行百度吧,安装完毕之后,记得要在window上设置环境变量
3.下载boost 下载之后记得要使用上面的MinGW编译,不然Cmake中找不到库的
    我的编译语句
    
    >bjam stage --toolset=gcc --with-system --build-type=complete  --link=static install
4.编译完后的库,直接复制到你安装的MinGW/lib/文件下
5.运行,如果找不到什么库,记得把上面复制到MinGW/lib/库的文件改一下名字

遇到的问题总结:
--
1.Cmake中编写 添加Boost库的时候,会报找不到boost里面的包的问题,你要设置一下
   >set(Boost_DEBUG ON)
   
可以看到很多log信息,我当时是因为没有经历上面的编译过程,导致log里面提到的要找的包,不存在.
2.运行之后,提示 boost 库找不到,那就是你没有把编译后的库复制到MinGW/lib文件夹下,记得要改成找不到的那个包的名字

3. 报下面这个问题的吧.请在 cmake的target_link_libraries添加 wsock32 ws2_32 这两
    完成的是这么写的 target_link_libraries(string boost_system wsock32 ws2_32)
>CMakeFiles\untitled1.dir/objects.a(main.cpp.obj): In function `ZN5boost4asio6detail17winsock_init_base7startupERNS2_4dataEhh':
 C:/www/cpp/boost_1_62_0/boost/asio/detail/impl/winsock_init.ipp:39: undefined reference to `_imp__WSAStartup@8'
 CMakeFiles\untitled1.dir/objects.a(main.cpp.obj): In function `ZN5boost4asio6detail17winsock_init_base7cleanupERNS2_4dataE':
 C:/www/cpp/boost_1_62_0/boost/asio/detail/impl/winsock_init.ipp:56: undefined reference to `_imp__WSACleanup@0'
