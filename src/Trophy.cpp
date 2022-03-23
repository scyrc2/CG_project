#include "Trophy.h"

Trophy::Trophy() : animateTime(0.0), animateRotation(0.0)
{
}

void Trophy::Display()
{
	glPushMatrix();
	glTranslated(-40.0, 1.0, 0.0);
	glRotated(45.0, 0.0, 1.0, 0.0);
	DrawTrophy();
	glPopMatrix();

}

void Trophy::Update(const double& deltaTime)
{
	// update the time and rotation steps
	animateTime += static_cast<float>(deltaTime);

	animateRotation = animateTime / 30.0 * 360.0;
}

void Trophy::DrawTrophy()
{
	glPushMatrix();


	//draw the base
	{
		//set the base materials
		GLfloat mat_ambient[] = { 0.247250f, 0.224500f, 0.064500f, 1.000000f };

		GLfloat mat_diffuse[] = { 0.346150f, 0.314300f, 0.090300f, 1.000000f };

		GLfloat mat_specular[] = { 0.797357f, 0.723991f, 0.208006f, 1.000000f };

		GLfloat mat_shinness[] = { 25.797357f };


		glPushAttrib(GL_ALL_ATTRIB_BITS);

		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shinness);

		glColor3d(242 / 255.0, 123 / 255.0, 31 / 255.0);

		glPushMatrix();
		glTranslated(0.0, -0.5, 0.0);
		glRotated(45.0, 0.0, 1.0, 0.0);
		glScaled(12.0, 1.0, 12.0);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		glTranslated(0.0, 0.5, 0.0);
		glTranslated(0.0, 0.0, 0.0);
		glRotated(45.0, 0.0, 1.0, 0.0);
		glScaled(10.0, 1.0, 10.0);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		GLUquadricObj* obj = gluNewQuadric();
		glRotated(-90.0f, 1.0f, 0.0f, 0.0f);
		gluCylinder(obj, 6.0 * sqrt(2.0), 5.0 * sqrt(2.0), 1, 4, 4);
		glPopMatrix();

		glPopAttrib();
	}

	glPushMatrix();
	glRotated(animateRotation, 0.0, 1.0, 0.0);



	//draw the trophy
	{
		//set the gold material
		GLfloat mat_ambient[] = { 0.247250f, 0.224500f, 0.064500f, 1.000000f };

		GLfloat mat_diffuse[] = { 0.346150f, 0.314300f, 0.090300f, 1.000000f };

		GLfloat mat_specular[] = { 0.797357f, 0.723991f, 0.208006f, 1.000000f };

		GLfloat mat_shinness[] = { 2.797357f };
		//GLfloat mat_shinness[] = { 83.199997f };


		glPushAttrib(GL_ALL_ATTRIB_BITS);

		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shinness);

		glColor3d(242 / 255.0, 123 / 255.0, 31 / 255.0);


		glPushMatrix();
		GLUquadricObj* obj1 = gluNewQuadric();
		glTranslated(0.0, 1.0, 0.0);
		glRotated(-90.0f, 1.0f, 0.0f, 0.0f);
		gluCylinder(obj1, 4.0, 4.0, 0.5, 100, 100);
		glPopMatrix();

		glPushMatrix();
		GLUquadricObj* obj2 = gluNewQuadric();
		glTranslated(0.0, 1.5, 0.0);
		glRotated(-90.0f, 1.0f, 0.0f, 0.0f);
		gluCylinder(obj2, 4.0, 3.5, 0.2, 100, 100);
		glPopMatrix();

		glPushMatrix();
		GLUquadricObj* obj3 = gluNewQuadric();
		glTranslated(0.0, 1.7, 0.0);
		glRotated(-90.0f, 1.0f, 0.0f, 0.0f);
		gluCylinder(obj3, 3.5, 3.5, 0.5, 100, 100);
		glPopMatrix();

		glPushMatrix();
		GLUquadricObj* obj4 = gluNewQuadric();
		glTranslated(0.0, 2.2, 0.0);
		glRotated(-90.0f, 1.0f, 0.0f, 0.0f);
		gluCylinder(obj4, 3.5, 2.0, 0.4, 100, 100);
		glPopMatrix();

		glPushMatrix();
		GLUquadricObj* obj5 = gluNewQuadric();
		glTranslated(0.0, 2.6, 0.0);
		glRotated(-90.0f, 1.0f, 0.0f, 0.0f);
		gluCylinder(obj5, 2.0, 2.0, 0.02, 100, 100);
		glPopMatrix();


		//draw the foot
		glPushMatrix();
		glTranslated(0.0, 2.62, 0.0);
		DrawFoot();
		glPopMatrix();

		//draw the cup
		glPushMatrix();
		glTranslated(0.0, 5.32, 0.0);
		glScaled(2.0, 2.0, 2.0);
		DrawFace();
		glPopMatrix();
		DrawEars();
		glPopMatrix();

		glPopAttrib();
	}

	glPopMatrix();

}

