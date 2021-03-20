/*
 * @Description:
 * @Author: 妄想
 * @Email: long452a@163.com
 * @Date: 2021-2-20
 */

#ifndef MESH_H
#define MESH_H

#include <utility>
#include<vector>

#include "texture.h"
#include "../math/DGM.h"
#include "transform.h"
#include "shader.h"

namespace disc0ver
{
	// 顶点
	struct Vertex {
		Position position;	// 坐标
		vec3<TRANSFORM> normal;	// 顶点法向
		glm::vec2 texCoords;

		Vertex() = default;
		Vertex(float x, float y, float z, float n1, float n2, float n3, float u, float v) : position(x, y, z), normal(n1, n2, n3), texCoords(u, v) {}
		Vertex(vec3<TRANSFORM> v, vec3<TRANSFORM> vn, glm::vec2 vt): position(v), normal(vn), texCoords(vt) {}
	};
	
	class Mesh
	{
    public:
        /*  网格数据  */
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        std::vector<Texture> textures;

        Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
        void Draw(Shader &shader);
		void addMaterial(Material material);
    private:
        /*  渲染数据  */
        unsigned int VAO, VBO, EBO;
		/* 材质 */
		Material material;
		bool useMaterial = false;

        void setupMesh();
	};
}

#endif
