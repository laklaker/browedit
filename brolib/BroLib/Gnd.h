#pragma once

#include <string>
#include <vector>
#include <glm/glm.hpp>

namespace blib { class Texture; }

class Gnd
{
public:
	Gnd(const std::string &fileName);
	void save(std::string fileName);

	class Texture
	{
	public:
		std::string name;
		std::string file;

		blib::Texture* texture;
		Texture();
		~Texture();
	};

	class Lightmap
	{
	public:
		char data[256];
	};

	class Tile
	{
	public:
		glm::vec2 v1,v2,v3,v4;
		int textureIndex;
		int lightmapIndex;
		glm::vec4 color;
	};

	class Cube
	{
	public:
		Cube() 
		{
			selected = rand()%100 == 0;
		}
		float h1,h2,h3,h4;
		int tileUp, tileSide, tileFront;
		bool selected;
	};


	short version;
	int width;
	int height;
	float tileScale;
	int maxTexName;
	int lightmapWidth;
	int lightmapHeight;
	int gridSizeCell;
	std::vector<Texture*> textures;
	std::vector<Lightmap*> lightmaps;
	std::vector<Tile*> tiles;
	std::vector<std::vector<Cube*> > cubes;




};