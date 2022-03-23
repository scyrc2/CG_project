#include "skybox.h"

#include <cassert>
#include <stdio.h>
#include <stdlib.h>
#include <GL\glut.h>
// #include <GL\glaux.h>


#define TEX_SIZE 50
#define GL_CLAMP_TO_EDGE 0x812F

const char* texFiles[6] = {
	"./src/front.jpg",
	"./src/back.jpg",
	"./src/left.jpg",
	"./src/right.jpg",
	"./src/top.jpg",
	"./src/bottom.jpg" };

Skybox::Skybox(const int& gridX, const int& gridZ) 
	:xGridDims(gridX), zGridDims(gridZ), frozen(false), time(0.0)
{
	for (int i = 0; i < 6; i++)
	{
		textures[i] = _loadTexture(texFiles[i]);
		//cout << texFiles[i] << endl;
	}
		
	


	// initialise the grids texture coordinate memory we will need enough memory for both the s and t coordinate at each mesh vertex
	texCoords = new float[(xGridDims + 1) * (zGridDims + 1) * 2];

	//texID = Scene::GetTexture("./Textures/sky.bmp");
}


Skybox::~Skybox(void) {}
void Skybox::Display() {


	glEnable(GL_TEXTURE_2D);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glPushMatrix();

	//glDepthMask(GL_FALSE);
	glDisable(GL_DEPTH_TEST);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glColor3f(0, 0, 0);

	//front
	glBindTexture(GL_TEXTURE_2D, textures[0]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 1.0); glVertex3f(-TEX_SIZE, -TEX_SIZE, -TEX_SIZE);
	glTexCoord2f(1.0, 1.0); glVertex3f(TEX_SIZE, -TEX_SIZE, -TEX_SIZE);
	glTexCoord2f(1.0, 0.0); glVertex3f(TEX_SIZE, TEX_SIZE, -TEX_SIZE);
	glTexCoord2f(0.0, 0.0); glVertex3f(-TEX_SIZE, TEX_SIZE, -TEX_SIZE);
	glEnd();

	//back
	glBindTexture(GL_TEXTURE_2D, textures[1]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 1.0); glVertex3f(TEX_SIZE, -TEX_SIZE, TEX_SIZE);
	glTexCoord2f(1.0, 1.0); glVertex3f(-TEX_SIZE, -TEX_SIZE, TEX_SIZE);
	glTexCoord2f(1.0, 0.0); glVertex3f(-TEX_SIZE, TEX_SIZE, TEX_SIZE);
	glTexCoord2f(0.0, 0.0); glVertex3f(TEX_SIZE, TEX_SIZE, TEX_SIZE);
	glEnd();

	//left
	glBindTexture(GL_TEXTURE_2D, textures[2]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 1.0); glVertex3f(TEX_SIZE, -TEX_SIZE, -TEX_SIZE);
	glTexCoord2f(1.0, 1.0); glVertex3f(TEX_SIZE, -TEX_SIZE, TEX_SIZE);
	glTexCoord2f(1.0, 0.0); glVertex3f(TEX_SIZE, TEX_SIZE, TEX_SIZE);
	glTexCoord2f(0.0, 0.0); glVertex3f(TEX_SIZE, TEX_SIZE, -TEX_SIZE);
	glEnd();

	//right
	glBindTexture(GL_TEXTURE_2D, textures[3]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 1.0); glVertex3f(-TEX_SIZE, -TEX_SIZE, TEX_SIZE);
	glTexCoord2f(1.0, 1.0); glVertex3f(-TEX_SIZE, -TEX_SIZE, -TEX_SIZE);
	glTexCoord2f(1.0, 0.0); glVertex3f(-TEX_SIZE, TEX_SIZE, -TEX_SIZE);
	glTexCoord2f(0.0, 0.0); glVertex3f(-TEX_SIZE, TEX_SIZE, TEX_SIZE);
	glEnd();

	//down
	glBindTexture(GL_TEXTURE_2D, textures[5]);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0); glVertex3f(-TEX_SIZE, -TEX_SIZE, TEX_SIZE);
	glTexCoord2f(1.0, 0.0); glVertex3f(TEX_SIZE, -TEX_SIZE, TEX_SIZE);
	glTexCoord2f(1.0, 1.0); glVertex3f(TEX_SIZE, -TEX_SIZE, -TEX_SIZE);
	glTexCoord2f(0.0, 1.0); glVertex3f(-TEX_SIZE, -TEX_SIZE, -TEX_SIZE);
	glEnd();

	//DrawTop();

	//glDepthMask(GL_TRUE);
	glEnable(GL_DEPTH_TEST);
	glPopMatrix();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

}

void Skybox::Update(const double& deltaTime)
{
}


#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Skybox::uint Skybox::_loadTexture(pcStr filename) {


	struct Image
	{
		unsigned char *data;
		int sizeX;
		int sizeY;
	} img;

	// load image file
	img.data = stbi_load(filename, &img.sizeX, &img.sizeY, nullptr, 3);
	assert(img.data);

	GLuint texId;
	glGenTextures(1, &texId);
	glBindTexture(GL_TEXTURE_2D, texId);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.sizeX, img.sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, img.data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);

	stbi_image_free(img.data); // free the buffer

	return texId;
}
