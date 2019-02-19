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

bool StudentWorld::hasBlock(int x, int y){
    for(int i=0; i< m_blocks.size(); i++)
        if(m_blocks[i]->getX()/SPRITE_WIDTH == x && m_blocks[i]->getY()/SPRITE_HEIGHT == y)
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
                m_people.push_back(m_penel);
                m_blocks.push_back(m_penel);
            }
            if(ge == Level::wall){
                m_walls.push_back(new Wall(this, i*SPRITE_WIDTH, j*SPRITE_HEIGHT));
                m_blocks.push_back(m_walls.back());
                m_actors.push_back(m_walls.back());
            }
            if(ge == Level::exit){
                m_exit = new Exit(this, i*SPRITE_WIDTH, j*SPRITE_HEIGHT);
                m_blocks.push_back(m_exit);
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
        if(!m_penel->isAlive())
            return GWSTATUS_PLAYER_DIED;
    }
    decLives(); //????
    return GWSTATUS_CONTINUE_GAME;

}

void StudentWorld::cleanUp()
{
    for (int i=0; i<m_actors.size(); i++)
        delete m_actors[i];
    
}
