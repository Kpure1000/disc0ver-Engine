/*
 * @Description:
 * @Author: ����
 * @Email: long452a@163.com
 * @Date: 2021-2-20
 */

#ifndef MESH_H
#define MESH_H

#include<vector>

#include "texture.h"
#include "../math/DGM.h"
#include "transform.h"
#include "shader.h"

namespace disc0ver
{
	// ����
	struct Vertex {
		Position position;	// ����
		vec3<TRANSFORM> normal;	// ���㷨��
		glm::vec2 texCoords;

		Vertex(float x, float y, float z, float n1, float n2, float n3, float u, float v) : position(x, y, z), normal(n1, n2, n3), texCoords(u, v) {}
	};
	
	class Mesh
	{
    public:
        /*  ��������  */
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        std::vector<Texture> textures;

        Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
        void Draw(Shader &shader);
    private:
        /*  ��Ⱦ����  */
        unsigned int VAO, VBO, EBO;

        void setupMesh();
	};
}

#endif
