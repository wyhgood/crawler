#include <iostream>
#include <curl/curl.h>
#include <thread>
#include "scan.h"
#include <cstring>
using namespace std;

size_t write_to_string(void *ptr, size_t size, size_t count, void *stream){
  ((string*)stream)->append((char*)ptr, 0, size*count);
  return size*count;
}

int SCAN::http_get(string ip_port){
  CURL *curl;
  curl = curl_easy_init();
  string flag = "030173";
  char ip[50]; 
  strcpy(ip, ip_port.c_str());
  //ip_port.c_str();
  int isfound;
  if(curl){
    //cout<< "bbbbbbb" <<endl;
    curl_easy_setopt(curl, CURLOPT_PROXY, ip);
    curl_easy_setopt(curl, CURLOPT_URL, "http://www.baidu.com");
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5); // 设置超时时间
    string response = "";
    //cout<< "aaaaaaa" <<endl;
    curl_easy_setopt(curl, CURLOPT_LOW_SPEED_LIMIT, 1L);
    curl_easy_setopt(curl, CURLOPT_LOW_SPEED_TIME, 5L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_to_string);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    CURLcode res = curl_easy_perform(curl);
    //cout<<response<<endl;
    curl_easy_cleanup(curl);
    isfound = response.find(flag);
    cout<< isfound<<endl;    
  }  
  return isfound;
}

