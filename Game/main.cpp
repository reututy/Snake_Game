#include "InputManager.h"
#include "glm\glm.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	const int DISPLAY_WIDTH = 1340;
	const int DISPLAY_HEIGHT = 690;
	const float zFar = 10000.0f;
	const float zNear = 1.0f;
	const float CAM_ANGLE = 60.0f;
	const float relation = (float)DISPLAY_WIDTH / (float)DISPLAY_HEIGHT;
	Viewport vp1(401, 0, DISPLAY_WIDTH - 401, DISPLAY_HEIGHT);
	Viewport vp2(0, 265, 400, DISPLAY_HEIGHT - 265);
	Viewport vp3(0, 0, 400, 264);
	Viewport vp4(0, 0, DISPLAY_WIDTH, DISPLAY_HEIGHT);
	Viewport vp5(0, 0, DISPLAY_WIDTH, DISPLAY_HEIGHT);
	Viewport vp6(0, 0, DISPLAY_WIDTH, DISPLAY_HEIGHT);
	
	Game *scn = new Game(glm::vec3(0.0f, 0.0f, 1.0f), CAM_ANGLE, zNear, zFar, vp1); //snake view camera - 0
	scn->AddCamera(glm::vec3(0.0f, 30.0f, 0.5f), 70.0f, zNear, zFar, vp2);	//up view camera - 1
	scn->AddCamera(glm::vec3(0.0f, 0.0f, 1.0f), CAM_ANGLE, zNear, zFar, vp3);	//free view camera - 2
	scn->AddCamera(glm::vec3(-950.0f, 0.0f, 1.0f), CAM_ANGLE, zNear, zFar, vp4);	//Menu camera - 3

	scn->shapeTransformation(scn->zCameraTranslate, 80.0f);

	//Camera 0: snake view
	scn->GetCamera(0)->myTranslate(glm::vec3(2, 0, 0), 0); //x
	scn->GetCamera(0)->myTranslate(glm::vec3(0, 2, 0), 0); //y
	scn->GetCamera(0)->myTranslate(glm::vec3(0, 0, -4), 0); //z
	scn->GetCamera(0)->myRotate(90, glm::vec3(0, 1, 0), -1); //rotate in 90 degrees

	//Camera 1: up view
	scn->GetCamera(1)->myTranslate(glm::vec3(4, 0, 0), -1);
	scn->GetCamera(1)->myTranslate(glm::vec3(0, 80, 0), -1);
	scn->GetCamera(1)->myRotate(90, glm::vec3(0, 1, 0), -1);

	//Camera 2: free view
	scn->GetCamera(2)->myTranslate(glm::vec3(100, 0, 0), 0); //x
	scn->GetCamera(2)->myTranslate(glm::vec3(0, 20, 0), 0); //y
	scn->GetCamera(2)->myTranslate(glm::vec3(0, 0, -4), 0); //z
	scn->GetCamera(2)->myRotate(90, glm::vec3(0, 1, 0), -1); //rotate in 90 degrees

	//Camera 3: Menu view
	scn->GetCamera(3)->myTranslate(glm::vec3(-600, 0, 0), -1);

	Display display(DISPLAY_WIDTH, DISPLAY_HEIGHT, "OpenGL");

	init(display);

	scn->Init();

	//Shaders:
	scn->addShader("../res/shaders/pickingShader");  //0
	scn->addShader("../res/shaders/basicShader"); //1
	scn->addShader("../res/shaders/ShaderLBS"); //2
	scn->addShader("../res/shaders/skinningShader"); //3

	//snake textures:
	scn->AddTexture("../res/textures/game/snake1.png", false); //0
	scn->AddTexture("../res/textures/game/snake_eyes.png", false); //1
	//water textures:
	scn->AddTexture("../res/textures/game/cave.png", false); //2
	scn->AddTexture("../res/textures/game/water_front.png", false); //3
	scn->AddTexture("../res/textures/game/water_up.png", false); //4
	scn->AddTexture("../res/textures/game/water_ground.png", false); //5
	//Obstacles textures:
	scn->AddTexture("../res/textures/game/rock.png", false); //6
	scn->AddTexture("../res/textures/game/bubble.png", false); //7
	scn->AddTexture("../res/textures/game/black.png", false); //8
	scn->AddTexture("../res/textures/game/door.png", false); //9
	//Rewords textures:
	scn->AddTexture("../res/textures/shines/gold_shine.png", false); //10
	scn->AddTexture("../res/textures/shines/red_shine.png", false); //11
	scn->AddTexture("../res/textures/shines/pink_shine.png", false); //12
	//Menues textures:
	scn->AddTexture("../res/textures/Menues-min/MainMenu0-min.png", false); //13
	scn->AddTexture("../res/textures/Menues-min/MainMenu1-min.png", false); //14
	scn->AddTexture("../res/textures/Menues-min/MainMenu2-min.png", false); //15
	scn->AddTexture("../res/textures/Menues-min/AboutMenu-min.png", false); //16
	scn->AddTexture("../res/textures/Menues-min/AboutMenuBack-min.png", false); //17
	scn->AddTexture("../res/textures/Menues-min/MainMenu3-min.png", false); //18
	scn->AddTexture("../res/textures/Menues-min/HowToPlay0-min.png", false); //19
	scn->AddTexture("../res/textures/Menues-min/HowToPlay1-min.png", false); //20
	scn->AddTexture("../res/textures/Menues-min/GameOver-min.png", false); //21
	scn->AddTexture("../res/textures/Menues-min/WinStar1-min.png", false); //22
	scn->AddTexture("../res/textures/Menues-min/WinStar2-min.png", false); //23
	scn->AddTexture("../res/textures/Menues-min/WinStar3-min.png", false); //24
	//Animals textures:
	scn->AddTexture("../res/textures/game/Walrus.png", false); //25
	scn->AddTexture("../res/textures/game/sea_horse.png", false); //26
	scn->AddTexture("../res/textures/game/fish1.png", false); //27
	scn->AddTexture("../res/textures/game/coral1.png", false); //28
	scn->AddTexture("../res/textures/game/coral2.png", false); //29
	scn->AddTexture("../res/textures/game/coral3.png", false); //30
	
	

	display.setScene(scn);

	while (!display.closeWindow())
	{
		if (scn->GetMainView() == true)
			scn->Draw(1, 3, BACK, true, false);
		else
		{
			for (int i = 0; i < 3; i++)
				scn->Draw(1, i, BACK, i < 1, false);
			if (scn->GetView() == true)
			{
				scn->GetCamera(0)->SetView(vp1);
				scn->GetCamera(1)->SetView(vp2);
			}
			else
			{
				scn->GetCamera(0)->SetView(vp2);
				scn->GetCamera(1)->SetView(vp1);
			}
		}
		scn->Motion();
		display.SwapBuffers();
		display.PollEvents();
	}
	delete scn;
	return 0;
}