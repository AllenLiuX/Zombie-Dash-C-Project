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

int StudentWorld::init()
{
    Level lev(assetPath());
    string levelFile = "level01.txt";
    Level::LoadResult result = lev.loadLevel(levelFile);
    for (int i=0; i<16; i++){
        for(int j=0; j<16; j++){
            Level::MazeEntry ge = lev.getContentsOf(i, j);
            if(ge == Level::player)
                penel = new Penelope(this, i*SPRITE_WIDTH, j*SPRITE_HEIGHT);
            if(ge == Level::wall)
                wall.push_back(new Wall(this, i*SPRITE_WIDTH, j*SPRITE_HEIGHT));
        }
    }
//    penel = new Penelope(this, 200.0, 100.0);
//    wall = new Wall(this, 10.0, 10.0);

    return GWSTATUS_CONTINUE_GAME;
}

int StudentWorld::move()
{
    // This code is here merely to allow the game to build, run, and terminate after you hit enter.
    // Notice that the return value GWSTATUS_PLAYER_DIED will cause our framework to end the current level.
    
    
    if(penel->isAlive()){
        penel->doSomething();
        return GWSTATUS_CONTINUE_GAME;
    }
    decLives();
    return GWSTATUS_PLAYER_DIED;
}

void StudentWorld::cleanUp()
{
}
