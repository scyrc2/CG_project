#include "SnowmanWatcher.h"

SnowmanWatcher::SnowmanWatcher():keyframe(-1), keyframe2(-1), animateTime(0.0), animateTime2(0.0), animateRotation(0.0), animateRotation2(0.0), animateTransmission(0.0)
{
}

void SnowmanWatcher::Display()
{
	glPushMatrix();

	// red group
	glPushMatrix();
	glTranslated(-10.0, 4.0, -28.0);
	//glRotated(90.0, 0.0, 1.0, 0.0);
	glScalef(0.5, 0.5, 0.5);
	DrawSnowman(2);
	glPopMatrix();


	glPushMatrix();
	glTranslated(-6.0, 4.0, -28.0);
	//glRotated(90.0, 0.0, 1.0, 0.0);
	glScalef(0.5, 0.5, 0.5);
	DrawSnowman(2);
	glPopMatrix();


	//blue group
	glPushMatrix();
	glTranslated(-10.0, 4.0, 28.0);
	glRotated(180.0, 0.0, 1.0, 0.0);
	glScalef(0.5, 0.5, 0.5);
	DrawSnowman(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-14.0, 4.0, 28.0);
	glRotated(180.0, 0.0, 1.0, 0.0);
	glScalef(0.5, 0.5, 0.5);
	DrawSnowman(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-6.0, 4.0, 28.0);
	glRotated(180.0, 0.0, 1.0, 0.0);
	glScalef(0.5, 0.5, 0.5);
	DrawSnowman(1);
	glPopMatrix();

	// another
	glPushMatrix();
	glTranslated(-28.0, 4.0, -15.0);
	glRotated(60.0, 0.0, 1.0, 0.0);
	glScalef(0.5, 0.5, 0.5);
	DrawSnowman2(2);
	glPopMatrix();

	glPopMatrix();
}

void SnowmanWatcher::Update(const double& deltaTime)
{
	// update the time and rotation steps
	animateTime += static_cast<float>(deltaTime);
	animateTime2 += static_cast<float>(deltaTime);
	animateRotation += static_cast<float>(deltaTime);


	//snowmen clapping
	if (animateTime >= 1.0)
	{
		animateTime = 0.0f;
		keyframe = -1;
		keyRotation = 30.0;
		//keyTransmission = 0.0;
	}

	if (animateTime < 0.5)
	{
		if (keyframe != 0)
		{
			keyframe = 0;
			keyRotation = 30.0;
		}

		animateRotation = keyRotation + (animateTime / 0.5) * 60;
	}

	else if (animateTime < 1.0)
	{
		if (keyframe != 1)
		{
			keyframe = 1;
			keyRotation = 90.0;
		}

		animateRotation = keyRotation - (animateTime - 0.5) / 0.5 * 60.0;
	}

	//snowman jumping and waving
	if (animateTime2 >= 0.8)
	{
		keyframe2 = -1;
		animateTime2 = 0.0;
		keyTransmission = 0.0;
		keyRotation2 = -10.0;
	}

	if (animateTime2 < 0.4)
	{
		if (keyframe2 != 0)
		{
			keyframe2 = 0;
			keyTransmission = 0.0;
			keyRotation2 = -10.0;
		}

		animateTransmission = keyTransmission + 0.5 * 9.8 * (-animateTime2) * (-animateTime2);
		animateRotation2 = keyRotation2 + 40.0 * (animateTime2 / 0.4);
	}

	else if (animateTime2 < 0.8)
	{
		if (keyframe2 != 1)
		{
			keyframe2 = 1;
			keyTransmission = 0.5 * 9.8 * 0.4 * 0.4;
			keyRotation2 = 30.0;
		}

		animateTransmission = keyTransmission - 0.5 * 9.8 * (-animateTime2 + 0.4) * (-animateTime2 + 0.4);
		animateRotation2 = keyRotation2 - 40.0 * ((animateTime2 - 0.4) / 0.4);
	}

}

void SnowmanWatcher::DrawSnowman(int id)
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
		//middle sphere
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glutSolidSphere(2.0f, 30, 30);
	glPopMatrix();

	//left armx
	glPushMatrix();
	glRotated(-animateRotation, 0.0, 1.0, 0.0);
	glPushMatrix();
	//glColor3f(1.0f, 0.0f, 0.0f);
	glRotatef(10.0f, 0.0f, 0.0f, 1.0f);
	glTranslatef(2.25f, 0.0f, 0.0f);
	DrawArm(id);
	glPopMatrix();
	glPopMatrix();

	//right arm
	glPushMatrix();
	glRotated(animateRotation, 0.0, 1.0, 0.0);
	glPushMatrix();
	//glColor3f(1.0f, 0.0f, 0.0f);
	glRotatef(170.0f, 0.0f, 0.0f, 1.0f);
	glTranslatef(2.25f, 0.0f, 0.0f);
	DrawArm(id);
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


	// pop matrix stack to revert to state prior to drawing
	glPopMatrix();
}

void SnowmanWatcher::DrawSnowman2(int id)
{
	// Always push before making any changes
	glPushMatrix();
	glTranslated(0.0, animateTransmission, 0.0);

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
		//middle sphere
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glutSolidSphere(2.0f, 30, 30);
	glPopMatrix();

	//left armx
	glPushMatrix();
	glRotated(-animateRotation2, 0.0, 0.0, 1.0);
	glPushMatrix();
	//glColor3f(1.0f, 0.0f, 0.0f);
	glRotatef(10.0f, 0.0f, 0.0f, 1.0f);
	glTranslatef(2.25f, 0.0f, 0.0f);
	DrawArm(id);
	glPopMatrix();
	glPopMatrix();

	//right arm
	glPushMatrix();
	glRotated(animateRotation2, 0.0, 0.0, 1.0);
	glPushMatrix();
	//glColor3f(1.0f, 0.0f, 0.0f);
	glRotatef(170.0f, 0.0f, 0.0f, 1.0f);
	glTranslatef(2.25f, 0.0f, 0.0f);
	DrawArm(id);
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



	glPopMatrix();


	// pop matrix stack to revert to state prior to drawing
	glPopMatrix();
}

void SnowmanWatcher::DrawArm(int id)
{
	glPushMatrix();

	glTranslatef(1.2f, 0.0f, 0.0f);

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
	glTranslatef(0.65f, 0.0f, 0.0f);
	glutSolidCube(0.8f);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-1.0, 0.0, 0.0);
	glScaled(6.0, 1.0, 1.0);
	glutSolidCube(0.5);
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();
}
