#include "Snowman.h"
#include <iostream>
using namespace std;

Snowman::Snowman() :keyframe(-1), keyframe2(-1), keyframe3(-1), animateTime(0.0), animateTime3(0.0), animateRotation(0.0), animateRotation3(0.0), animateScale(0.0), animateTransmission(0.0), keyRotation(0.0), keyScale(1.0f)
{
}

void Snowman::Display()
{

	// Always push before making any changes
	glPushMatrix();
	// Final visulization setting for better performance
	//glTranslatef(-10.0f, 0.0f, 0.0f);


	glPushMatrix();
	glRotatef(180.0, 0.0, 1.0, 0.0);
	glTranslatef(10.0f, 4.0f, -7.0f);
	glScalef(0.5, 0.5, 0.5);
	//draw the snowman model
	DrawSnowman(1);
	glPopMatrix();

	glPushMatrix();
	//glRotatef(180.0, 0.0, 1.0, 0.0);
	glTranslatef(-10.0f, 4.0f, -7.0f);
	glScalef(0.5, 0.5, 0.5);
	//draw the snowman model
	DrawSnowman(2);
	glPopMatrix();

	//judger
	glPushMatrix();
	glTranslated(-20.0, 4.0, 0.0);
	glRotated(90.0, 0.0, 1.0, 0.0);
	glScalef(0.5, 0.5, 0.5);
	DrawSnowman(3);
	glPopMatrix();

	glPushMatrix();
	glTranslated(45.0, 4.0, 0.0);
	glRotated(-90.0, 0.0, 1.0, 0.0);
	glScalef(0.5, 0.5, 0.5);
	DrawSnowman(3);
	glPopMatrix();

	// another player
	glPushMatrix();
	glTranslatef(10.0f, 4.0f, -10.0f);
	glRotated(-90.0, 0.0, 1.0, 0.0);
	glScalef(0.5, 0.5, 0.5);
	DrawSnowman2();
	glPopMatrix();



	// pop matrix stack to revert to state prior to drawing
	glPopMatrix();
}

