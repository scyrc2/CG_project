#pragma once
#include "DisplayableObject.h"
#include "Animation.h"

class Fan :
	public DisplayableObject,
	public Animation
{
public:
	Fan();
	~Fan(){};

	void Display();
	void Update(const double& deltaTime);

private:

	int keyframe;               // variable to track which keyframe we are on
	double animateTime;          // variable to store the current time the animation has run for
	double animateRotation;      // variable to track the current amount of rotation steps

	//several radius values used in the project
	double R = 8.0;
	double R2 = 1.0;
	double R3 = 2.0;
	double R4 = 10.0;
	double R5 = 8.0;

	//Pi value
	double Pi = 3.1415927;


	//functions to draw different units of the Fan
	void DrawPillar();
	void DrawBase();
	void DrawP1();
	void DrawP2();
	void DrawP3();
	void DrawFanBlade();
};

