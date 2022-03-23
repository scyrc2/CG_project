#pragma once

#include "DisplayableObject.h"
#include "Animation.h"
#include <map>
#include <string>

// Pointer index for vertex 0
#define _VERTEX0 0
// Pointer index for vertex 1
#define _VERTEX1 3
// Pointer index for vertex 2
#define _VERTEX2 6
// Pointer index for vertex 3
#define _VERTEX3 9
// Pointer index for vertex 4
#define _VERTEX4 12
// Pointer index for vertex 5
#define _VERTEX5 15

#define PI 3.1415926

class TexturedBall :
	public DisplayableObject,
	public Animation
{
public:
	TexturedBall();
	TexturedBall(const std::string& filename);
	~TexturedBall() {};

	void Display();
	void Update(const double& deltaTime);

	void SetTexture(const std::string& filename);

private:
	// Rate of rotation in x and y (degrees per second) 
	float _xrot, _yrot;

	// Initial vertices
	float* _initV;
	GLboolean _flagWireFrame; 
	GLboolean _flagAnimation;

	GLint texID;

	
	void DrawSphere();
	void SubDivide(int recurse_idx, float* a, float* b, float* c);
	void DrawFace(float* a, float* b, float* c);
	void FixSeam(float& a, float& b, float& c);


	int keyframe;               // variable to track which keyframe we are on
	double animateTime;          // variable to store the current time the animation has run for
	double animateRotation;      // variable to track the current amount of rotation steps

	double animateTransmissionX;	//three dimension movement
	double animateTransmissionY;
	double animateTransmissionZ;
	
	double keyTransmissionX;	
	double keyTransmissionY;
	double keyTransmissionZ;

	double ballsPositionX[50];	//store the random positions for 50 balls on floor
	double ballsPositionZ[50];


};
