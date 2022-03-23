#include "TexturedBall.h"
#include "VectorMath.h"
#include <time.h> 
#include <cmath>
TexturedBall::TexturedBall() : _xrot(100.0f), _yrot(10.0f), texID(NULL), _flagWireFrame(false), _flagAnimation(true),
								keyframe(-1), keyTransmissionX(0.0), keyTransmissionY(0.0), keyTransmissionZ(0.0),
								animateTransmissionX(0.0), animateTransmissionY(0.0), animateTransmissionZ(0.0)
{
	// Octahedron vertices (used for initial triangle faces)
	static float vertices[] =
	{
		1.0f, 0.0f, 0.0f,   // VERTEX 0
		0.0f, 0.0f, -1.0f,  // VERTEX 1
		-1.0f, 0.0f, 0.0f,  // VERTEX 2
		0.0f, 0.0f, 1.0f,   // VERTEX 3
		0.0f, 1.0f, 0.0f,   // VERTEX 4
		0.0f, -1.0f, 0.0f   // VERTEX 5
	};
	// Globalise vertices
	_initV = vertices;

	srand(0);


	for (int i = 0; i < 25; i++)
	{
		ballsPositionX[i] = rand() % 1000 / 1000.0 * 25.0;
		ballsPositionZ[i] = rand() % 1000 / 1000.0 * 25.0;
	}

	for (int i = 25; i < 50; i++)
	{
		ballsPositionX[i] = rand() % 1000 / 1000.0 * 25.0;
		ballsPositionZ[i] = -rand() % 1000 / 1000.0 * 25.0;
	}


}

TexturedBall::TexturedBall(const std::string& filename) : TexturedBall()
{
	SetTexture(filename);
}


void TexturedBall::Display()
{
	glPushMatrix();

	glPushAttrib(GL_ALL_ATTRIB_BITS);
	// Enable texturing (2D image as texture)
	glEnable(GL_TEXTURE_2D);
	// Bind input texture to GL_TEXTURE_2D buffer
	glBindTexture(GL_TEXTURE_2D, texID);
	// Handle lighting effects
	glEnable(GL_COLOR_MATERIAL);

	glPushMatrix();
	glTranslated(animateTransmissionX, animateTransmissionY, animateTransmissionZ);
	glPushMatrix();
	// inner rotation
	glTranslated(-10.0, 3.4, 0.0);
	glRotatef(rotation[1], 0.0f, 1.0f, 0.0f);
	glRotatef(rotation[2], 0.0f, 0.0f, 1.0f);
	glRotatef(rotation[0], 1.0f, 0.0f, 0.0f);
	glScaled(0.1, 0.1, 0.1);
	DrawSphere();
	// Unbind the texture
	glBindTexture(GL_TEXTURE_2D, NULL);
	// Disable texturing
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	for (int i = 0; i < 50; i++)
	{
		glPushMatrix();
		glTranslated(ballsPositionX[i],0.15, ballsPositionZ[i]);
		glColor3d(254 / 255.0, 186 / 255.0, 7 / 255.0);
		glutSolidSphere(0.1, 30, 30);
		glPopMatrix();
	}
	glPopMatrix();

	glPopAttrib();
	glPopMatrix();
}

void TexturedBall::Update(const double& deltaTime)
{
	//inner rotation of the ball
	rotation[0] += _xrot * static_cast<float>(deltaTime);
	rotation[1] += _yrot * static_cast<float>(deltaTime);

	// update the time and rotation steps
	animateTime += static_cast<float>(deltaTime);

	if (animateTime >= 4.0)
	{
		animateTime = 0.0f;
		keyframe = -1;
		//keyTransmissionX = -3.0;
		keyTransmissionZ = -4.3;
	}

	// from first key position to second
	if (animateTime < 2.0)
	{

		if (keyframe != 0)
		{
			keyframe = 0;
			keyTransmissionZ = -4.4;
			keyTransmissionX = -1.3;
		}

		animateTransmissionX = keyTransmissionX + 2.6 * animateTime / 2.0;
		animateTransmissionY =  abs(-1.6 * cos((PI / 2.0) * (animateTime - 0.5)));
		animateTransmissionZ = keyTransmissionZ + 8.6 * animateTime / 2.0;
	}

	else if(animateTime < 4.0)
	{
		if (keyframe != 1)
		{
			keyframe = 1;
			keyTransmissionZ = 4.4;
			keyTransmissionX = 1.3;
		}

		
		//update the position of the ball
		animateTransmissionX = keyTransmissionX - 2.6 * (animateTime - 2) / 2.0;
		animateTransmissionY = abs(-1.6 * cos((PI / 2.0) * (animateTime - 0.5)));
		animateTransmissionZ = keyTransmissionZ - 8.6 * (animateTime - 2.0) / 2.0;

	}

}

