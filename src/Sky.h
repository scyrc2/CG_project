#pragma once

#include "DisplayableObject.h"
#include "Animation.h"
#include "Input.h"

#include <string>

class Sky :
	public DisplayableObject,
	public Animation,
	public Input
{
public:
	Sky(const int& gridX, const int& gridZ, const std::string& filename);
	~Sky();

	void Display();
	void Update(const double& delteTime);

private:
	int texID;					

	int xGridDims, zGridDims;
	float* texCoords;
	double time;
	bool frozen;

	float matAmbient[4];      // matrial properties of the grid
	float matDiffuse[4];
	int   matShininess;
	float matSpecular[4];
};

