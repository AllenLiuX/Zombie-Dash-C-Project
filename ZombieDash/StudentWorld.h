#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "Actor.h"
#include <string>
using namespace std;

// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp
class Actor;
class Person;
class Block;
class Zombie;
class Goodie;
class Penelope;
class Wall;
class Exit;
class Citizen;
class SmartZombie;
class DumbZombie;


class StudentWorld : public GameWorld
{
public:
    StudentWorld(std::string assetPath);
    ~StudentWorld(){this->cleanUp(); }
    virtual int init();
    virtual int move();
    virtual void cleanUp();
    bool hasBlock(int x, int y);
private:
    vector<Actor*> m_actors;
    vector<Block*> m_blocks;
    vector<Person*> m_people;
    vector<Goodie*> m_goodies;
    vector<Zombie*> m_zombies;
    Penelope* m_penel;
    vector<Wall*> m_walls;
    Exit* m_exit;
    vector<Citizen*> m_citizens;
    vector<DumbZombie*> m_dumbZombies;
    vector<SmartZombie*> m_smartZombies;
    
    
};

#endif // STUDENTWORLD_H_
