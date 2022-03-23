#include "TexturedBarrier.h"


TexturedBarrier::TexturedBarrier(const std::string& filename)
{
	texID = Scene::GetTexture(filename);
}

void TexturedBarrier::Display()
{
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);

    DrawBarriers();

	glPopAttrib();
	glPopMatrix();
}

void TexturedBarrier::Update(const double& deltaTime)
{
}

void TexturedBarrier::DrawBarrierUnit()
{

    // Enable Texturing
    glEnable(GL_TEXTURE_2D);

    // Enable setting the colour of the material the cube is made from
    // as well as the material for blending.
    glEnable(GL_COLOR_MATERIAL);

    // Tell openGL which texture buffer to use
    glBindTexture(GL_TEXTURE_2D, texID);

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -0.05f);
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_QUADS);

    // set the normal of the front face
    glNormal3f(0.0f, 0.0f, 1.0f);

    // define texture coordinates for the 4 vertices
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0.0f, 3.0, 0.1f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.1f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(5.0f, 0.0f, 0.1f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(5.0f, 3.0f, 0.1f);

    // draw the back face

    // set the normal of the front face
    glNormal3f(0.0f, 0.0f, -1.0f);

    // define texture coordinates for the 4 vertices
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0.0f, 3.0, 0.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(5.0f, 3.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(5.0f, 0.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    
    // draw the left face

    // set the normal of the front face
    glNormal3f(-1.0f, 0.0f, 0.0f);

    // define texture coordinates for the 4 vertices
    glTexCoord2f(0.0f, 0.1f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.0, 0.0f, 0.1f);
    glTexCoord2f(0.1f, 0.0f);
    glVertex3f(0.0f, 3.0f, 0.1f);
    glTexCoord2f(0.1f, 0.1f);
    glVertex3f(0.0f, 3.0f, 0.0f);

    // draw the right face

    // set the normal of the front face
    glNormal3f(1.0f, 0.0f, 0.0f);

    // define texture coordinates for the 4 vertices
    glTexCoord2f(0.0f, 0.1f);
    glVertex3f(5.0f, 0.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(5.0f, 3.0f, 0.0f);
    glTexCoord2f(0.1f, 0.0f);
    glVertex3f(5.0f, 3.0f, 0.1f);
    glTexCoord2f(0.1f, 0.1f);
    glVertex3f(5.0f, 0.0f, 0.1f);


    // draw the top face

    // set the normal of the front face
    glNormal3f(0.0f, 1.0f, 0.0f);

    // define texture coordinates for the 4 vertices
    glTexCoord2f(0.0f, 0.1f);
    glVertex3f(0.0f, 3.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.0f, 3.0f, 0.1f);
    glTexCoord2f(0.1f, 0.0f);
    glVertex3f(5.0f, 3.0f, 0.1f);
    glTexCoord2f(0.1f, 0.1f);
    glVertex3f(5.0f, 3.0f, 0.0f);

    glEnd();


    glPopMatrix();
}

void TexturedBarrier::DrawBarriers()
{

    //draw the barriers, arrangement
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -25.0f);
    glPushMatrix();

    for (int i = 0; i < 5; i++)
    {
        glPushMatrix();
        glTranslated(i * 5.0, 0.0, 0.0);
        DrawBarrierUnit();
        glPopMatrix();

    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-25.0, 0.0, 0.0);
    for (int i = 0; i < 5; i++)
    {
        glPushMatrix();
        glTranslated(i * 5.0, 0.0, 0.0);
        DrawBarrierUnit();
        glPopMatrix();

    }
    glPopMatrix();
    glPopMatrix();

    //front
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 25.0f);
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
    glPushMatrix();

    for (int i = 0; i < 5; i++)
    {
        glPushMatrix();
        glTranslated(i * 5.0, 0.0, 0.0);
        DrawBarrierUnit();
        glPopMatrix();

    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-25.0, 0.0, 0.0);
    //glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
    for (int i = 0; i < 5; i++)
    {
        glPushMatrix();
        glTranslated(i * 5.0, 0.0, 0.0);
        DrawBarrierUnit();
        glPopMatrix();

    }
    glPopMatrix();
    glPopMatrix();

    //right
    glPushMatrix();
    glTranslatef(25.0f, 0.0f, 0.0f);
    glRotatef(-90.0, 0.0f, 1.0f, 0.0f);
    glPushMatrix();

    for (int i = 0; i < 5; i++)
    {
        glPushMatrix();
        glTranslated(i * 5.0, 0.0, 0.0);
        DrawBarrierUnit();
        glPopMatrix();

    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-25.0, 0.0, 0.0);
    //glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
    for (int i = 0; i < 5; i++)
    {
        glPushMatrix();
        glTranslated(i * 5.0, 0.0, 0.0);
        DrawBarrierUnit();
        glPopMatrix();

    }
    glPopMatrix();

    glPopMatrix();


    //middle
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glRotatef(-90.0, 0.0f, 1.0f, 0.0f);
    glPushMatrix();

    for (int i = 0; i < 5; i++)
    {
        glPushMatrix();
        glTranslated(i * 5.0, 0.0, 0.0);
        DrawBarrierUnit();
        glPopMatrix();

    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-25.0, 0.0, 0.0);
    for (int i = 0; i < 5; i++)
    {
        glPushMatrix();
        glTranslated(i * 5.0, 0.0, 0.0);
        DrawBarrierUnit();
        glPopMatrix();

    }
    glPopMatrix();

    glPopMatrix();


    //left
    glPushMatrix();
    glTranslatef(-25.0f, 0.0f, 0.0f);
    glRotatef(90.0, 0.0f, 1.0f, 0.0f);
    glPushMatrix();

    for (int i = 0; i < 5; i++)
    {
        glPushMatrix();
        glTranslated(i * 5.0, 0.0, 0.0);
        DrawBarrierUnit();
        glPopMatrix();

    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-25.0, 0.0, 0.0);
    //glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
    for (int i = 0; i < 5; i++)
    {
        glPushMatrix();
        glTranslated(i * 5.0, 0.0, 0.0);
        DrawBarrierUnit();
        glPopMatrix();

    }
    glPopMatrix();
    glPopMatrix();
}
