#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
#include "StudentWorld.h"

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp
class StudentWorld;

class Actor: public GraphObject{
public:
    Actor(int imageID, double startX, double startY, int depth): GraphObject(imageID, startX, startY, right, depth){
        alive = true;
    }
    bool isAlive() {return alive;}
    virtual void doSomething()=0;
private:
    bool alive;

};
//===================Super Class ====================
class Block: public Actor{
public:
    Block(int imageID, double startX, double startY, int depth): Actor(imageID, startX, startY, depth){
        
    }
};


class Zombie: public Actor{
public:
    Zombie(int imageID, double startX, double startY): Actor(imageID, startX, startY, 0){
    
    }
};

class Goodie: public Actor{
public:
    Goodie(int imageID, double startX, double startY): Actor(imageID, startX, startY, 1){
        
    }
};



//======================Base Class #2==============
class Person: public Block{
public:
    Person(int imageID, double startX, double startY): Block(imageID, startX, startY, 0){
        infected = false;
    }
    bool isInfected() {return infected;}
    
private:
    bool infected;
};

class Wall: public Block{
public:
    Wall(StudentWorld* world, double startX, double startY): Block(IID_WALL, startX, startY, 0){
        m_world = world;
    }
    virtual void doSomething() {return;}
private:
    StudentWorld* m_world;
};

class Exit: public Block{
public:
    Exit(StudentWorld* world, double startX, double startY): Block(IID_EXIT, startX, startY, 1){
        m_world = world;
    }
    virtual void doSomething() {return;}
private:
    StudentWorld* m_world;
};


class DumbZombie: public Zombie{
public:
    DumbZombie(int imageID, double startX, double startY): Zombie(imageID, startX, startY){
        
    }
    virtual void doSomething();
    
};

class SmartZombie: public Zombie{
public:
    SmartZombie(int imageID, double startX, double startY): Zombie(imageID, startX, startY){
        
    }
    virtual void doSomething();
};
//================Class #3=====================

class Penelope: public Person{
public:
    Penelope(StudentWorld* world, double startX, double startY): Person(IID_PLAYER, startX, startY){
        m_world = world;
    }
    virtual void doSomething();
private:
    StudentWorld* m_world;
    
};

class Citizen: public Person{
public:
    Citizen(StudentWorld* world, double startX, double startY): Person(IID_CITIZEN, startX, startY){
        m_world = world;
    }
private:
    StudentWorld* m_world;
};
//==================



#endif // ACTOR_H_
