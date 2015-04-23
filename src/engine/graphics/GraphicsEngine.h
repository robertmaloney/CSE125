#ifndef GRAPHICS_ENGINE_H
#define GRAPHICS_ENGINE_H

#define GLEW_STATIC
#include <glew.h>
#include <glm.hpp>
#include <glfw3.h>
#include <gtc\matrix_transform.hpp>
#include <gtc\type_ptr.hpp>
#include <gtx\string_cast.hpp>

#include <vector>
#include <deque>
#include "MatrixNode.h"
#include "Geode.h"
#include "Renderable.h"
#include "..\utility\InputHandler.h"
#include "..\network\Packet.h"

using namespace std;

typedef void (*KeyCallback) (int,int,int);

class GraphicsEngine {
public:
	static void Initialize();
	static bool Closing();
	static void CloseGame();
	static void DrawAndPoll();
	static void Destroy();
	static void SetKeyCallback(KeyCallback);
	static void MoveUp();
	static void MoveLeft();
	static void MoveDown();
	static void MoveRight();
	static void ScaleUp();
	static void ScaleDown();
	static KeyCallback GetKeyCallback();
	static void UpdatePlayer(deque<Packet> &);
   static int getKeyState(int);

private:
	static glm::mat4				m_view, m_projection;
	static bool						m_initialized;
	static GLFWwindow				*m_window;
	static GLint					m_uniView, m_uniProjection;
	static std::vector<MatrixNode*> m_objects;
	static GLuint					m_vertexShader, m_fragmentShader, m_shaderProgram;
	static KeyCallback				m_keyCallback;
	static MatrixNode				*m_player;
	static MatrixNode				*m_scene;
	
	static void renderScene(Node*, glm::mat4*);
};

#endif