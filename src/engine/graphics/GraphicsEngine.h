#ifndef GRAPHICS_ENGINE_H
#define GRAPHICS_ENGINE_H
// STL
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#define GLEW_STATIC
#include <glew.h>
#include <glm.hpp>
#include <glfw3.h>
#include <gtc\matrix_transform.hpp>
#include <gtc\type_ptr.hpp>
#include <gtx\string_cast.hpp>

#include <vector>
#include <deque>
#include <unordered_map>

#include "MatrixNode.h"
#include "Geode.h"
#include "CameraNode.h"
#include "Renderable.h"
#include "Shader.h"

#include "..\network\Packet.h"
#include "..\utility\GameObject.h"
//#include "..\utility\GameState.h"
#include "..\utility\InputHandler.h"


typedef unsigned int ObjectId;

using namespace std;

typedef void (*KeyCallback) (int,int,int);

enum MenuStatus {
	START = 0,
	QUIT,
	MWINREPLAY,
	MWINQUIT,
	MLOSEREPLAY,
	MLOSEQUIT
};


class GraphicsEngine {
public:
	static void Initialize();
	static bool Closing();
	static void CloseGame();
	static void DrawAndPoll();
	static void DrawAndPollMenu();
	static void Destroy();
	static void SetKeyCallback(KeyCallback);
	static void MoveUp();
	static void MoveLeft();
	static void MoveDown();
	static void MoveRight();
	static void ScaleUp();
	static void ScaleDown();
	static KeyCallback GetKeyCallback();
	//static void UpdatePlayer(deque<Packet> &, GameState &);
   static int getKeyState(int);

   static void bindPlayerNode(GameObject* player);
	static void updateObject(ObjectId objId, glm::quat &, float, float, bool);
	static void insertObject(ObjectId objId, MatrixNode*);
   static void removeObject(ObjectId objId);
    static void ZoomIn();
    static void ZoomOut();
	static void setMenuStatus(MenuStatus ms);
	static MenuStatus getMenuStatus();

   static void setCursor(int);

	static MatrixNode* addNode(Renderable*, bool);
   static Renderable* selectModel(Model model);


private:
	static glm::mat4				m_view, m_projection;
	static glm::vec2                m_screen_scale;
	static bool						m_initialized;
	static GLFWwindow				*m_window;
	static GLint					m_uniView, m_uniProjection;
	static std::vector<MatrixNode*> m_objects;
	static KeyCallback				m_keyCallback;
	static MatrixNode				*m_player;
	static CameraNode				*m_mainCamera;
	static CameraNode				*m_minimapCamera;
	static MatrixNode				*m_scene;
	static int						HUDW;
	static int                      HUDH;

	static GLuint					m_timerId, m_plusId, m_minusId,m_borderId, m_skyboxId, m_HudId1, m_HudId2, m_HudId3, m_HudId4, m_HudIdN1, m_HudIdN2, m_HudIdN3, m_HudIdN4, m_groundId, m_menuId1, m_menuId2, m_menuId3, m_menuId4, m_menuId5, m_menuId6;// , m_tId;
	static Renderable				*m_timer, *m_plus, *m_minus, *m_border, *m_skybox, *m_HUD1, *m_HUD2, *m_HUD3, *m_HUD4, *m_HUDN1, *m_HUDN2, *m_HUDN3, *m_HUDN4, *worldModel, *m_menu;
	static Shader					*m_defaultShader, *m_skyboxShader, *m_textureShader;// , *m_tShader;

	static int						m_sunLight;


	static MenuStatus ms;
	static unordered_map<ObjectId, MatrixNode*> objNodeMap;
	
	static void renderScene(Node*, glm::mat4*);
	static void addHUD();
	static void renderHUD(int width, int height, glm::mat4 & identity);
};

#endif