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
class Pit;
class VaccineGoodie;
class GascanGoodie;
class LandmineGoodie;


class StudentWorld : public GameWorld
{
public:
    StudentWorld(std::string assetPath);
    ~StudentWorld(){this->cleanUp(); }
    virtual int init();
    virtual int move();
    virtual void cleanUp();
    bool hasBlock(double x, double y);
//    void deleteActorAt(int i){delete m_actors[i];}
    bool exitOverlap(double x, double y);
    bool goodieOverlap(double x, double y);
    void clean(Actor*);
    
    void changeVacc(int i){n_Vacc += i;}
    void changeFlames(int i) {n_Flames += i;}
    void changeMines(int i) {n_mines += i;}
    void changeInfected(int i) {n_Infected += i;}
    void popActor(double x, double y);
//    template <typename Mvector>
//    void pop(Mvector a, double x, double y);
    void pop(vector<Actor*> vec, double x, double y);
private:
    int n_Vacc;
    int n_Flames;
    int n_mines;
    int n_Infected;
    
    vector<Actor*> m_actors;
    
    vector<Block*> m_blocks;    //wall, exit, people
    vector<Wall*> m_walls;
    Exit* m_exit;
    vector<Person*> m_people;   //citizen, penel
    vector<Citizen*> m_citizens;
    Penelope* m_penel;
    
    vector<Goodie*> m_goodies;  //vaccine, gascan, landminegoodie
    vector<VaccineGoodie*> m_vaccines;
    vector<GascanGoodie*> m_gascans;
    vector<LandmineGoodie*> m_landminegoodies;
    
    vector<Zombie*> m_zombies;  //dumb, smart
    vector<DumbZombie*> m_dumbZombies;
    vector<SmartZombie*> m_smartZombies;
    
    vector<Pit*> m_pits;
    

    
};

#endif // STUDENTWORLD_H_
