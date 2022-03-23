#include "Sofa.h"

Sofa::Sofa()
{
}

void Sofa::Display()
{

	{	
		//set the light attibutes
		GLfloat light_position[] = { 5.0f, 10.0f, -45.0f, 1.0f };
		GLfloat light_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
		GLfloat light_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
		GLfloat light_specular[] = { 0.2f, 0.2f, 0.2f, 1.0f };
		glLightfv(GL_LIGHT1, GL_POSITION, light_position);
		glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
		glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);


		//enable the light 1
		glEnable(GL_LIGHT1);
		glEnable(GL_LIGHTING);
	}

	//close the light 0 source
	glDisable(GL_LIGHT0);



	glPushMatrix();
	glTranslated(0.0, 0.5, -45.0);
	glPushMatrix();
	glTranslated(0.0, 0.0, 0.0);
	DrawSofa();
	glPopMatrix();

	glPushMatrix();
	glTranslated(10.0, 0.0, 0.0);
	DrawSofa();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-10.0, 0.0, 0.0);
	DrawSofa();
	glPopMatrix();
	glPopMatrix();



	glPushMatrix();
	glTranslated(0.0, 1.0, -45.0);
	DrawLamp();
	glPopMatrix();


	glDisable(GL_LIGHT1);
	glEnable(GL_LIGHT0);
}

void Sofa::Update(const double& deltaTime)
{
}

void Sofa::DrawSofa()
{
	glPushMatrix();
	glColor3d(222 / 255.0f, 158 / 255.0f, 68 / 255.0f);
	glPushMatrix();
	glScaled(8.0, 1.0, 4.0);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-3.5, 1.0, -0.5);
	glScaled(1.0, 1.0, 3.0);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(3.5, 1.0, -0.5);
	glScaled(1.0, 1.0, 3.0);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.0, 2.0, -1.5);
	glScaled(6.0, 3.0, 1.0);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(3.5, 1.0, 1.5);
	glScaled(0.4, 0.4, 0.4);
	glutSolidDodecahedron();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-3.5, 1.0, 1.5);
	glScaled(0.4, 0.4, 0.4);
	glutSolidDodecahedron();
	glPopMatrix();

	glPopMatrix();
}

void Sofa::DrawLamp()
{
	glPushMatrix();
	glColor3d(80 / 255.0f, 62 / 255.0f, 42 / 255.0f);

	glPushMatrix();
	glTranslated(5.0, 10.0, 0.0);
	glPushMatrix();
	glTranslated(0.0, -0.2, 0.0);
	glutSolidSphere(0.1, 30, 30);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.0, 0.2, 0.0);
	glutSolidSphere(0.2, 30, 30);
	glPopMatrix();


	//repeat the cubes to draw the funnel
	for (int i = 0; i < 360; i++)
	{

		glPushMatrix();
		glRotated(i, 0.0, 1.0, 0.0);
		glPushMatrix();
		glRotated(60.0, 1.0, 0.0, 0.0);
		glTranslated(0.0, -0.6, 0.0);
		glScaled(0.1, 1.0, 0.1);
		glutSolidCube(1.0);
		glPopMatrix();
		glPopMatrix();
	}
	
	glPushMatrix();
	glBegin(GL_LINES);
	glVertex3d(0.0, 0.0, 0.0);
	glVertex3d(0.0, 1.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.0, 1, -2.0);
	glScaled(0.1, 0.1, 4.0);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.0, -5.0, -3.5);
	glScaled(0.1, 12.0, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.0, -10.95, -3.5);
	glScaled(3.0, 0.2, 3.0);
	glutSolidCube(1.0);
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();
}
