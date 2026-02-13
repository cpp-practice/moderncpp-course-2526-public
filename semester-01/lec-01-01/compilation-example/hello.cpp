#include "hello.hpp"

#include <iostream>

#define PRIVATE_TOKEN 42                            // macro

static int private_access_token = PRIVATE_TOKEN;    // (internal linkage)
int access_token = private_access_token; // definition (external linkage)

void hello(int) { // definition (external linkage)
    if (private_access_token == access_token) {
        std::cout << "hello, world!";
    } else {
        std::cerr << "Access denied!";
    }
}
