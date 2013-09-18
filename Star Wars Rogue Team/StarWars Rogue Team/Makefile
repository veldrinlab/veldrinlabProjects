CXX := g++
INCLUDE := -I/usr/include/boost -I/usr/include/SDL -I/usr/include/GL -lXext -lX11 -lGL -lGLU -lm -lSDL -lSDLmain -lSDL_mixer -lSDL_image -lSDL_ttf -lboost_signals -L/usr/lib -lboost_system -lboost_filesystem

StarWars: main.o resourceManager.o mesh.o texture.o iMenuState.o optionsMenuState.o menuContext.o creditsMenuState.o showCreditsMenuState.o quitMenuState.o menuCode.o backMenuState.o battleOfHothMenuState.o battleOfMindorMenuState.o windowManager.o vector3D.o vbo.o timer.o tieFighter.o xwing.o chooseLevelMenuState.o colorDepthMenuState.o gameMenuState.o resolutionMenuState.o showOptionsMenuState.o shader.o skyBox.o specialFXManager.o starDestroyer.o terrain.o matrix4.o lighting.o levelManager.o laserBlast.o quaterion.o particle.o motionBlur.o sceneNode.o sceneManager.o renderer.o game.o gameHud.o fontException.o fog.o extensions.o explosionEffect.o engine.o enemyPrototypeFactory.o enemyPrototype.o gameState.o inputManager.o camera.o collisionDetector.o destroyEffect.o configuration.o asteroid.o atst.o boundingBox.o camera.o audioManager.o
	$(CXX) $(INCLUDE) main.o resourceManager.o mesh.o texture.o iMenuState.o optionsMenuState.o menuContext.o creditsMenuState.o showCreditsMenuState.o quitMenuState.o menuCode.o backMenuState.o battleOfHothMenuState.o vbo.o battleOfMindorMenuState.o windowManager.o vector3D.o timer.o tieFighter.o xwing.o chooseLevelMenuState.o colorDepthMenuState.o gameMenuState.o resolutionMenuState.o showOptionsMenuState.o shader.o skyBox.o specialFXManager.o starDestroyer.o terrain.o matrix4.o lighting.o levelManager.o laserBlast.o quaterion.o particle.o motionBlur.o sceneNode.o sceneManager.o renderer.o game.o gameHud.o fog.o extensions.o explosionEffect.o engine.o enemyPrototypeFactory.o enemyPrototype.o gameState.o inputManager.o collisionDetector.o destroyEffect.o configuration.o asteroid.o atst.o boundingBox.o camera.o audioManager.o -o StarWars

main.o: main.cpp texture.o mesh.o resourceManager.o
	$(CXX) -c main.cpp $(INCLUDE) -o main.o

windowManager.o: WindowManager.cpp WindowManager.hpp
	$(CXX) -c WindowManager.cpp $(INCLUDE) -o windowManager.o

asteroid.o: Asteroid.hpp Asteroid.cpp
	$(CXX) -c Asteroid.cpp $(INCLUDE) -o asteroid.o

atst.o: ATST.cpp ATST.hpp
	$(CXX) -c ATST.cpp $(INCLUDE) -o atst.o

audioManager.o: AudioManager.cpp AudioManager.hpp
	$(CXX) -c AudioManager.cpp $(INCLUDE) -o audioManager.o

boundingBox.o: BoundingBox.hpp BoundingBox.cpp
	$(CXX) -c BoundingBox.cpp $(INCLUDE) -o boundingBox.o

camera.o: Camera.hpp Camera.cpp
	$(CXX) -c Camera.cpp $(INCLUDE) -o camera.o

collisionDetector.o: CollisionDetector.cpp CollisionDetector.hpp
	$(CXX) -c CollisionDetector.cpp $(INCLUDE) -o collisionDetector.o

destroyEffect.o: DestroyEffect.cpp DestroyEffect.hpp
	$(CXX) -c DestroyEffect.cpp $(INCLUDE) -o destroyEffect.o

configuration.o: Configuration.cpp Configuration.hpp
	$(CXX) -c Configuration.cpp $(INCLUDE) -o configuration.o

enemyPrototype.o: EnemyPrototype.hpp EnemyPrototype.cpp
	$(CXX) -c EnemyPrototype.cpp $(INCLUDE) -o enemyPrototype.o

