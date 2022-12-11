#pragma once

#include"Component.h"
#include"SDL.h"
#include<iostream>

#include "RendererManager.h"
#include "CameraManager.h"


/*
	Descriere clasa:

		-> constructori cu parametri:
			- folosit la incarcarea in memorie a sprite-urilor
			   (folosit doar in AssetsStorage)
		-> contructor de copiere (se aloca memorie dor pentru _dest) :
			- folosit la crearea mapei (fac o copie din memorie a sprite-ului)
			- sau la Animatii si posibil si in alte locuri
		-> desenez sprite-ul doar daca este in cadrul camerei
		->indetificator pentru obiectul urmarit de camera (default este player-ul)
*/
class SpriteComponent : public Component
{
	friend class AssetsStorage;
	friend class Map;
	friend class Tank;
	friend class Bullet;
	friend class Animation;

private:
	SDL_Rect* _src = nullptr;
	SDL_Rect* _dest = nullptr;
	SDL_Texture* _texture = nullptr;
	SDL_Point center = { 64 , 74 };
	float _angle = 0;

public:
	bool _isFollowed = false;
	bool _isTile = false;

	SpriteComponent() {}

	SpriteComponent(const char* source);

	SpriteComponent(SpriteComponent*& sprite);

	~SpriteComponent();

	void setSrcTextNullPtr() // se apeleaza inaintea stergerii un comonente ce are	
							 // o copie a unui sprite din AssetsStorage
	{
		_src = nullptr;
		_texture = nullptr;
	}

	void setAngle(float angle)
	{
		_angle = angle;
	}

	void setPosition(Vector2T<int> position)
	{
		_dest->x = position.getX();
		_dest->y = position.getY();
	}

	void isOnCamera();

	void draw() override;

	void update() override;

};


