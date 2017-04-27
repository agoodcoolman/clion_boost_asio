//
// Created by Administrator on 2017/4/24.
//http
//


#include <boost/asio/ip/tcp.hpp>

int main() {
    boost::asio::ip::tcp::resolver::query query("www.baidu.com", "80");
}