enemyPrototypeFactory.o: EnemyPrototypeFactory.cpp EnemyPrototypeFactory.hpp
	$(CXX) -c EnemyPrototypeFactory.cpp $(INCLUDE) -o enemyPrototypeFactory.o

engine.o: Engine.hpp Engine.cpp
	$(CXX) -c Engine.cpp $(INCLUDE) -o engine.o

explosionEffect.o: ExplosionEffect.cpp ExplosionEffect.hpp
	$(CXX) -c ExplosionEffect.cpp $(INCLUDE) -o explosionEffect.o

extensions.o: Extensions.cpp Extensions.hpp
	$(CXX) -c Extensions.cpp $(INCLUDE) -o extensions.o

fog.o: Fog.hpp Fog.cpp
	$(CXX) -c Fog.cpp $(INCLUDE) -o fog.o

fontException.o: FontException.hpp
	$(CXX) -c FontException.hpp $(INCLUDE) -o fontException.o

game.o: Game.cpp Game.hpp
	$(CXX) -c Game.cpp $(INCLUDE) -o game.o

gameHud.o: GameHud.hpp GameHud.cpp
	$(CXX) -c GameHud.cpp $(INCLUDE) -o gameHud.o

gameState.o: GameState.cpp GameState.hpp
	$(CXX) -c GameState.cpp $(INCLUDE) -o gameState.o

inputManager.o: InputManager.hpp InputManager.cpp
	$(CXX) -c InputManager.cpp $(INCLUDE) -o inputManager.o

matrix4.o: Matrix4.cpp Matrix4.hpp
	$(CXX) -c Matrix4.cpp $(INCLUDE) -o matrix4.o

lighting.o: Lighting.cpp Lighting.hpp
	$(CXX) -c Lighting.cpp $(INCLUDE) -o lighting.o

levelManager.o: LevelManager.cpp LevelManager.hpp
	$(CXX) -c LevelManager.cpp $(INCLUDE) -o levelManager.o

laserBlast.o: LaserBlast.hpp LaserBlast.cpp
	$(CXX) -c LaserBlast.cpp $(INCLUDE) -o laserBlast.o

quaterion.o: Quatenion.cpp Quaternion.hpp
	$(CXX) -c Quatenion.cpp $(INCLUDE) -o quaterion.o

particle.o: Particle.cpp Particle.hpp
	$(CXX) -c Particle.cpp $(INCLUDE) -o particle.o

motionBlur.o: MotionBlur.hpp MotionBlur.cpp
	$(CXX) -c MotionBlur.cpp $(INCLUDE) -o motionBlur.o

sceneNode.o: SceneNode.cpp SceneNode.hpp
	$(CXX) -c SceneNode.cpp $(INCLUDE) -o sceneNode.o

sceneManager.o: SceneManager.cpp SceneManager.hpp
	$(CXX) -c SceneManager.cpp $(INCLUDE) -o sceneManager.o

renderer.o: Renderer.cpp Renderer.hpp
	$(CXX) -c Renderer.cpp $(INCLUDE) -o renderer.o

shader.o: Shader.cpp Shader.hpp
	$(CXX) -c Shader.cpp $(INCLUDE) -o shader.o

skyBox.o: SkyBox.cpp SkyBox.hpp
	$(CXX) -c SkyBox.cpp $(INCLUDE) -o skyBox.o

specialFX.o: SpecialFX.hpp
	$(CXX) -c SpecialFX.hpp $(INCLUDE) -o specialFX.o

specialFXManager.o: SpecialFXManager.cpp SpecialFXManager.hpp
	$(CXX) -c SpecialFXManager.cpp $(INCLUDE) -o specialFXManager.o

starDestroyer.o: StarDestroyer.cpp StarDestroyer.hpp
	$(CXX) -c StarDestroyer.cpp $(INCLUDE) -o starDestroyer.o

terrain.o: Terrain.cpp Terrain.hpp
	$(CXX) -c Terrain.cpp $(INCLUDE) -o terrain.o

vector3D.o: Vector3D.cpp Vector3D.hpp
	$(CXX) -c Vector3D.cpp $(INCLUDE) -o vector3D.o

vbo.o: VBO.cpp VBO.hpp
	$(CXX) -c VBO.cpp $(INCLUDE) -o vbo.o

timer.o: Timer.cpp Timer.hpp
	 $(CXX) -c Timer.cpp $(INCLUDE) -o timer.o

