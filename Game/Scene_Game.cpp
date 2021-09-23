#include "pch.h"
#include "Scene_Game.h"

#include <InputManager.h>
#include <MoveCameraCommand.h>
#include <RotateCameraCommand.h>

#include <Material_GPUInstance.h>

Scene_Game::Scene_Game()
		   : Scene()
{}
Scene_Game::~Scene_Game()
{}

void Scene_Game::Initialize()
{
	// Bunny 1
	const std::string name1{ "Bunny 1" };
	const DirectX::XMFLOAT3 pos1{ 10, 0, 0 };
	Material_GPUInstance* pMaterial1 = new Material_GPUInstance();
	Create3DObject(name1, pos1, "./Resources/Meshes/lowpoly_bunny.obj", pMaterial1);

	// Bunny 2
	const std::string name2{ "Bunny 1" };
	const DirectX::XMFLOAT3 pos2{ -10, 0, 0 };
	Material_GPUInstance* pMaterial2 = new Material_GPUInstance();
	Create3DObject(name2, pos2, "./Resources/Meshes/lowpoly_bunny.obj", pMaterial2);

	// Main camera
	const std::string name3{ "Camera-Main" };
	const DirectX::XMFLOAT3 pos3{ 0, 0, -20 };
	CreateCamera(name3, pos3);

	// Inputs
	//CreateInputs();

	ActivateScene();
	Scene::Initialize();
}
void Scene_Game::PostInitialize()
{ Scene::PostInitialize(); }
void Scene_Game::Update(const float elapsedSec)
{ Scene::Update(elapsedSec); }
void Scene_Game::FixedUpdate(const float timeEachUpdate)
{ Scene::FixedUpdate(timeEachUpdate); }
void Scene_Game::LateUpdate()
{ Scene::LateUpdate(); }
void Scene_Game::Render() const
{ Scene::Render(); }

void Scene_Game::CreateInputs()
{
	InputManager* pInputManager{ Locator::GetInputManagerService() };
	// Arrows
	pInputManager->AddKeyToMap(ControllerButton::ButtonUp, KeyboardButton::ARROW_UP, ButtonPressType::BUTTON_RELEASED, "MOVE_FORWARD", new MoveCameraCommand(true, false, false, false));
	pInputManager->AddKeyToMap(ControllerButton::ButtonDown, KeyboardButton::ARROW_DOWN, ButtonPressType::BUTTON_RELEASED, "MOVE_BACKWARD", new MoveCameraCommand(false, true, false, false));
	pInputManager->AddKeyToMap(ControllerButton::ButtonLeft, KeyboardButton::ARROW_LEFT, ButtonPressType::BUTTON_RELEASED, "MOVE_LEFT", new MoveCameraCommand(false, false, true, false));
	pInputManager->AddKeyToMap(ControllerButton::ButtonRight, KeyboardButton::ARROW_RIGHT, ButtonPressType::BUTTON_RELEASED, "MOVE_RIGHT", new MoveCameraCommand(false, false, false, true));

	// WASD
	pInputManager->AddKeyToMap(ControllerButton::ButtonUp, KeyboardButton::W, ButtonPressType::BUTTON_RELEASED, "MOVE_FORWARD", new MoveCameraCommand(true, false, false, false));
	pInputManager->AddKeyToMap(ControllerButton::ButtonDown, KeyboardButton::S, ButtonPressType::BUTTON_RELEASED, "MOVE_BACKWARD", new MoveCameraCommand(false, true, false, false));
	pInputManager->AddKeyToMap(ControllerButton::ButtonLeft, KeyboardButton::A, ButtonPressType::BUTTON_RELEASED, "MOVE_LEFT", new MoveCameraCommand(false, false, true, false));
	pInputManager->AddKeyToMap(ControllerButton::ButtonRight, KeyboardButton::D, ButtonPressType::BUTTON_RELEASED, "MOVE_RIGHT", new MoveCameraCommand(false, false, false, true));
	pInputManager->AddKeyToMap(ControllerButton::ButtonLThumbStick, KeyboardButton::E, ButtonPressType::BUTTON_HOLD, "ROTATE", new RotateCameraCommand());
}