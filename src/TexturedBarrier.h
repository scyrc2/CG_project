#pragma once

#include "DisplayableObject.h"
#include "Animation.h"

#include <string>

class TexturedBarrier :
	public DisplayableObject,
	public Animation
{
public:
	//TexturedBarrier();
	TexturedBarrier(const std::string& filename);
	~TexturedBarrier() {}

	void Display();
	void Update(const double& deltaTime);

private:

	void DrawBarrierUnit();
	void DrawBarriers();

	GLint texID;
};

