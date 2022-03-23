#pragma once
#include "DisplayableObject.h"
#include "Animation.h"

class SnowmanWatcher : 
	public DisplayableObject,
	public Animation
{
public:
	SnowmanWatcher();
	~SnowmanWatcher() {};

	void Display();
	void Update(const double& deltaTime);

private:
	void DrawSnowman(int id);			//function to draw the snowman object
	void DrawSnowman2(int id);			//function to draw the snowman object
	void DrawArm(int id);				//function to draw the arm

	int keyframe;               // variable to track which keyframe we are on
	int keyframe2;               // variable to track which keyframe we are on
	double animateTime;          // variable to store the current time the animation has run for
	double animateTime2;          // another variable to store the current time the animation has run for
	double animateRotation;		//clapping
	double animateRotation2;	//waving
	double animateTransmission;	//jumping
	
	double keyRotation;
	double keyRotation2;
	double keyTransmission;

};

