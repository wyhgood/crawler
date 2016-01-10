#ifndef _SCAN_H
#define _SCAN_H


#include <iostream>
using namespace std;
class SCAN{
 public:
  SCAN(){};
  ~SCAN(){};
  
  int http_get(string ip);
  //size_t write_to_string(void *ptr, size_t size, size_t count, void *stream);
};

#endif