void Snowman::Update(const double& deltaTime)
{
	// update the time and rotation steps
	animateTime += static_cast<float>(deltaTime);
	animateTime3 += static_cast<float>(deltaTime);
	animateTime4 += static_cast<float>(deltaTime);



	// the movement updation for snowman body
	if (animateTime >= 4.0)
	{
		animateTime = 0.0f;
		keyframe = -1;
		keyRotation = 0.0;
		keyRotation2 = 60.0;
		keyScale = 6.0;
	}


	// from first key position to second
	if (animateTime < 2.0)
	{

		if (keyframe != 1)
		{
			keyframe = 1;
			keyRotation = 0.0;      // rotation value at key position 1
			keyScale = 6.0;         // scale value at key position 1
		}

		//calculate the new movement arguments
		animateRotation = keyRotation + (animateTime / 2.0) * 60.0;
		animateRotation2 = keyRotation2 - (animateTime / 2.0) * 60.0;
		//animateScale = keyScale  - (3.0f ) / (10 / 3.0f) * animateTime;
	}

	else if (animateTime < 4.0)
	{

		if (keyframe != 2)
		{
			keyframe = 2;
			keyRotation = 60.0;     // rotation value at key position 2
			keyRotation2 = 0.0;     // rotation value at key position 2
			keyScale = 3.0;         // scale value at key position 2
		}


		animateRotation = keyRotation - ((animateTime - 2.0) / 2.0) * 60.0;
		animateRotation2 = keyRotation2 + ((animateTime - 2.0) / 2.0) * 60.0;
		//animateScale = keyScale  - (1.0f ) / (10 / 3.0f) * (animateTime - 10.0f / 3);
	}


	//movement for another player in training ground
	if (animateTime3 >= 8.0)
	{
		animateTime3 = 0.0;
		keyframe2 = -1;
		keyRotation3 = 0.0;
		keyRotation4 = 0.0;
	}

	if (animateTime3 < 0.5)
	{
		if (keyframe2 != 0)
		{
			keyframe2 = 0;
			keyRotation3 = 0.0;
			keyRotation4 = 0.0;
		}

		animateRotation3 = keyRotation3 + 10 / 0.5 * animateTime3;
		animateRotation4 = keyRotation4 + 30 / 0.5 * animateTime3;
	}

	else if (animateTime3 < 1.0)
	{
		if (keyframe2 != 1)
		{
			keyframe2 = 1;
			keyRotation3 = 10.0;
			keyRotation4 = 30.0;
		}

		animateRotation3 = keyRotation3 - 10 / 0.5 * (animateTime3 - 0.5);
		animateRotation4 = keyRotation4 + 30 / 0.5 * (animateTime3 - 0.5);
	}

	else if (animateTime3 < 4.0)
	{
		if (keyframe2 != 2)
		{
			keyframe2 = 2;
			keyRotation3 = 0.0;
			keyRotation4 = 60.0;
		}

		animateRotation3 = keyRotation3;
		animateRotation4 = keyRotation4;
	}

	else if (animateTime3 < 6.0)
	{
		if (keyframe2 != 2)
		{
			keyframe2 = 2;
			keyRotation3 = 0.0;
			keyRotation4 = 60.0;
		}

		animateRotation3 = keyRotation3;
		animateRotation4 = keyRotation4 - 60.0 / 2 * (animateTime3 - 4);
	}

	else if (animateTime3 < 7)
	{
		if (keyframe2 != 3)
		{
			keyframe2 = 3;
			keyRotation3 = 0.0;
		}

		animateRotation3 = keyRotation3 - 20.0 / 1.0 * (animateTime3 - 6.0);
		animateRotation4 = 0.0;
	}

	else if (animateTime3 < 8.0)
	{
		if (keyframe2 != 4)
		{
			keyframe2 = 4;
			keyRotation3 = -20.0;
		}

		animateRotation3 = keyRotation3 + 20.0 / 1.0 * (animateTime3 - 7.0);
		animateRotation4 = 0.0;
	}

	if (animateTime4 >= 8.0)
	{
		animateTime4 = 0.0;
		keyframe3 = -1;
		keyTransmission = 0.0;
	}

	if (animateTime4 < 4.0)
	{
		if (keyframe3 != 0)
		{
			keyframe3 = 0;
			keyTransmission = 0.5 * 2 * 4.0 * 4.0;
		}

		animateTransmission = keyTransmission - 0.5 * 2 * (4 - animateTime3) * (4 - animateTime3);
		//cout << animateTime3 << endl;
	}

	else if (animateTime4 < 8.0)
	{
		if (keyframe3 != 1)
		{
			keyframe3 = 1;
			keyTransmission = 0.5 * 2 * 4.0 * 4.0;
		}

		animateTransmission = keyTransmission - 0.5 * 2 * (animateTime3 - 4) * (animateTime3 - 4);
	}



}

