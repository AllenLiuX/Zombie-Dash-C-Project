#include "Actor.h"
#include "StudentWorld.h"

// Students:  Add code to this file, Actor.h, StudentWorld.h, and StudentWorld.cpp

//Penelope::Penelope()

void Penelope::doSomething(){
    if(!isAlive())
        return;
    int dir = 0;
//    int X = getX();
//    int Y = getY();
    
    if(m_world->getKey(dir)){
        if(dir == KEY_PRESS_UP){
            setDirection(up);
            if(!m_world->hasWall(getX()/SPRITE_WIDTH, getY()/SPRITE_HEIGHT + 1))
                moveTo(getX(), getY()+4);
        }
        if(dir == KEY_PRESS_DOWN){
            setDirection(down);
            if(!m_world->hasWall(getX()/SPRITE_WIDTH, (getY()-1)/SPRITE_HEIGHT))    //getY()-1 to make penel a little bit left!
                moveTo(getX(), getY()-4);
        }
        if(dir == KEY_PRESS_LEFT){
            setDirection(left);
            if(!m_world->hasWall((getX()-1)/SPRITE_WIDTH, getY()/SPRITE_HEIGHT))
                moveTo(getX()-4, getY());
        }
        if(dir == KEY_PRESS_RIGHT){
            setDirection(right);
            if(!m_world->hasWall(getX()/SPRITE_WIDTH+1, getY()/SPRITE_HEIGHT))
                moveTo(getX()+4, getY());
        }
    }
}