tieFighter.o: TieFighter.cpp TieFighter.hpp
	$(CXX) -c TieFighter.cpp $(INCLUDE) -o tieFighter.o

xwing.o: Xwing.cpp Xwing.hpp
	$(CXX) -c Xwing.cpp $(INCLUDE) -o xwing.o

chooseLevelMenuState.o: ChooseLevelMenuState.cpp ChooseLevelMenuState.hpp
	$(CXX) -c ChooseLevelMenuState.cpp $(INCLUDE) -o chooseLevelMenuState.o

# Menu section

colorDepthMenuState.o: ColorDepthMenuState.cpp ColorDepthMenuState.hpp
	$(CXX) -c ColorDepthMenuState.cpp $(INCLUDE) -o colorDepthMenuState.o

gameMenuState.o: GameMenuState.cpp GameMenuState.hpp
	$(CXX) -c GameMenuState.cpp $(INCLUDE) -o gameMenuState.o

resolutionMenuState.o: ResolutionMenuState.cpp ResolutionMenuState.hpp
	$(CXX) -c ResolutionMenuState.cpp $(INCLUDE) -o resolutionMenuState.o

showOptionsMenuState.o: ShowOptionsMenuState.cpp ShowOptionsMenuState.hpp
	$(CXX) -c ShowOptionsMenuState.cpp $(INCLUDE) -o showOptionsMenuState.o

battleOfMindorMenuState.o: BattleOfMindorMenuState.cpp BattleOfMindorMenuState.hpp
	$(CXX) -c BattleOfMindorMenuState.cpp $(INCLUDE) -o battleOfMindorMenuState.o
battleOfHothMenuState.o: BattleOfHothMenuState.cpp BattleOfHothMenuState.hpp
	$(CXX) -c BattleOfHothMenuState.cpp $(INCLUDE) -o battleOfHothMenuState.o

backMenuState.o: BackMenuState.cpp BackMenuState.hpp
	$(CXX) -c BackMenuState.cpp $(INCLUDE) -o backMenuState.o

menuCode.o: Menu.cpp Menu.hpp
	$(CXX) -c Menu.cpp $(INCLUDE) -o menuCode.o

quitMenuState.o: Menu/QuitMenuState.cpp Menu/QuitMenuState.hpp
	$(CXX) -c Menu/QuitMenuState.cpp $(INCLUDE) -o quitMenuState.o 

showCreditsMenuState.o: Menu/ShowCreditsMenuState.cpp Menu/ShowCreditsMenuState.hpp
	$(CXX) -c Menu/ShowCreditsMenuState.cpp $(INCLUDE) -o showCreditsMenuState.o 

creditsMenuState.o: Menu/CreditsMenuState.cpp Menu/CreditsMenuState.hpp
	$(CXX) -c Menu/CreditsMenuState.cpp $(INCLUDE) -o creditsMenuState.o 

menuContext.o: Menu/MenuStateContext.cpp Menu/MenuStateContext.hpp
	$(CXX) -c Menu/MenuStateContext.cpp $(INCLUDE) -o menuContext.o 

optionsMenuState.o: Menu/OptionsMenuState.cpp Menu/OptionsMenuState.hpp
	$(CXX) -c Menu/OptionsMenuState.cpp $(INCLUDE) -o optionsMenuState.o 

iMenuState.o: Menu/IMenuState.cpp Menu/IMenuState.hpp
	$(CXX) -c Menu/IMenuState.cpp $(INCLUDE) -o iMenuState.o	

# ResourceManager section
#resourceManager.o: resourceManagerFile.o texture.o mesh.o resource.o
#	$(CXX) resourceManagerFile.o texture.o mesh.o resource.o -o resourceManager.o

resourceManager.o: ResourceManager/ResourceManager.cpp
	$(CXX) -c ResourceManager/ResourceManager.cpp $(INCLUDE) -o resourceManager.o
texture.o: resource.o ResourceManager/Texture.cpp
	$(CXX) -c ResourceManager/Texture.cpp $(INCLUDE) -o texture.o
mesh.o: resource.o ResourceManager/Mesh.cpp
	$(CXX) -c ResourceManager/Mesh.cpp $(INCLUDE) -o mesh.o
resource.o: ResourceManager/Resource.cpp
	$(CXX) -c ResourceManager/Resource.cpp $(INCLUDE) -o resource.o
