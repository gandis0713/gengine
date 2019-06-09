#ifndef DELOG_H
#define DELOG_H

#include <iostream>

#if WIN32
#define tlog(text) \
    std::cout << "[" << __FUNCSIG__ << "]" << " " << text << std::endl
#else
#define tlog(text) \
    std::cout << "[" << __PRETTY_FUNCTION__ << "]" << " " << text << std::endl
#endif

#endif // DELOG_H
