#!/usr/bin/python3

header_name = "./index.h";

code = '''\
#include <iostream>
#include <string>

void echo (const std::string& text) {
      std::cout << text << std::endl;
}\
'''

def generate_header(name):
    with open (name, "w") as out_file:
        out_file.write (code)

if __name__ == "__main__":
    generate_header (header_name)
