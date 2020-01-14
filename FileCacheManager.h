//
// Created by roei on 12/01/2020.
//

#ifndef SECONDMILESTONE__FILECACHEMANAGER_H_
#define SECONDMILESTONE__FILECACHEMANAGER_H_

#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>
#include <list>
#include <fstream>
#include <functional>
#include "CacheManager.h"

using namespace std;

//global to run the loop
class FileCacheManager : public CacheManager<string,string> {
    unsigned int cacheSize;
    unordered_map<std::string, std::pair<string, typename list<string>::iterator>> cacheMemory;
    list<string> myList;

    void updateCache(string);
    void writeToFile(string, string);
    void deleteLRU();
    bool containsKey(string);
    void addToMap(string, string);

  public:
    void insert(string, string);
    FileCacheManager(int);
    string get(string);

    void foreach(const function<void(string &)>);

};



#endif //SECONDMILESTONE__FILECACHEMANAGER_H_