void TexturedBall::SetTexture(const std::string& filename)
{
	// Load texture using the provided Texture loader (.bmp only)
	texID = Scene::GetTexture(filename);
}

void TexturedBall::DrawSphere()
{
	SubDivide(6, &_initV[_VERTEX3], &_initV[_VERTEX0], &_initV[_VERTEX4]);
	SubDivide(6, &_initV[_VERTEX0], &_initV[_VERTEX1], &_initV[_VERTEX4]);
	SubDivide(6, &_initV[_VERTEX1], &_initV[_VERTEX2], &_initV[_VERTEX4]);
	SubDivide(6, &_initV[_VERTEX2], &_initV[_VERTEX3], &_initV[_VERTEX4]);
	// Bottom half
	SubDivide(6, &_initV[_VERTEX0], &_initV[_VERTEX3], &_initV[_VERTEX5]);
	SubDivide(6, &_initV[_VERTEX1], &_initV[_VERTEX0], &_initV[_VERTEX5]);
	SubDivide(6, &_initV[_VERTEX2], &_initV[_VERTEX1], &_initV[_VERTEX5]);
	SubDivide(6, &_initV[_VERTEX3], &_initV[_VERTEX2], &_initV[_VERTEX5]);
}

void TexturedBall::SubDivide(int recurse_idx, float* a, float* b, float* c)
{
	// Recursively subdivide faces
	if (recurse_idx > 0)
	{
		// Calcuate mid point between each pair of triangle vertices (a,b,c)
		float ab[3] = { a[0] + b[0], a[1] + b[1], a[2] + b[2] };
		float bc[3] = { b[0] + c[0], b[1] + c[1], b[2] + c[2] };
		float ca[3] = { c[0] + a[0], c[1] + a[1], c[2] + a[2] };

		// Normalise to vertices to have ||x|| = 1
		norm(ab);
		norm(bc);
		norm(ca);

		/*
			  a                      a
			 /\                      /\
			/  \                 ab /__\ ca
		   /    \       --->       /\  /\
		b /______\ c            b /__\/__\ c
									 bc
		*/
		SubDivide(recurse_idx - 1, a, ab, ca);
		SubDivide(recurse_idx - 1, ab, b, bc);
		SubDivide(recurse_idx - 1, ca, bc, c);
		SubDivide(recurse_idx - 1, ca, ab, bc);
	}
	// Draw final subdivision faces
	else
	{
		/*
			 a
			 /\
			/  \
		   /    \
		b /______\ c

		*/
		DrawFace(a, b, c);
	}
}

void TexturedBall::DrawFace(float* a, float* b, float* c)
{
	// Index texture coordinate (s,t) for vertex a (convert to angle and index between 0 and 1)
	float sa = 0.5f + atan2f(a[0], a[2]) / (2.0f * M_PI);
	float ta = 0.5f + asinf(a[1]) / M_PI;

	// Index texture coordinate (s,t) for vertex b (convert to angle and index between 0 and 1)
	float sb = 0.5f + atan2f(b[0], b[2]) / (2.0f * M_PI);
	float tb = 0.5f + asinf(b[1]) / M_PI;

	// Index texture coordinate (s,t,) for vertex c( convert to angle and index between 0 and 1)
	float sc = 0.5f + atan2f(c[0], c[2]) / (2.0f * M_PI);
	float tc = 0.5f + asinf(c[1]) / M_PI;

	// Fix seam issue when texture face goes from 1 to 0 (wrap around)
	FixSeam(sa, sb, sc);

	// Create face with texture bound texture
	_flagWireFrame ? glBegin(GL_LINE_LOOP) : glBegin(GL_TRIANGLES);
	// vertex a
	glTexCoord2f(sa, ta);
	glNormal3fv(a); glVertex3fv(a);
	// vertex b
	glTexCoord2f(sb, tb);
	glNormal3fv(b); glVertex3fv(b);
	// vertex c
	glTexCoord2f(sc, tc);
	glNormal3fv(c); glVertex3fv(c);
	glEnd();
}

void TexturedBall::FixSeam(float& a, float& b, float& c)
{
	if (b < 0.75f && a > 0.75f)
		b += 1.0f;
	else if (b > 0.75f && a < 0.75f)
		b -= 1.0f;

	if (c < 0.75f && a > 0.75f)
		c += 1.0f;
	else if (c > 0.75f && a < 0.75f)
		c -= 1.0f;
}
	