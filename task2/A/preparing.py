#!/usr/bin/python3

header_name = "./index.h";

code = '''\
#ifndef __HEADER_INDEX_H
#define __HEADER_INDEX_H

#include <iostream>
#include <string>

void echo (const std::string& text) {
      std::cout << text << std::endl;
}

int fiver () {
      return 5;
}
#endif\
'''

def generate_header(name):
    with open (name, "w") as out_file:
        out_file.write (code)

if __name__ == "__main__":
    generate_header (header_name)
