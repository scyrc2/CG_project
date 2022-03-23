#pragma once
#include "DisplayableObject.h"
#include "Animation.h"

class Snowman :
	public DisplayableObject,
	public Animation
{
public:
	Snowman();
	~Snowman() {};

	void Display();
	void Update(const double& deltaTime);

private:
	void DrawSnowman(int id);			//function to draw the snowman object
	void DrawSnowman2();
	void DrawArm();				//function to draw the arm
	void DrawBat();
	void DrawBall();

	int id;
	int keyframe;               // variable to track which keyframe we are on
	int keyframe2;               
	int keyframe3;               
	double animateTime;          // variable to store the current time the animation has run for
	double animateTime3;          // variable to store the current time the animation has run for
	double animateTime4;          // variable to store the current time the animation has run for
	double animateRotation;      // variable to track the current amount of rotation steps
	double animateRotation2;      
	double animateRotation3;      
	double animateRotation4; 

	double animateTransmission;

	double animateScale;			// variable to track the current amount of scale steps

	double keyRotation;			//variable to store the key frame rotation value
	double keyRotation2;			
	double keyRotation3;			
	double keyRotation4;	

	double keyTransmission;

	double keyScale;				//variable to store the key frame scale value
};