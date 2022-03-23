#include "Fan.h"

Fan::Fan() :keyframe(-1), animateTime(0.0)
{
}

void Fan::Display()
{


	//Draw the first fan
	glPushMatrix();
	glTranslated(45.0, 0.15, -20.0);
	glScaled(0.2, 0.2, 0.2);
	glPushMatrix();
	glRotated(-90, 0.0, 1.0, 0.0);
	DrawBase();
	DrawPillar();
	glPopMatrix();
	glPopMatrix();

	//Draw the second fan
	glPushMatrix();
	glTranslated(45.0, 0.15, 20.0);
	glScaled(0.2, 0.2, 0.2);
	glPushMatrix();
	glRotated(-90, 0.0, 1.0, 0.0);
	DrawBase();
	DrawPillar();
	glPopMatrix();
	glPopMatrix();

	//Draw the third fan
	glPushMatrix();
	glTranslated(45.0, 0.15, -5.0);
	glScaled(0.2, 0.2, 0.2);
	glPushMatrix();
	DrawBase();
	DrawPillar();
	glPopMatrix();
	glPopMatrix();


}

void Fan::Update(const double& deltaTime)
{
	animateTime += static_cast<float>(deltaTime);

	//set the animation rotation 
	animateRotation = animateTime * 180.0;
}

//This function used to draw the pillar, blades, and cover
void Fan::DrawPillar()
{
	glPushMatrix();
	glColor3d(66 / 255.0, 134 / 255.0, 117 / 255.0);
	glTranslated(0.0, 20.0, 0.0);
	glPushMatrix();

	// draw the blades, covers....
	DrawP1();

	//draw the pillar
	GLUquadricObj* obj = gluNewQuadric();
	glRotated(90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(obj, 1.0, 1.0, 20, 30, 30);
	glPopMatrix();

	glPopMatrix();
}

//This function is used to draw the base of the fan
void Fan::DrawBase()
{
	glPushMatrix();
	glColor3d(66 / 255.0, 134 / 255.0, 117 / 255.0);
	glTranslated(0.0, 0.0, 1.0);
	glPushMatrix();
	GLUquadricObj* obj = gluNewQuadric();
	glRotated(90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(obj, R, R, 1, 30, 30);
	glPopMatrix();

	//draw the bottom surface of the base
	glPushMatrix();
	glBegin(GL_POLYGON);
	for (int i = 360; i > 0; i--)
	{
		glVertex3d(R * cos(i / 360.0 * 2 * Pi), 0, R * sin(i / 360.0 * 2 * Pi));
	}
	glEnd();
	glPopMatrix();

	//draw the bottom surface of the base
	glPushMatrix();
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		glVertex3d(R * cos(i / 360.0 * 2 * Pi), -1, R * sin(i / 360.0 * 2 * Pi));
	}
	glEnd();
	glPopMatrix();

	glPopMatrix();
}


//draw the head of the fan
void Fan::DrawP1()
{
	glPushMatrix();

	glPushMatrix();
	glTranslated(0.0, 0.0, -4.0);
	GLUquadricObj* obj = gluNewQuadric();
	gluCylinder(obj, 2.0, 2.0, 8.0, 30, 30);
	glPopMatrix();

	//draw the cover
	glPushMatrix();
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		glVertex3d(R3 * cos(i / 360.0 * 2 * Pi), R3 * sin(i / 360.0 * 2 * Pi), 4);
	}
	glEnd();
	glPopMatrix();

	//draw the cover lines
	for (int i = 0; i < 36; i++)
	{
		glPushMatrix();
		glRotated(i * 10.0, 0.0, 0.0, 1.0);
		DrawP3();
		glPopMatrix();
	}

	glPushMatrix();
	glTranslated(0.0, 0.0, 3.5);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; i++)
	{
		glVertex3d(R5 * cos(i / 360.0 * 2 * Pi), R5 * sin(i / 360.0 * 2 * Pi), 4);
	}
	glEnd();
	glPopMatrix();


	//draw the blades and rotation unit
	glPushMatrix();
	DrawP2();
	glPopMatrix();

	//draw the unit
	glPushMatrix();
	glTranslated(0.0, 0.0, -4.0);
	glutSolidSphere(2.0, 30, 30);
	glPopMatrix();

	glPopMatrix();
}


