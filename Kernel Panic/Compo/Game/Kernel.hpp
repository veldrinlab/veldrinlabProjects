#ifndef KERNEL_HPP
#define KERNEL_HPP

#include "../Engine/SceneEntity.hpp"
#include "../ResourceManager/ResourceManager.hpp"

namespace Game
{
	class Kernel : public Engine::SceneEntity
	{
	private:
		Kernel();

	public:
		Resource::PResource texture;
		int hpAccumulator;

		Kernel(const char* textureFileName, const Math::Vector3D& position, const int hpAmount);
		~Kernel();

		void renderEntity();
		void updateEntity(const float elapsedTime);


	};

}

#endif
