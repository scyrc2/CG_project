#include "Table.h"

Table::Table()
{
}

Table::~Table()
{
}

//draw the table, net, floors
void Table::Display()
{
	glPushMatrix();

	glPushMatrix();
	glTranslatef(-10.0f, 3.05f, 0.0f);
	DrawTable();
	DrawNet();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(10.0f, 3.05f, 0.0f);
	DrawTable();
	DrawNet();
	glPopMatrix();

	glPushMatrix();
	glColor3d(130 / 255.0, 17 / 255.0, 31 / 255.0);
	glScalef(100.0f, 0.1f, 100.0f);
	glutSolidCube(1.0f);
	glPopMatrix();

	glPopMatrix();
}

void Table::DrawTable()
{
	glPushMatrix();

	//button face
	glPushMatrix();
	glColor3d(21 / 255.0, 85 / 255.0, 157 / 255.0);
	glTranslatef(0.0f, 0.0f, 2.6f);
	glScalef(6.0f, 0.3f, 4.8f);
	glutSolidCube(1.0f);
	glPopMatrix();

	glPushMatrix();
	glColor3d(21 / 255.0, 85 / 255.0, 157 / 255.0);
	glTranslatef(0.0f, 0.0f, -2.6f);
	glScalef(6.0f, 0.3f, 4.8f);
	glutSolidCube(1.0f);
	glPopMatrix();

	//up face
	glPushMatrix();
	glColor3d(21 / 255.0, 85 / 255.0, 157 / 255.0);
	//glColor3f(1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, 0.2f, 0.0f);
	glScalef(6.0f, 0.1f, 10.0f);
	glutSolidCube(1.0f);
	glPopMatrix();

	//side lines 
	glPushMatrix();
	glTranslatef(0.0f, -0.05f, 0.0f);
	glScalef(1.01f, 1.01f, 1.01f);
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(-2.95f, 0.25f, 0.0f);
	glScalef(0.1f, 0.1f, 10.0f);
	glutSolidCube(1.0f);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(0.0f, 0.25f, 0.0f);
	glScalef(0.1f, 0.1f, 10.0f);
	glutSolidCube(1.0f);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(2.95f, 0.25f, 0.0f);
	glScalef(0.1f, 0.1f, 10.0f);
	glutSolidCube(1.0f);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(0.0f, 0.25f, 0.0f);
	glScalef(0.1f, 0.1f, 6.0f);
	glutSolidCube(1.0f);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -5.0f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(0.0f, 0.25f, 0.0f);
	glScalef(0.1f, 0.1f, 6.0f);
	glutSolidCube(1.0f);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 5.0f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(0.0f, 0.25f, 0.0f);
	glScalef(0.1f, 0.1f, 6.0f);
	glutSolidCube(1.0f);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();



	// legs
	glPushMatrix();
	glColor3d(205 / 255.0, 209 / 255.0, 211 / 255.0);
	glPushMatrix();
	glTranslatef(2.5f, -1.5f, 4.0f);
	glScalef(0.2f, 3.0f, 0.2f);
	glutSolidCube(1.0f);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(2.5f, -1.5f, -4.0f);
	glScalef(0.2f, 3.0f, 0.2f);
	glutSolidCube(1.0f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.5f, -1.5f, -4.0f);
	glScalef(0.2f, 3.0f, 0.2f);
	glutSolidCube(1.0f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.5f, -1.5f, 4.0f);
	glScalef(0.2f, 3.0f, 0.2f);
	glutSolidCube(1.0f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.5f, -1.5f, 1.0f);
	glScalef(0.2f, 3.0f, 0.2f);
	glutSolidCube(1.0f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.5f, -1.5f, -1.0f);
	glScalef(0.2f, 3.0f, 0.2f);
	glutSolidCube(1.0f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.5f, -1.5f, -1.0f);
	glScalef(0.2f, 3.0f, 0.2f);
	glutSolidCube(1.0f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.5f, -1.5f, 1.0f);
	glScalef(0.2f, 3.0f, 0.2f);
	glutSolidCube(1.0f);
	glPopMatrix();

	glPopMatrix();


	// whiffletree
	glPushMatrix();
	glColor3d(242 / 255.0, 206 / 255.0, 43 / 255.0);

	glPushMatrix();
	glTranslatef(-2.3f, -1.0f, 2.5f);
	glScalef(0.2f, 0.2f, 3.0f);
	glutSolidCube(1.0f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.3f, -1.0f, 2.5f);
	glScalef(0.2f, 0.2f, 3.0f);
	glutSolidCube(1.0f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.3f, -1.0f, -2.5f);
	glScalef(0.2f, 0.2f, 3.0f);
	glutSolidCube(1.0f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.3f, -1.0f, -2.5f);
	glScalef(0.2f, 0.2f, 3.0f);
	glutSolidCube(1.0f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, -1.5f, 4.0f);
	glScalef(5.0f, 0.2f, 0.2f);
	glutSolidCube(1.0f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, -1.5f, -4.0f);
	glScalef(5.0f, 0.2f, 0.2f);
	glutSolidCube(1.0f);
	glPopMatrix();
	glPopMatrix();

	//slash
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);
	glPushMatrix();
	glTranslatef(2.3f, -0.5f, 3.5f);
	glRotatef(45.0f, 1.0f, 0.0f, 0.0f);
	glScalef(0.2f, 0.2f, 1.5f);
	glutSolidCube(1.0f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.3f, -0.5f, 3.5f);
	glRotatef(45.0f, 1.0f, 0.0f, 0.0f);
	glScalef(0.2f, 0.2f, 1.5f);
	glutSolidCube(1.0f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.3f, -0.5f, -3.5f);
	glRotatef(-45.0f, 1.0f, 0.0f, 0.0f);
	glScalef(0.2f, 0.2f, 1.5f);
	glutSolidCube(1.0f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.3f, -0.5f, -3.5f);
	glRotatef(-45.0f, 1.0f, 0.0f, 0.0f);
	glScalef(0.2f, 0.2f, 1.5f);
	glutSolidCube(1.0f);
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
}

