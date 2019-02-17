#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "Actor.h"
#include <string>

// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp
class Penelope;

class StudentWorld : public GameWorld
{
public:
    StudentWorld(std::string assetPath);
    //    ~StudentWorld();
    virtual int init();
    virtual int move();
    virtual void cleanUp();

private:
    Penelope* penel;
    
//    Wall* wall;
};

#endif // STUDENTWORLD_H_