void Snowman::DrawSnowman(int id)
{
	// Always push before making any changes
	glPushMatrix();

	//head
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(0.0f, 3.0f, 0.0f);
	glutSolidSphere(1.0f, 30, 30);
	glPushMatrix();
	glColor4f(0.0f, 0.0f, 0.0f, 0.8f);
	glRotatef(-20.0f, 1.0f, 0.0f, 0.0f);
	glPushMatrix();
	glRotatef(-20.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, 1.0f);
	glutSolidSphere(0.2f, 30, 30);    //eye
	glPopMatrix();
	glPushMatrix();
	glRotatef(20.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, 1.0f);
	glutSolidSphere(0.2f, 30, 30);    //eye
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	/*****************************************/

	if (id == 1 || id == 2)
	{
		// animation body
		glPushMatrix();

		if (id == 1)
		{
			glRotated(animateRotation, 0.0, 1.0, 0.0);
		}
		else
		{
			glRotated(animateRotation2, 0.0, 1.0, 0.0);
		}

		//middle sphere
		glPushMatrix();
		glColor3f(1.0f, 1.0f, 1.0f);
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
		glutSolidSphere(2.0f, 30, 30);
		glPopMatrix();

		//left armx
		glPushMatrix();
		if (id == 1)
		{
			glColor3f(1.0f, 1.0f, 1.0f);
		}
		else if (id == 2)
		{
			glColor3f(1.0f, 0.0f, 0.0f);
		}
		glPushMatrix();
		//glColor3f(1.0f, 1.0f, 1.0f);
		glRotatef(-30.0f, 0.0f, 0.0f, 1.0f);
		glTranslatef(2.25f, 0.0f, 0.0f);
		DrawArm();
		glPopMatrix();
		glPopMatrix();

		//right arm
		glPushMatrix();
		//glColor3f(1.0f, 1.0f, 1.0f);
		glRotatef(170.0f, 0.0f, 0.0f, 1.0f);
		glTranslatef(2.25f, 0.0f, 0.0f);
		DrawArm();


		glPushMatrix();
		glTranslated(2.3, 0.0, 0.0);
		glRotated(10, 1.0, 1.0, 0.0);
		glPushMatrix();
		glRotated(-100, 0.0, 0.0, 1.0);
		DrawBat();
		glPopMatrix();
		glPopMatrix();

		glPopMatrix();




		glPopMatrix();
		/***********************************************/


		//down sphere
		glPushMatrix();
		glColor3f(1.0f, 1.0f, 1.0f);
		glTranslatef(0.0f, -5.0f, 0.0f);
		glPushMatrix();
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
		glutSolidSphere(3.0f, 30, 30);
		glPopMatrix();
		glPopMatrix();
	}
	else
	{
		//middle sphere
		glPushMatrix();
		glColor3f(1.0f, 1.0f, 1.0f);
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
		glutSolidSphere(2.0f, 30, 30);
		glPopMatrix();

		//left armx
		glPushMatrix();
		glPushMatrix();
		glColor3f(0.0f, 0.0f, 1.0f);
		glRotatef(-30.0f, 0.0f, 0.0f, 1.0f);
		glTranslatef(2.25f, 0.0f, 0.0f);
		DrawArm();
		glPopMatrix();
		glPopMatrix();

		//right arm
		glPushMatrix();
		glColor3f(0.0f, 0.0f, 1.0f);
		glRotatef(-150.0f, 0.0f, 0.0f, 1.0f);
		glTranslatef(2.25f, 0.0f, 0.0f);
		DrawArm();
		glPopMatrix();




		/***********************************************/


		//down sphere
		glPushMatrix();
		glColor3f(1.0f, 1.0f, 1.0f);
		glTranslatef(0.0f, -5.0f, 0.0f);
		glPushMatrix();
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
		glutSolidSphere(3.0f, 30, 30);
		glPopMatrix();
		glPopMatrix();
	}


	// pop matrix stack to revert to state prior to drawing
	glPopMatrix();
}

