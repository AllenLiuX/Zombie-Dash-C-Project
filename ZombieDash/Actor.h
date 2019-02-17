#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
#include "StudentWorld.h"

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp
class StudentWorld;

class Actor: public GraphObject{
public:
    Actor(int imageID, double startX, double startY, int startDirection, int depth): GraphObject(imageID, startX, startY, startDirection, depth){
    }
    virtual void doSomething() {return;}
private:
//   StudentWorld* sWorld;

};

class Wall: public Actor{
public:
    Wall(double startX, double startY): Actor(IID_WALL, startX, startY, right, 0){
        
    }
    //    virtual void doSomething() {return;}
    
};

class Penelope: public Actor{
public:
    Penelope(StudentWorld* world, double startX, double startY): Actor(IID_PLAYER, startX, startY, right, 0){
        alive = true;
        m_world = world;
    }
    virtual void doSomething();
    bool isAlive() {return alive;}
private:
    StudentWorld* m_world;
    bool alive;
    
};

#endif // ACTOR_H_
