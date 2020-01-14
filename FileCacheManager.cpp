
#include "FileCacheManager.h"

//constructor
FileCacheManager::FileCacheManager(int size) {
    this->cacheSize = size;

}

//insert method
void FileCacheManager::insert(string key, string obj) {

    //check if the key is already in the cache
    if (this->containsKey(key)) {
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

//update our cache order for existing key
void FileCacheManager::updateCache(string key) {
    //delete current key recently used from prev location.
    myList.erase(cacheMemory[key].second);
    //our last used key will be first now.
    myList.push_front(key);
}

void FileCacheManager::deleteLRU() {
    //delete last used item
    string buffer = myList.back();
    cacheMemory.erase(buffer);
    myList.pop_back();
}

//check if out map contains th key.
bool FileCacheManager::containsKey(string key) {
    typename std::unordered_map<std::string, std::pair<string,
    typename list<string>::iterator>>::iterator it
                                                    = cacheMemory.find(key);
    if(it != cacheMemory.end()) {
        return true;
    }
    return false;
}

//add key value to the map with iterator.
void FileCacheManager::addToMap(string key, string value) {
    myList.push_front(key);
    list<string>::iterator it = myList.begin();
    cacheMemory[key] = {value, it};
}

void FileCacheManager::writeToFile(string key, string obj) {

    //open a stream for writing
    std::ofstream writer(key + ".txt", std::ios::out | std::ofstream::trunc);
    if (!writer || !writer.is_open()) {
        throw "error happened in opening file for writing";
    }
    writer << obj;
    if (writer.fail()) {
        throw "Error happened in writing to file";
    }
    writer.close();
}

string FileCacheManager::get(string key) {
    //this key is in the cache
    if (this->containsKey(key)) {
        //we updated the LRU algorithm
        updateCache(key);
        //return our key object
        return cacheMemory[key].first;
    } else {
        string b = key + ".txt";
        std::ifstream reader(key, std::ios::in);
        if (!reader || !reader.is_open()) {
            throw "No such object";
        }
        string buffer;
        //reading out object from a file
        reader >> buffer;
        //check if file open currectly
        if (!reader) {
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
        //return wanted object
        return buffer;
    }
}

void FileCacheManager::foreach(const function<void(string &)> func) {
    for (auto i : myList) {
        func(cacheMemory[i].first);
    }
}

string hashString(const string& key){
    hash<string> hash;
    size_t hashedKey = hash(key);
    char buf[24]; // just big enough
    snprintf(buf, sizeof buf, "%zu", hashedKey);
    string newKey(buf);
    return newKey;
}

