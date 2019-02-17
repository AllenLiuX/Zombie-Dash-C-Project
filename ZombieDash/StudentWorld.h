#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "Actor.h"
#include <string>

// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp
class Actor;
class Penelope;
class Wall;

class StudentWorld : public GameWorld
{
public:
    StudentWorld(std::string assetPath);
    ~StudentWorld(){this->cleanUp(); }
    virtual int init();
    virtual int move();
    virtual void cleanUp();
    bool hasWall(int x, int y);
private:
    std::vector<Actor*> m_actors;
    Penelope* m_penel;
    std::vector<Wall*> m_walls;
    
};

#endif // STUDENTWORLD_H_
