/**
 * Copyright (C) 2020 Varun Tewari
 * 
 * This file is part of octo.
 * 
 * octo is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 * 
 * octo is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with octo.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <iostream>

#include <octo/http/request.h>

int main(int argc, char **argv) {
    octo::http::Request req;
    std::string raw = "GET /foo/bar HTTP/1.1\r\n"
        "Host: example.org\r\n"
        "User-Agent: Mozilla/5.0 (Macintosh; U; Intel Mac OS X 10.6; fr; rv:1.9.2.8) Gecko/20100722 Firefox/3.6.8\r\n"
        "Accept: */*\r\n"
        "Accept-Language: fr,fr-fr;q=0.8,en-us;q=0.5,en;q=0.3\r\n"
        "Accept-Encoding: gzip,deflate\r\n"
        "Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7\r\n"
        "Keep-Alive: 115\r\n"
        "Connection: keep-alive\r\n"
        "Content-Type: application/x-www-form-urlencoded\r\n"
        "X-Requested-With: XMLHttpRequest\r\n"
        "Referer: http://example.org/test\r\n"
        "Cookie: foo=bar; lorem=ipsum\r\n"
        "\r\n\r\n"
        "foo=bar&bar=foo";
    req.parse_http_request(raw);
    std::cout << req.get_method() << std::endl;
    std::cout << req.get_path() << std::endl;
    std::cout << req.get_http_verion() << std::endl;
}