void Table::DrawNet()
{
	glPushMatrix();

	glPushMatrix();
	glTranslated(2.75, -0.15, -0.1);
	DrawNetUnit();
	glPopMatrix();

	glPushMatrix();
	glPushMatrix();
	glTranslated(-2.75, -0.15, 0.1);
	glRotatef(180.0, 0.0, 1.0, 0.0);
	DrawNetUnit();
	glPopMatrix();
	glPopMatrix();

	//net
	glPushMatrix();
	glColor3d(1.0, 1.0, 1.0);
	glTranslatef(0.0f, 0.35f, 0.0f);
	for (int i = 0; i < 10; i++)
	{
		glBegin(GL_LINE_LOOP);
		glVertex3d(-4.2, i / 10.0 * 0.5, 0.0);
		glVertex3d(4.2, i / 10.0 * 0.5, 0.0);
		glVertex3d(4.2, (i + 1) / 10.0 * 0.5, 0.0);
		glVertex3d(-4.2, (i + 1) / 10.0 * 0.5, 0.0);
		glEnd();
	}
	for (int i = 0; i < 49; i++)
	{
		glBegin(GL_LINE_LOOP);
		glVertex3d(i / 50.0 * 4.2, 0.0, 0.0);
		glVertex3d((i + 1) / 50.0 * 4.2, 0.0, 0.0);
		glVertex3d((i + 1) / 50.0 * 4.2, 0.5, 0.0);
		glVertex3d(i / 50.0 * 4.2, 0.5, 0.0);
		glEnd();
	}

	for (int i = 0; i < 49; i++)
	{
		glBegin(GL_LINE_LOOP);
		glVertex3d(-i / 50.0 * 4.2, 0.0, 0.0);
		glVertex3d(-(i + 1) / 50.0 * 4.2, 0.0, 0.0);
		glVertex3d(-(i + 1) / 50.0 * 4.2, 0.5, 0.0);
		glVertex3d(-i / 50.0 * 4.2, 0.5, 0.0);
		glEnd();
	}
	glPopMatrix();

	glPushMatrix();
	glColor3d(19 / 255.0, 72 / 255.0, 87 / 255.0);
	glTranslatef(0.0f, 0.85f, 0.0f);
	glScalef(8.5f, 0.1f, 0.1f);
	glutSolidCube(1.0f);
	glPopMatrix();

	glPopMatrix();
}

void Table::DrawNetUnit()
{
	glPushMatrix();
	glScalef(0.05f, 0.05f, 0.05f);
	glColor3d(19 / 255.0, 72 / 255.0, 87 / 255.0);

	//bottom bar
	glPushMatrix();
	glScalef(20.0f, 2.0f, 4.0f);
	glTranslatef(0.5f, 0.5f, 0.5f);
	glutSolidCube(1.0f);
	glPopMatrix();

	//middle bar
	glPushMatrix();
	glTranslatef(5.0f, 2.0f, 0.0f);
	glPushMatrix();
	glScalef(15.0f, 6.0f, 4.0f);
	glTranslatef(0.5f, 0.5f, 0.5f);
	glutSolidCube(1.0f);
	glPopMatrix();
	glPopMatrix();

	//up bar
	glPushMatrix();
	glTranslatef(0.0f, 8.0f, 0.0f);
	glPushMatrix();
	glScalef(30.0f, 2.0f, 4.0f);
	glTranslatef(0.5f, 0.5f, 0.5f);
	glutSolidCube(1.0f);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(29.0f, 10.0f, 2.0f);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	GLUquadricObj* cylinder = gluNewQuadric();
	gluCylinder(cylinder, 1.0, 1.0, 10.0, 100, 100);
	glPopMatrix();


	glPopMatrix();
}

