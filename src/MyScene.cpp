#include "MyScene.h"

#include "Lamp.h"
#include "Table.h"
#include "TexturedBarrier.h"
#include "Snowman.h"
#include "SnowmanWatcher.h"
#include "TexturedBall.h"
#include "skybox.h"
#include "Fan.h"
#include "Sofa.h"
#include "Trophy.h"
#include "Sky.h"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{
	
}

void MyScene::Initialise()
{
	//clear the color, initialize the background
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Use the Skybox class to draw the walls
	Skybox* skybox = new Skybox(20, 20);
	skybox->size(6.0);
	AddObjectToScene(skybox);

	// Draw the table tennis table, floor, net
	Table* t = new Table();
	t->size(6.0f);
	AddObjectToScene(t);

	// Draw the barriers
	TexturedBarrier* b = new TexturedBarrier("./src/texture3.bmp");
	b->size(100.0f);
	AddObjectToScene(b);

	//Draw the snowmen players
	Snowman* s1 = new Snowman();
	s1->size(6.0);
	AddObjectToScene(s1);

	//Draw the watchers
	SnowmanWatcher* s5 = new SnowmanWatcher();
	s5->size(6.0);
	AddObjectToScene(s5);

	//Draw the balls
	TexturedBall* ball = new TexturedBall("./src/ball3.bmp");
	ball->size(6.0);
	AddObjectToScene(ball);

	//Draw the fans
	Fan* f = new Fan();
	f->size(6.0);
	AddObjectToScene(f);

	//Draw the sofa
	Sofa* sofa = new Sofa();
	sofa->size(6.0);
	AddObjectToScene(sofa);

	//Draw the trophy
	Trophy* trophy = new Trophy();
	trophy->size(6.0);
	AddObjectToScene(trophy);

	//Draw the animated sky
	Sky* sky = new Sky(50, 50, "./src/sky4.bmp");
	//sky->position(0.0f, 100.0f, 100.0f);
	sky->size(6.0f);
	AddObjectToScene(sky);


}

void MyScene::Projection()
{
	//set the view angel into the projection function
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(view, aspect, 1.0, 1000.0);
}