void Trophy::DrawFoot()
{
	glPushMatrix();
	glTranslated(0.0, 3.1, 0.0);
	for (int i = 40; i > 10; i--)
	{
		glTranslated(0.0, -0.1, 0.0);
		glPushMatrix();
		DrawCylinder(1 / (i * 0.05), 1 / ((i - 1) * 0.05));
		glPopMatrix();
	}

	glPushMatrix();
	glTranslated(0.0, 3.0, 0.0);
	glRotated(90.0, 1.0, 0.0, 0.0);
	glutSolidTorus(0.1, 0.5, 30, 30);
	glPopMatrix();

	glPopMatrix();
}

void Trophy::DrawFace()
{
	glPushMatrix();

	glRotated(180.0, 0.0, 0.0, 1.0);

	for (int i = 0; i < 40; i++)
	{
		glTranslated(0.0, -0.1, 0.0);
		glPushMatrix();
		DrawCylinder(sqrt((i - 1) * 0.1), sqrt(i * 0.1));
		glPopMatrix();
	}
	glPopMatrix();


	glPushMatrix();
	glPushMatrix();
	glBegin(GL_POLYGON);
	for (int i = 360; i > 0; i--)
	{
		glVertex3d(sqrt(39 * 0.1) * cos(i / 360.0 * 2 * Pi), 4.1, sqrt(39 * 0.1) * sin(i / 360.0 * 2 * Pi));
	}
	glEnd();
	glPopMatrix();

	glPopMatrix();
}

void Trophy::DrawEars()
{
	glPushMatrix();

	glTranslated(5.0, 12.0, 0.0);
	//glScaled(2.0, 2.0, 2.0);

	//DrawCylinder(0.1, 0.1);

	glPushMatrix();
	glRotated(30 * 1.0, 0.0, 0.0, 1.0);
	glTranslated(-1.0, 0.0, 0.0);
	DrawCylinder(0.2, 0.2);

	glPushMatrix();
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		glVertex3d(0.2 * cos(i / 360.0 * 2 * Pi), -0.1, 0.2 * sin(i / 360.0 * 2 * Pi));
	}
	glEnd();

	glPopMatrix();

	glPopMatrix();


	for (int i = -29; i <= 180; i++)
	{
		glPushMatrix();
		glRotated(-i * 1.0, 0.0, 0.0, 1.0);
		glTranslated(-1.0, 0.0, 0.0);
		DrawCylinder(0.2, 0.2);
		glPopMatrix();
	}

	for (int i = 180; i <= 280; i++)
	{
		glPushMatrix();
		glTranslated(-3, 0.0, 0.0);
		glRotated(-i * 1.0, 0.0, 0.0, 1.0);
		glTranslated(-4.0, 0.0, 0.0);
		DrawCylinder(0.2, 0.2);
		glPopMatrix();
	}


	glPopMatrix();


	glPushMatrix();
	glRotated(180.0, 0.0, 1.0, 0.0);
	glTranslated(5.0, 12.0, 0.0);


	glPushMatrix();
	glRotated(30 * 1.0, 0.0, 0.0, 1.0);
	glTranslated(-1.0, 0.0, 0.0);
	DrawCylinder(0.2, 0.2);

	glPushMatrix();
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		glVertex3d(0.2 * cos(i / 360.0 * 2 * Pi), -0.1, 0.2 * sin(i / 360.0 * 2 * Pi));
	}
	glEnd();

	glPopMatrix();

	glPopMatrix();



	for (int i = -30; i <= 180; i++)
	{
		glPushMatrix();
		glRotated(-i * 1.0, 0.0, 0.0, 1.0);
		glTranslated(-1.0, 0.0, 0.0);
		DrawCylinder(0.2, 0.2);
		glPopMatrix();
	}

	for (int i = 180; i <= 280; i++)
	{
		glPushMatrix();
		glTranslated(-3, 0.0, 0.0);
		glRotated(-i * 1.0, 0.0, 0.0, 1.0);
		glTranslated(-4.0, 0.0, 0.0);
		DrawCylinder(0.2, 0.2);
		glPopMatrix();
	}


	glPopMatrix();

}

//helper function to draw cylinders
void Trophy::DrawCylinder(double R1, double R2)
{
	glPushMatrix();
	GLUquadricObj* obj = gluNewQuadric();
	//glTranslated(0.0, 2.2, 0.0);
	glRotated(90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(obj, R1, R2, 0.1, 30, 30);
	glPopMatrix();
}

