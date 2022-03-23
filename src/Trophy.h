#pragma once
#include "DisplayableObject.h"
#include "Animation.h"

class Trophy :
	public DisplayableObject,
	public Animation
{
public:
	Trophy();
	~Trophy() {};

	void Display();
	void Update(const double& deltaTime);

private:
	void DrawTrophy();
	void DrawFoot();				//draw the cup foot
	void DrawFace();				//draw the cup face
	void DrawEars();				//deaw the cup ears
	void DrawCylinder(double R1, double R2);

	double Pi = 3.1415926;

	double animateTime;          // variable to store the current time the animation has run for
	double animateRotation;      // variable to track the current amount of rotation steps
};
