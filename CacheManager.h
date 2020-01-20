//
// Created by roei on 12/01/2020.
//

#ifndef SECONDMILESTONE__CACHEMANAGER_H_
#define SECONDMILESTONE__CACHEMANAGER_H_

template <typename P,typename S>
class CacheManager {
  public:
    virtual void insert(P,S) = 0;
    //virtual CacheManager* clone() = 0;

    virtual S get(P) = 0;

};

#endif //SECONDMILESTONE__CACHEMANAGER_H_
