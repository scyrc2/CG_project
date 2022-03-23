#pragma once
#include "DisplayableObject.h"
#include "Animation.h"
#include "Input.h"


class Table :
	public DisplayableObject,
	public Animation,
	public Input
{
public:
	Table();
	~Table();

	void Display();
	void Update(const double& deltaTime) {};
private:
	void DrawTable();		
	void DrawNet();				
	void DrawNetUnit();		//draw the net bracket

};
