#pragma once
#include "DisplayableObject.h"
#include "Animation.h"

class Sofa :
	public DisplayableObject,
	public Animation
{
public:
	Sofa();
	~Sofa() {};

	void Display();
	void Update(const double& deltaTime);

private:
	void DrawSofa();
	void DrawLamp();

	double Pi = 3.1415926;
	double R = 1.0;

};