void Snowman::DrawSnowman2()
{
	glPushMatrix();

	//head
	glPushMatrix();
	//glRotated(-animateRotation4, 1.0, 0.0, 0.0);
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(0.0f, 3.0f, 0.0f);

	//glPushMatrix();
	glRotated(-animateRotation4, 1.0, 0.0, 0.0);
	glutSolidSphere(1.0f, 30, 30);
	//glPopMatrix();
	glPushMatrix();
	glColor4f(0.0f, 0.0f, 0.0f, 0.8f);
	glRotatef(-20.0f, 1.0f, 0.0f, 0.0f);
	glPushMatrix();
	glRotatef(-20.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, 1.0f);
	glutSolidSphere(0.2f, 30, 30);    //eye
	glPopMatrix();
	glPushMatrix();
	glRotatef(20.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, 1.0f);
	glutSolidSphere(0.2f, 30, 30);    //eye
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	//middle sphere
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glutSolidSphere(2.0f, 30, 30);
	glPopMatrix();

	//left armx
	glPushMatrix();
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 1.0f);
	glRotatef(-30.0f, 0.0f, 0.0f, 1.0f);
	glTranslatef(2.25f, 0.0f, 0.0f);
	DrawArm();
	glPopMatrix();
	glPopMatrix();

	//right arm

	glPushMatrix();
	glRotated(-animateRotation3, 1.0, 0.0, 0.0);
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 1.0f);
	glRotated(90, 0.0, 1.0, 0.0);
	glRotatef(-180.0f, 0.0f, 0.0f, 1.0f);
	glTranslatef(2.25f, 0.0f, 0.0f);
	DrawArm();

	glPushMatrix();
	glTranslated(2.3, 0.0, 0.0);
	//glRotated(10, 1.0, 1.0, 0.0);
	glPushMatrix();
	glRotated(-90, 0.0, 0.0, 1.0);
	glRotated(90, 0.0, 1.0, 0.0);
	DrawBat();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.0, animateTransmission, 5.5);
	DrawBall();
	glPopMatrix();

	//down sphere
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(0.0f, -5.0f, 0.0f);
	glPushMatrix();
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glutSolidSphere(3.0f, 30, 30);
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
}

void Snowman::DrawArm()
{
	glPushMatrix();

	glTranslatef(1.2f, 0.0f, 0.0f);


	glPushMatrix();
	glTranslatef(0.65f, 0.0f, 0.0f);
	glutSolidCube(0.8f);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-1.0, 0.0, 0.0);
	glScaled(6.0, 1.0, 1.0);
	glutSolidCube(0.5);
	glPopMatrix();


	glPopMatrix();
}

