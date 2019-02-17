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
            this->moveTo(getX(), getY()+1);
        }
        if(dir == KEY_PRESS_DOWN){
            this->moveTo(getX(), getY()-1);
        }
        if(dir == KEY_PRESS_LEFT){
            this->moveTo(getX()-1, getY());
        }
        if(dir == KEY_PRESS_RIGHT){
            this->moveTo(getX()+1, getY());
        }
    }
}
