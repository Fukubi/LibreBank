#ifndef CLEAR_H
#define CLEAR_H

#if _WIN32
  #define CLEAR "cls"
#elif __linux__
  #define CLEAR "clear"
#endif

#endif