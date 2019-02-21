#include "StudentWorld.h"
#include "GameConstants.h"
#include "Level.h"
#include <string>
#include <cmath>
using namespace std;


GameWorld* createStudentWorld(string assetPath)
{
	return new StudentWorld(assetPath);
}

// Students:  Add code to this file, StudentWorld.h, Actor.h and Actor.cpp

StudentWorld::StudentWorld(string assetPath)
: GameWorld(assetPath)
{
    
    
}

bool StudentWorld::hasBlock(double x, double y){
    for(int i=0; i< m_blocks.size(); i++){
        double dx = abs(m_blocks[i]->getX() - x);
        double dy = abs(m_blocks[i]->getY() - y);
        if(dx <= SPRITE_WIDTH-1 && dy <= SPRITE_HEIGHT-1)
            return true;
    }
    return false;
    
//    for(int i=0; i< m_blocks.size(); i++)
//        if(m_blocks[i]->getX()/SPRITE_WIDTH == x && m_blocks[i]->getY()/SPRITE_HEIGHT == y)
//            return true;
//    return false;
}

bool StudentWorld::exitOverlap(double x, double y){
    for(int i=0; i<m_people.size(); i++){
        double dx = m_people[i]->getX()-x;
        double dy = m_people[i]->getY()-y;
        if(dx*dx + dy*dy <= 100){
            m_people[i]->setExit();
//            delete m_people[i];
            return true;
        }
    }
    return false;
}

//bool overlap(double x1, double y1, double x2, double y2){
//    double dx = x1-x2;
//    double dy = y1-y2;
//    if(dx*dx + dy*dy <= 100)
//        return true;
//    else return false;
//}

int StudentWorld::init()
{
    Level lev(assetPath());
    string levelFile= "level01.txt";
    switch(getLevel()){
        case 1: levelFile = "level01.txt"; break;
        case 2: levelFile = "level02.txt"; break;
        case 3: levelFile = "level03.txt"; break;
        case 4: levelFile = "level04.txt"; break;
        case 5: levelFile = "level05.txt"; break;
        case 6: levelFile = "level06.txt"; break;
    }
    
    Level::LoadResult result = lev.loadLevel(levelFile);
    if(result == Level::load_fail_file_not_found || result == Level::load_fail_bad_format)
        return GWSTATUS_LEVEL_ERROR;
    for (int i=0; i<16; i++){
        for(int j=0; j<16; j++){
            Level::MazeEntry ge = lev.getContentsOf(i, j);
            if(ge == Level::player){
                m_penel = new Penelope(this, i*SPRITE_WIDTH, j*SPRITE_HEIGHT);
                m_actors.push_back(m_penel);
                m_people.push_back(m_penel);
//                m_blocks.push_back(m_penel);
            }
            if(ge == Level::wall){
                m_walls.push_back(new Wall(this, i*SPRITE_WIDTH, j*SPRITE_HEIGHT));
                m_blocks.push_back(m_walls.back());
                m_actors.push_back(m_walls.back());
            }
            if(ge == Level::exit){
                m_exit = new Exit(this, i*SPRITE_WIDTH, j*SPRITE_HEIGHT);
//                m_blocks.push_back(m_exit);
                m_actors.push_back(m_exit);
            }
        }
    }

    return GWSTATUS_CONTINUE_GAME;
}

int StudentWorld::move()
{
    // This code is here merely to allow the game to build, run, and terminate after you hit enter.
    // Notice that the return value GWSTATUS_PLAYER_DIED will cause our framework to end the current level.
    
    for(int i=0; i<m_actors.size(); i++){
        if(m_actors[i]->isAlive()){
            m_actors[i]->doSomething();
        }
        if(!m_penel->isAlive()){
            decLives();
            return GWSTATUS_PLAYER_DIED;
        }
        if(m_penel->isExit()){
            increaseScore(1000);
            return GWSTATUS_FINISHED_LEVEL;
        }
    }
    return GWSTATUS_CONTINUE_GAME;

}

//void StudentWorld::clean(Actor*){
//    long size = m_actors.size();
//    for (int i=0; i<m_actors.size(); i++){
//        delete m_actors[size];
//        m_actors.pop_back();
//    }
//}

void StudentWorld::cleanUp()
{
    long size = m_actors.size();
    for (int i=0; i<size; i++){
        delete m_actors.back();
        m_actors.pop_back();
    }
    for(int i=0; i<m_walls.size(); i++)
        m_walls.pop_back();
    for(int i=0; i<m_blocks.size(); i++)
        m_blocks.pop_back();
    
    
}
