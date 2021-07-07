#include "Box.h"
#include "Engine.h"
#include <cstdlib>

#define SCROLLSPD 2

Sprite::Sprite(const SDL_Point p)
//:m_dst({ p.x,p.y,128,128 })
// m_color()
{
	m_dst = { p.x,p.y,128,128 };
	m_color = { (Uint8)(rand() % 256),(Uint8)(rand() % 256),(Uint8)(rand() % 256),255 };

}

void Sprite::Render()
{
	SDL_SetRenderDrawColor(Engine::Instance().GetRenderer(), m_color.r, m_color.g, m_color.b, m_color.a);
	SDL_RenderFillRect(Engine::Instance().GetRenderer(), &m_dst);
	
}

Box::Box(const SDL_Point p, bool hasSprite):m_pos(p), m_pSprite(nullptr)
{
	if (hasSprite)
		m_pSprite = new Sprite(m_pos);
}

Box::~Box()
{
	if(m_pSprite != nullptr)
	{
		delete m_pSprite;
		m_pSprite = nullptr;//Wrangle Dangle
		
	}
}

void Box::Update()
{
	m_pos.x -= SCROLLSPD;
	if (m_pSprite != nullptr)
		m_pSprite->m_dst.x = m_pos.x;
	
}

void Box::Render()
{
	if (m_pSprite != nullptr)
		m_pSprite->Render();
	// Optional outline for empty boxes
	SDL_Rect m_dst = { m_pos.x,m_pos.y,128,128 };
	SDL_SetRenderDrawColor(Engine::Instance().GetRenderer(),255,0,255,255);
	SDL_RenderFillRect(Engine::Instance().GetRenderer(), &m_dst);
}
