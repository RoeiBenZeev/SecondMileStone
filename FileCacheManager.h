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
template <typename P,typename S>
//global to run the loop
class FileCacheManager : public CacheManager<P,string> {
    unsigned int cacheSize;
    unordered_map<P, std::pair<S, typename list<P>::iterator>> cacheMemory;
    list<P> myList;
    string hashString(const P& key);
    void updateCache(P);
    void writeToFile(P, S);
    void deleteLRU();
    bool containsKey(P);
    void addToMap(P, S);

  public:
    void insert(P, S);
    FileCacheManager(int);
    string get(P);

    void foreach(const function<void(S &)>);

};

template <typename P,typename S>
//constructor
FileCacheManager<P,S>::FileCacheManager(int size) {
    this->cacheSize = size;

}
template <typename P,typename S>

//insert method
void FileCacheManager<P,S>::insert(P key, S obj) {
    //key = hashString(key);
    //check if the key is already in the cache
    if(this->containsKey(key)) {
        updateCache(key);
        //list<string>::iterator it = myList.begin();
        //update new obj and iterator
        list<string>::iterator it = myList.begin();
        cacheMemory[key] = {obj, it};
        // his key isnt it the cache
    } else {
        //first need to delete
        if (this->cacheMemory.size() == cacheSize) {
            deleteLRU();
            //add to map
            addToMap(key, obj);
        }
        if (this->cacheMemory.size() < cacheSize) {
            addToMap(key, obj);
        }
    }
    writeToFile(key, obj);
}
template <typename P,typename S>

//update our cache order for existing key
void FileCacheManager<P,S>::updateCache(P key) {
    //key = hashString(key);
    //delete current key recently used from prev location.
    myList.erase(cacheMemory[key].second);
    //our last used key will be first now.
    myList.push_front(key);
}
template <typename P,typename S>

void FileCacheManager<P,S>::deleteLRU() {
    //delete last used item
    string buffer = myList.back();
    cacheMemory.erase(buffer);
    myList.pop_back();
}
template <typename P,typename S>

//check if out map contains th key.
bool FileCacheManager<P,S>::containsKey(P key) {
    //key = hashString(key);
    typename std::unordered_map<std::string, std::pair<string,
    typename list<string>::iterator>>::iterator it
        = cacheMemory.find(key);
    if(it != cacheMemory.end()) {
        return true;
    }
    return false;
}
template <typename P,typename S>
//add key value to the map with iterator.
void FileCacheManager<P,S>::addToMap(P key, S value) {
    //key = hashString(key);
    myList.push_front(key);
    list<string>::iterator it = myList.begin();
    cacheMemory[key] = {value, it};
}
template <typename P,typename S>
void FileCacheManager<P,S>::writeToFile(P key, S obj) {
    //key = hashString(key);
    //open a stream for writing
    std::ofstream writer(key+".txt",std::ios::binary | std::ofstream::trunc);
    if(!writer || !writer.is_open()) {
        throw "error happened in opening file for writing";
    }
    writer << obj;
    if(writer.fail()) {
        throw "Error happened in writing to file";
    }
    writer.close();
}
template <typename P,typename S>
string FileCacheManager<P,S>::get(P key) {
    //key = hashString(key);
    //this key is in the cache
    if(this->containsKey(key)) {
        //we updated the LRU algorithm
        updateCache(key);
        cout << "the solution is in the cache"<< std::flush;
        //return our key object
        return cacheMemory[key].first;
    } else {
        string b = key+".txt";
        std::ifstream reader(b,std::ios::binary);
        if(!reader || !reader.is_open()) {
            throw "No such object";
        }
        string buffer;
        //reading out object from a file
        reader >> buffer;
        //check if file open currectly
        if(!reader) {
            throw "error happened in opening file for reading";
        }
        //check our cache size
        if (this->cacheMemory.size() == cacheSize) {
            deleteLRU();
            //add to map
            addToMap(key, buffer);
        } else {
            addToMap(key, buffer);
        }
        reader.close();
        cout << "the solution is in the files"<< std::flush;
        //return wanted object
        return buffer;
    }
}
template <typename P,typename S>
void FileCacheManager<P,S>::foreach(const function<void(S &)> func) {
    for(auto i : myList) {
        func(cacheMemory[i].first);
    }
}
template <typename P,typename S>
string FileCacheManager<P,S>::hashString(const P& key){
    hash<string> hash;
    size_t hashedKey = hash(key);
    char buf[24]; // just big enough
    snprintf(buf, sizeof buf, "%zu", hashedKey);
    string newKey(buf);
    return newKey;
}

#endif //SECONDMILESTONE__FILECACHEMANAGER_H_
