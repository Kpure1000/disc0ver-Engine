/*
 * @Description:
 * @Author: ����
 * @Email: long452a@163.com
 * @Date: 2020-09-27
 */

#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "texture.h"

namespace disc0ver {
	// ����
	struct vertex {
		float x, y, z; // ����
		float r, g, b; // ��ɫ
		float u, v;  // ��ͼ����
	};

	class IBaseModel {
	public:
		unsigned int VAO, VBO, EBO;
		virtual void Init() = 0; // ����ģ��
		virtual void resize() = 0; // 
		virtual void draw() = 0; // ����ͼ��
		virtual void addTexture(const GLchar* texturePath) = 0;
	private:
		const std::vector<vertex> vertices;
		const std::vector<unsigned int> indices;
	};

	class rectangleModel : public IBaseModel {
	public:
		~rectangleModel();
		virtual void Init();
		virtual void resize();
		virtual void draw();
		virtual void addTexture(const GLchar* texturePath);
		std::vector<Texture> textures;
	private:
		std::vector<vertex> vertices = {
			//     ---- λ�� ----       ---- ��ɫ ----     - �������� -
			{ 0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f},   // ����
			{ 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f},   // ����
			{-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f},   // ����
			{-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f}    // ����
		};
		std::vector<unsigned int> indices = {
			0, 1, 3,
			1, 2, 3
		};
	};
}
#endif