//this function is used to draw the swivel and blades
void Fan::DrawP2()
{
	glPushMatrix();


	//draw the swivel
	glPushMatrix();
	glTranslated(0.0, 0.0, 4.0);
	GLUquadricObj* obj = gluNewQuadric();
	gluCylinder(obj, 0.5, 0.5, 3.0, 30, 30);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.0, 0.0, 7.0);
	glPushMatrix();
	GLUquadricObj* obj1 = gluNewQuadric();
	gluCylinder(obj1, 1.0, 1.0, 0.5, 30, 30);
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		glVertex3d(R2 * cos(i / 360.0 * 2 * Pi), R2 * sin(i / 360.0 * 2 * Pi), 0.5);
	}
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_POLYGON);
	for (int i = 360; i > 0; i--)
	{
		glVertex3d(R2 * cos(i / 360.0 * 2 * Pi), R2 * sin(i / 360.0 * 2 * Pi), 0);
	}
	glEnd();
	glPopMatrix();

	//draw the blades
	glPushMatrix();
	glRotated(-animateRotation, 0.0, 0.0, 1.0);
	for (int i = 0; i < 5; i++)
	{
		glPushMatrix();
		glRotated(i * 72.0, 0.0, 0.0, 1.0);
		glTranslated(-0.5, 0.0, 0.5);
		DrawFanBlade();
		glPopMatrix();
	}

	glPopMatrix();


	glPopMatrix();




	glPopMatrix();
}


//this function is used to draw the cover lines
void Fan::DrawP3()
{
	glPushMatrix();


	glPushMatrix();
	glTranslated(0.0, 0.0, -0.5);
	glPushMatrix();
	//glColor3d(1.0, 0.0, 0.0);
	glTranslated(0.0, 0.0, 14);
	glBegin(GL_LINES);
	for (int i = 0; i < 360; i++)
	{

		if (R4 * sin(i / 360.0 * 2 * Pi) >= -6)
		{
			continue;
		}
		glVertex3d(0, R4 * cos(i / 360.0 * 2 * Pi), R4 * sin(i / 360.0 * 2 * Pi));
		glVertex3d(0, R4 * cos((i + 1) / 360.0 * 2 * Pi), R4 * sin((i + 1) / 360.0 * 2 * Pi));
	}
	glEnd();
	glPopMatrix();

	glPushMatrix();
	//glColor3d(1.0, 0.0, 0.0);
	glTranslated(0.0, 0.0, 2);
	glBegin(GL_LINES);
	for (int i = 0; i < 360; i++)
	{

		if (R4 * sin(i / 360.0 * 2 * Pi) <= 6)
		{
			continue;
		}
		glVertex3d(0, R4 * cos(i / 360.0 * 2 * Pi), R4 * sin(i / 360.0 * 2 * Pi));
		glVertex3d(0, R4 * cos((i + 1) / 360.0 * 2 * Pi), R4 * sin((i + 1) / 360.0 * 2 * Pi));
	}
	glEnd();
	glPopMatrix();
	glPopMatrix();


	glPopMatrix();
}

void Fan::DrawFanBlade()
{
	glPushMatrix();


	glPushMatrix();
	glBegin(GL_POLYGON);
	glVertex3d(0.0, 0.0, 0.0);
	glVertex3d(1.0, 0.0, -0.5);
	glVertex3d(1.0, 7.0, -0.5);
	glVertex3d(0.0, 7.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_POLYGON);
	glVertex3d(0.0, 0.0, 0.0);
	glVertex3d(0.0, 7.0, -0.5);
	glVertex3d(1.0, 7.0, -0.5);
	glVertex3d(1.0, 0.0, 0.0);
	glEnd();
	glPopMatrix();



	glPopMatrix();
}
