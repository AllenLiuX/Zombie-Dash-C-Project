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
    void setDead() {alive = false;}
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
    Goodie(StudentWorld* world, int imageID, double startX, double startY): Actor(imageID, startX, startY, 1){
        m_world = world;
    }
    bool overlapPenel();
    virtual void doSomething();
private:
    StudentWorld* m_world;
};

class Exit: public Actor{
public:
    Exit(StudentWorld* world, double startX, double startY): Actor(IID_EXIT, startX, startY, 1){
        m_world = world;
    }
    virtual void doSomething();
private:
    StudentWorld* m_world;
};

class Pit: public Actor{
public:
    Pit(StudentWorld* world, double startX, double startY): Actor(IID_PIT, startX, startY, 0){
        m_world = world;
    }
    virtual void doSomething(){return;}
private:
    StudentWorld* m_world;
};


//======================Base Class #2==============
class Person: public Block{
public:
    Person(int imageID, double startX, double startY): Block(imageID, startX, startY, 0){
        infected = false;
        exit = false;
    }
    bool isInfected() {return infected;}
    bool isExit() {return exit;}
    void setExit() {exit = true;}
    
private:
    bool infected;
    bool exit;
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

//====================Goodies =========================
class VaccineGoodie: public Goodie{
public:
    VaccineGoodie(StudentWorld* world, double startX, double startY): Goodie(world, IID_VACCINE_GOODIE, startX, startY){
    }
    virtual void doSomething(){return;}
private:
};

class GascanGoodie: public Goodie{
public:
    GascanGoodie(StudentWorld* world, double startX, double startY): Goodie(world, IID_GAS_CAN_GOODIE, startX, startY){
    }
    virtual void doSomething(){return;}
private:
};

class LandmineGoodie: public Goodie{
public:
    LandmineGoodie(StudentWorld* world, double startX, double startY): Goodie(world, IID_LANDMINE_GOODIE, startX, startY){
    }
    virtual void doSomething(){return;}
private:
};

//------------Zombies ---------------------

class DumbZombie: public Zombie{
public:
    DumbZombie(StudentWorld* world, double startX, double startY): Zombie(IID_ZOMBIE, startX, startY){
        m_world = world;
    }
    virtual void doSomething();
private:
    StudentWorld* m_world;
};

class SmartZombie: public Zombie{
public:
    SmartZombie(StudentWorld* world, double startX, double startY): Zombie(IID_ZOMBIE, startX, startY){
        m_world = world;
    }
    virtual void doSomething();
private:
    StudentWorld* m_world;
};
//================People =====================

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
