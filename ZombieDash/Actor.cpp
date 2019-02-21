#include "Actor.h"
#include "StudentWorld.h"

// Students:  Add code to this file, Actor.h, StudentWorld.h, and StudentWorld.cpp

//Penelope::Penelope()




void Penelope::doSomething(){
    if(!isAlive())
        return;
    int dir = 0;
    
    if(m_world->getKey(dir)){
        
        if(dir == KEY_PRESS_UP){
            setDirection(up);
            if(!m_world->hasBlock(getX(), getY() + 1))
                moveTo(getX(), getY()+4);
        }
        if(dir == KEY_PRESS_DOWN){
            setDirection(down);
            if(!m_world->hasBlock(getX(), getY()-1))    //getY()-1 to make penel a little bit left!
                moveTo(getX(), getY()-4);
        }
        if(dir == KEY_PRESS_LEFT){
            setDirection(left);
            if(!m_world->hasBlock(getX()-1, getY()))
                moveTo(getX()-4, getY());
        }
        if(dir == KEY_PRESS_RIGHT){
            setDirection(right);
            if(!m_world->hasBlock(getX()+1, getY()))
                moveTo(getX()+4, getY());
        }
        
    }
}

void Exit::doSomething(){
    m_world->exitOverlap(getX(), getY());
}

void Goodie::doSomething(){
    
}

