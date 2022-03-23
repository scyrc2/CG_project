
#include "DisplayableObject.h"
#include "Animation.h"



class Skybox :
	public DisplayableObject,
	public Animation
{
public:
	Skybox(const int& gridX, const int& gridZ);
	~Skybox();

	void Display();
	void Update(const double& deltaTime);

private:

	typedef unsigned int uint;
	typedef const char * pcStr;
	uint textures[6];
	static uint _loadTexture(pcStr filename);

	int texID;

	int xGridDims, zGridDims;
	float* texCoords;

	double time;
	bool frozen;

};