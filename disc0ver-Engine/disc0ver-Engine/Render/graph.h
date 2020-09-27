#pragma once
#ifndef GRAPH_H
#define SHADER_H

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<vector>

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
	private:
		std::vector<vertex> vertices;
		std::vector<unsigned int> indices;
	};

	class rectangleModel : public IBaseModel {
	public:
		~rectangleModel();
		virtual void Init();
		virtual void resize();
		virtual void draw();
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