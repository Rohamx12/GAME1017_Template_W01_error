#pragma once

#ifndef _BOX_H_
#define _BOX_H_
#include <SDL.h>

class Sprite //visual component of a Box
{
private:
	SDL_Rect m_dst; //position of colored Box on screen
	SDL_Color m_color; // random color box
	

public:
	Sprite(const SDL_Point p);
	void Render();
	friend class Box; //box has access to sprite
	
	
	
};



class Box
{
private:
	
	SDL_Point m_pos; //position on screen
	Sprite* m_pSprite; //pointer to visual component
	
	
	

public:
	
	Box(const SDL_Point p , bool hasSprite = false);
	~Box();
	void Update();
	void Render();
	const SDL_Point GetPos() { return m_pos; }
	


	
	
};


#endif
