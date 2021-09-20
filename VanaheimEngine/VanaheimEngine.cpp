// >----------------------------------< //
// > Copyright 2021 - Vanaheim Engine < //
// > Author: Steve Verhoeven		  < //
// >----------------------------------< //
#include "pch.h"
#include "VanaheimEngine.h"

// Vanaheim includes
#include "Timer.h"
#include "Window.h"
#include "Graphics.h"
#include "Locator.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "ResourceManager.h"

VanaheimEngine::VanaheimEngine()
			   : m_pTimer(nullptr)
			   , m_pWindow(nullptr)
			   , m_pGraphics(nullptr)
			   , m_pDebugLogger(nullptr)
			   , m_pSceneManager(nullptr)
			   , m_pInputManager(nullptr)
			   , m_pResourceManager(nullptr)
{}
VanaheimEngine::~VanaheimEngine()
{
	DELETE_POINTER(m_pTimer);
	DELETE_POINTER(m_pWindow);
	DELETE_POINTER(m_pGraphics);
	DELETE_POINTER(m_pDebugLogger);
	DELETE_POINTER(m_pSceneManager);
	DELETE_POINTER(m_pInputManager);
	DELETE_POINTER(m_pResourceManager);
}

void VanaheimEngine::Initialize(HINSTANCE instance)
{
	int width{ 2560 }, height{ 1080 };

	m_pWindow = new Window("Vanaheim Engine", width, height, instance);
	m_pGraphics = new Graphics(m_pWindow->GetWindowHandle(), width, height);

	InitializeLocator();
}
void VanaheimEngine::Update()
{
	m_pTimer->Update();
}

void VanaheimEngine::InitializeLocator()
{
	Locator::ProvideGraphicsService(m_pGraphics);
	Locator::ProvideWindowService(m_pWindow);
	
	m_pTimer = new Timer();
	Locator::ProvideTimerService(m_pTimer);

	m_pDebugLogger = new DebugLogger();
	m_pDebugLogger->Initialize();
	Locator::ProvideLoggingService(m_pDebugLogger);

	m_pSceneManager = new SceneManager();
	Locator::ProvideSceneService(m_pSceneManager);

	m_pInputManager = new InputManager();
	Locator::ProvideInputService(m_pInputManager);

	m_pResourceManager = new ResourceManager();
	Locator::ProvideResourceService(m_pResourceManager);
}

void VanaheimEngine::Render()
{
	m_pGraphics->ClearBackbuffer();
	Locator::GetSceneManagerService()->Render();
	m_pGraphics->PresentBackbuffer();
}