void Snowman::DrawBat()
{
	glPushMatrix();


	glPushMatrix();
	glColor3d(214 / 255.0, 160 / 255.0, 29 / 255.0);
	glScaled(0.2, 0.8, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();


	glPushMatrix();
	glTranslated(0.0, 0.60 + 0.6 * cos(360.0 / 8), 0.05);
	glColor3d(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3d(0.6 * cos(22.5), 0.6 * sin(22.5), 0.0);
	glVertex3d(0.6 * sin(22.5), 0.6 * cos(22.5), 0.0);
	glVertex3d(-0.6 * sin(22.5), 0.6 * cos(22.5), 0.0);
	glVertex3d(-0.6 * cos(22.5), 0.6 * sin(22.5), 0.0);
	glVertex3d(-0.6 * cos(22.5), -0.6 * sin(22.5), 0.0);
	glVertex3d(-0.6 * sin(22.5), -0.6 * cos(22.5), 0.0);
	glVertex3d(0.6 * sin(22.5), -0.6 * cos(22.5), 0.0);
	glVertex3d(0.6 * cos(22.5), -0.6 * sin(22.5), 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.0, 0.6 + 0.6 * cos(360.0 / 8), -0.05);
	glColor3d(0.0, 0.0, 0.0);
	glRotated(180.0, 0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3d(0.6 * cos(22.5), 0.6 * sin(22.5), 0.0);
	glVertex3d(0.6 * sin(22.5), 0.6 * cos(22.5), 0.0);
	glVertex3d(-0.6 * sin(22.5), 0.6 * cos(22.5), 0.0);
	glVertex3d(-0.6 * cos(22.5), 0.6 * sin(22.5), 0.0);
	glVertex3d(-0.6 * cos(22.5), -0.6 * sin(22.5), 0.0);
	glVertex3d(-0.6 * sin(22.5), -0.6 * cos(22.5), 0.0);
	glVertex3d(0.6 * sin(22.5), -0.6 * cos(22.5), 0.0);
	glVertex3d(0.6 * cos(22.5), -0.6 * sin(22.5), 0.0);
	glEnd();
		

	glPushMatrix();
	glColor3d(214 / 255.0, 160 / 255.0, 29 / 255.0);
	glPushMatrix();
	//glColor3d(0.0, 0.0, 1.0);
	glRotated(180.0, 0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3d(0.6 * cos(22.5), 0.6 * sin(22.5), 0.1);
	glVertex3d(0.6 * cos(22.5), 0.6 * sin(22.5), 0.0);
	glVertex3d(0.6 * sin(22.5), 0.6 * cos(22.5), 0.0);
	glVertex3d(0.6 * sin(22.5), 0.6 * cos(22.5), 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(0.6 * sin(22.5), 0.6 * cos(22.5), 0.1);
	glVertex3d(0.6 * sin(22.5), 0.6 * cos(22.5), 0.0);
	glVertex3d(0.6 * sin(22.5), 0.6 * cos(22.5), 0.0);
	glVertex3d(0.6 * sin(22.5), 0.6 * cos(22.5), 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(0.6 * sin(22.5), 0.6 * cos(22.5), 0.1);
	glVertex3d(0.6 * sin(22.5), 0.6 * cos(22.5), 0.0);
	glVertex3d(-0.6 * sin(22.5), 0.6 * cos(22.5), 0.0);
	glVertex3d(-0.6 * sin(22.5), 0.6 * cos(22.5), 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(-0.6 * sin(22.5), 0.6 * cos(22.5), 0.1);
	glVertex3d(-0.6 * sin(22.5), 0.6 * cos(22.5), 0.0);
	glVertex3d(-0.6 * sin(22.5), 0.6 * cos(22.5), 0.0);
	glVertex3d(-0.6 * sin(22.5), 0.6 * cos(22.5), 0.1);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex3d(-0.6 * sin(22.5), 0.6 * cos(22.5), 0.1);
	glVertex3d(-0.6 * sin(22.5), 0.6 * cos(22.5), 0.0);
	glVertex3d(-0.6 * cos(22.5), 0.6 * sin(22.5), 0.0);
	glVertex3d(-0.6 * cos(22.5), 0.6 * sin(22.5), 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(-0.6 * cos(22.5), 0.6 * sin(22.5), 0.1);
	glVertex3d(-0.6 * cos(22.5), 0.6 * sin(22.5), 0.0);
	glVertex3d(-0.6 * cos(22.5), -0.6 * sin(22.5), 0.0);
	glVertex3d(-0.6 * cos(22.5), -0.6 * sin(22.5), 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(-0.6 * cos(22.5), -0.6 * sin(22.5), 0.1);
	glVertex3d(-0.6 * cos(22.5), -0.6 * sin(22.5), 0.0);
	glVertex3d(-0.6 * sin(22.5), -0.6 * cos(22.5), 0.0);
	glVertex3d(-0.6 * sin(22.5), -0.6 * cos(22.5), 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(-0.6 * sin(22.5), -0.6 * cos(22.5), 0.1);
	glVertex3d(-0.6 * sin(22.5), -0.6 * cos(22.5), 0.0);
	glVertex3d(0.6 * sin(22.5), -0.6 * cos(22.5), 0.0);
	glVertex3d(0.6 * sin(22.5), -0.6 * cos(22.5), 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(0.6 * sin(22.5), -0.6 * cos(22.5), 0.1);
	glVertex3d(0.6 * sin(22.5), -0.6 * cos(22.5), 0.0);
	glVertex3d(0.6 * cos(22.5), -0.6 * sin(22.5), 0.0);
	glVertex3d(0.6 * cos(22.5), -0.6 * sin(22.5), 0.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(0.6 * cos(22.5), -0.6 * sin(22.5), 0.1);
	glVertex3d(0.6 * cos(22.5), -0.6 * sin(22.5), 0.0);
	glVertex3d(0.6 * cos(22.5), 0.6 * sin(22.5), 0.0);
	glVertex3d(0.6 * cos(22.5), 0.6 * sin(22.5), 0.1);
	glEnd();
	
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
}

void Snowman::DrawBall()
{
	glPushMatrix();
	glColor3d(254 / 255.0, 186 / 255.0, 7 / 255.0);
	glutSolidSphere(0.1, 30, 30);
	glPopMatrix();
}
