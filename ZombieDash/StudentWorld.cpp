#include "StudentWorld.h"
#include "GameConstants.h"
#include "Level.h"
#include <string>
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

bool StudentWorld::hasWall(int x, int y){
    for(int i=0; i< m_walls.size(); i++)
        if(m_walls[i]->getX()/SPRITE_WIDTH == x && m_walls[i]->getY()/SPRITE_HEIGHT == y)
            return true;
    return false;
}

int StudentWorld::init()
{
    Level lev(assetPath());
    string levelFile = "level01.txt";
    Level::LoadResult result = lev.loadLevel(levelFile);
    for (int i=0; i<16; i++){
        for(int j=0; j<16; j++){
            Level::MazeEntry ge = lev.getContentsOf(i, j);
            if(ge == Level::player){
                m_penel = new Penelope(this, i*SPRITE_WIDTH, j*SPRITE_HEIGHT);
                m_actors.push_back(m_penel);
            }
            if(ge == Level::wall){
                m_walls.push_back(new Wall(this, i*SPRITE_WIDTH, j*SPRITE_HEIGHT));
                m_actors.push_back(m_walls.back());
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
        if(!m_penel->isAlive())
            return GWSTATUS_PLAYER_DIED;
    }
    decLives(); //????
    return GWSTATUS_CONTINUE_GAME;

}

void StudentWorld::cleanUp()
{
    delete m_penel;
    for (int i=0; i<m_walls.size(); i++)
        delete m_walls[i];
    
}
