#pragma once
#include <Scene.h>

class Scene_Dev final : public Scene
{
	public:
		Scene_Dev();
		virtual ~Scene_Dev() override;

		Scene_Dev(const Scene_Dev& other) = delete;
		Scene_Dev(Scene_Dev&& other) = delete;
		Scene_Dev& operator=(const Scene_Dev& other) = delete;
		Scene_Dev& operator=(Scene_Dev&& other) = delete;

		void Initialize() override;
		void PostInitialize() override;
		void Update(const float elapsedSec) override;
		void FixedUpdate(const float timeEachUpdate) override;
		void LateUpdate() override;
		void Render() const override;
				
	private:
		void CreateInputs();
};