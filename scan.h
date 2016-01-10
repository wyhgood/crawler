#ifndef _SCAN_H
#define _SCAN_H


#include <iostream>
#include <queue>
#include <mutex>
using namespace std;
class SCAN{
 public:
  mutex mtx;
  queue<string> tasks;
  
  SCAN(){
    for(int i=0; i<=1000; i++){
      string ip = "117.135.250.133:80";
      tasks.push(ip);
    }    
  };
  ~SCAN(){};
  
  void check_ip();
  int http_get(string ip);
  //size_t write_to_string(void *ptr, size_t size, size_t count, void *stream);
};

#endif
