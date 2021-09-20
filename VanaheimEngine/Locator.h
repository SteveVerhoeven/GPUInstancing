#pragma once

class Timer;
class Window;
class Graphics;
class DebugLogger;
class SceneManager;
class InputManager;
class ResourceManager;
class VanaheimEngine;
class CameraComponent;
class GeneratorManager;
class Locator final
{
	public:
		Locator() = default;
		~Locator() = default;

		Locator(const Locator&) = delete;
		Locator(Locator&&) noexcept = delete;
		Locator& operator=(const Locator&) = delete;
		Locator& operator=(Locator&&) noexcept = delete;

		// Scene
		static void ProvideSceneService(SceneManager* pSceneService) { m_pSceneManager = pSceneService; }
		static SceneManager* const GetSceneManagerService() { return m_pSceneManager; }
		// Input
		static void ProvideInputService(InputManager* pInputService) { m_pInputManager = pInputService; }
		static InputManager* const GetInputManagerService() { return m_pInputManager; }
		// Debug logger
		static void ProvideLoggingService(DebugLogger* pLoggingService) { m_pDebugLogger = pLoggingService; }
		static DebugLogger* const GetDebugLoggerService() { return m_pDebugLogger; }
		// Resource
		static void ProvideResourceService(ResourceManager* pResourceManager) { m_pResourceManager = pResourceManager; }
		static ResourceManager* const GetResourceManagerService() { return m_pResourceManager; }
		// Graphics
		static void ProvideGraphicsService(Graphics* pGraphics) { m_pGraphics = pGraphics; }
		static Graphics* const GetGraphicsService() { return m_pGraphics; }
		// Window
		static void ProvideWindowService(Window* pWindow) { m_pWindow = pWindow; }
		static Window* const GetWindowService() { return m_pWindow; }
		// Camera
		static void ProvideCameraService(CameraComponent* pCameraComponent) { m_pCameraComponent = pCameraComponent; }
		static CameraComponent* const GetCameraService() { return m_pCameraComponent; }
		// Timer
		static void ProvideTimerService(Timer* pTimer) { m_pTimer = pTimer; }
		static Timer* const GetTimerService() { return m_pTimer; }

	private:
		static inline Timer* m_pTimer = nullptr;
		static inline DebugLogger* m_pDebugLogger = nullptr;
		static inline SceneManager* m_pSceneManager = nullptr;
		static inline InputManager* m_pInputManager = nullptr;
		static inline ResourceManager* m_pResourceManager = nullptr;
		static inline Graphics* m_pGraphics = nullptr;
		static inline Window* m_pWindow = nullptr;
		static inline CameraComponent* m_pCameraComponent = nullptr;
};