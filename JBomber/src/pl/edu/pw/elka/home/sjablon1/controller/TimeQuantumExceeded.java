package pl.edu.pw.elka.home.sjablon1.controller;

import java.util.LinkedList;
import java.util.Random;
import java.util.Timer;
import java.util.TimerTask;

import pl.edu.pw.elka.home.sjablon1.model.EnemyPowerUpCollision;
import pl.edu.pw.elka.home.sjablon1.model.ExplosionBrickCollision;
import pl.edu.pw.elka.home.sjablon1.model.ExplosionEnemyCollision;
import pl.edu.pw.elka.home.sjablon1.model.ExplosionPlayerCollision;
import pl.edu.pw.elka.home.sjablon1.model.PlayerPowerUpCollision;
import pl.edu.pw.elka.home.sjablon1.model.PositionStatic;
import pl.edu.pw.elka.home.sjablon1.model.Vertex;
import pl.edu.pw.elka.home.sjablon1.view.BackgroundTileView;
import pl.edu.pw.elka.home.sjablon1.view.BombAnimation;
import pl.edu.pw.elka.home.sjablon1.view.ExplosionAnimation;
import pl.edu.pw.elka.home.sjablon1.view.PowerUpAnimation;
import pl.edu.pw.elka.home.sjablon1.view.event.BombChangeStateEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.ExplosionChangeStateEvent;



/**
 * Class represents Timer Task that is execute when Game time quantum exceed. It stops
 * taking events from queue, update animation states and ask Model Unit about detected
 * collision.
 * @author Szymon Jablosnki
 * @version 1.0
 */
public class TimeQuantumExceeded extends TimerTask
{
	/** Game Controller Unit */
	private Controller controller;
	/** Game Timer */
	private Timer timer;
	
	/**
	 * Default constructor of TimeQuantumExceede object.
	 * 
	 * @param controller is Game MVC Controller Unit
	 */
	public TimeQuantumExceeded(Controller controller,Timer timer)
	{
		this.setController(controller);
		this.timer = timer;
	}
	
	@Override
	/**
	 * Method used to execute Time quantum exceeded event. 
	 */
	public void run()
	{
		this.getController().setTimeExceeded(true);
		this.getController().getBlockingEventQueue().clear();
		this.getTimer().cancel();
		System.out.println("Time Quantum Exceeded");
		
		/** Update Game animation state */
		this.updateBombAnimation();
		this.updateExplosionAnimation();
		this.updateBombPowerUpAnimation();
		this.updateExplosionPowerUpAnimation();
		this.updateSpeedPowerUpAnimation();
		
		
		/** Execute occurred collision  */
		LinkedList<ExplosionBrickCollision> explosionBrick = this.getController().getModel().
												getCollisionDetector().detectExplosionWithBrickCollision();
		if(explosionBrick!=null)
		{
			for(int i = 0; i<explosionBrick.size(); i++)
				this.executeExplosionBrickCollision(explosionBrick.get(i).getCollisionVertex());
		}
		
		ExplosionPlayerCollision explosionPlayer = this.getController().getModel().
										getCollisionDetector().detectExplosionWithPlayerCollision();
		if(explosionPlayer!=null)
			this.executeExplosionPlayerCollision(explosionPlayer.getCollisionVertex());
		
		ExplosionEnemyCollision explosionEnemy = this.getController().getModel().
										getCollisionDetector().detectExplosionWithEnemyCollision();
		if(explosionEnemy!=null)
			this.executeExplosionEnemyCollision(explosionEnemy.getCollisionVertex());
		
		
		PlayerPowerUpCollision playerCollision = this.getController().getModel().getCollisionDetector().
												 detectPlayerPowerUpCollision();
		if(playerCollision!=null)
			this.executePlayerPowerUpCollision(playerCollision);
		
		EnemyPowerUpCollision enemyCollision = this.getController().getModel().getCollisionDetector().
											   detectEnemyPowerUpCollision();
		if(enemyCollision!=null)
			this.executeEnemyPowerUpCollision(enemyCollision);
		
		
		/** Set up new Timer */
		this.getController().setTimeExceeded(false);
		this.getController().setGameTimer();
	}
	

	/**
	 * Method used to update Bomb Animation state.
	 */
	public void updateBombAnimation()
	{
		BombAnimation[] bombAnimationArray = this.getController().getView().getBombAnimationArray();
		if(bombAnimationArray != null)
		{
			for(int i = 0; i<bombAnimationArray.length; i++)
			{
				if(bombAnimationArray[i]!=null)
					bombAnimationArray[i].runAnimation();
			}
		}
		
		/** Update Bomb states */
		this.getController().getBlockingEventQueue().add(new BombChangeStateEvent(this));
	}
	
	/**
	 * Method used to update Explosion Animation state.
	 */
	public void updateExplosionAnimation()
	{
		ExplosionAnimation[] explosionAnimationArray = this.getController().getView().getExposionAnimationArray();
		if(explosionAnimationArray != null)
		{
			for(int i = 0; i<explosionAnimationArray.length; i++)
			{
				if(explosionAnimationArray[i]!=null)
					explosionAnimationArray[i].runAnimation();
			}
		}
		/** Update Explosion states */
		this.getController().getBlockingEventQueue().add(new ExplosionChangeStateEvent(this));
	}
	
	/**
	 * Method used to update Bomb PowerUp Animation state.
	 */
	public void updateBombPowerUpAnimation()
	{
		PowerUpAnimation[] bombPowerUpArray = this.getController().getView().getBombPowerUpArray();
		if(bombPowerUpArray != null)
		{
			for(int i = 0; i<bombPowerUpArray.length; i++)
			{
				if(bombPowerUpArray[i]!=null)
					bombPowerUpArray[i].runAnimation();
			}
		}
	}
	
	/**
	 * Method used to update Speed PowerUp Animation state.
	 */
	public void updateSpeedPowerUpAnimation()
	{
		PowerUpAnimation[] speedPowerUpArray = this.getController().getView().getSpeedPowerUpArray();
		if(speedPowerUpArray != null)
		{
			for(int i = 0; i<speedPowerUpArray.length; i++)
			{
				if(speedPowerUpArray[i]!=null)
					speedPowerUpArray[i].runAnimation();
			}
		}
	}
	
	/**
	 * Method used to update Speed PowerUp Animation state.
	 */
	public void updateExplosionPowerUpAnimation()
	{
		PowerUpAnimation[] explosionPowerUpArray = this.getController().getView().getExplosionPowerUpArray();
		if(explosionPowerUpArray != null)
		{
			for(int i = 0; i<explosionPowerUpArray.length; i++)
			{
				if(explosionPowerUpArray[i]!=null)
					explosionPowerUpArray[i].runAnimation();
			}
		}	
	}
	
	/**
	 * Method used to execute explosion with brick collision
	 * 
	 * @param collisionVertex is detected object vertex
 	 */
	public void executeExplosionBrickCollision(Vertex collisionVertex)
	{
		this.getController().getModel().activateVertexState(collisionVertex);
		
		int positionId = collisionVertex.getVertexId();
		int tilePositionX = (positionId%this.getController().getModel().getBoardDimension().getX())*40;
		int tilePositionY = positionId/this.getController().getModel().getBoardDimension().getX()*40; 
		
		Random generator = new Random();		
		int isPowerUp = generator.nextInt(10) + 1;
		
		switch(isPowerUp)
		{
			case 1:
			{
				PowerUpAnimation bombPowerUp = new PowerUpAnimation("bombPowerUp.png");
				bombPowerUp.setxPosition(tilePositionX);
				bombPowerUp.setyPosition(tilePositionY);
				
				PositionStatic[] powerUpArray = this.getController().getModel().getBombPowerUpPosition();
				PowerUpAnimation [] powerUpAnimation = this.getController().getView().getBombPowerUpArray();
				
				int iterator = 0;
				while(iterator < 10)
				{
					if(powerUpArray[iterator]==null)
						break;
					iterator++;
				}
								
				powerUpArray[iterator] = new PositionStatic(collisionVertex);
				powerUpAnimation[iterator] = bombPowerUp;
				
				this.getController().getView().updateBombPowerUp(powerUpAnimation);
				this.getController().getModel().updateBombPowerUpPosition(powerUpArray);
				this.getController().getModel().increaseBombPowerUp();
			
				this.getController().getView().addBombPowerUp(bombPowerUp);
				return;
			}
			case 4:
			{
				PowerUpAnimation speedPowerUp = new PowerUpAnimation("speedPowerUp.png");
				speedPowerUp.setxPosition(tilePositionX);
				speedPowerUp.setyPosition(tilePositionY);
				
				PositionStatic[] powerUpArray = this.getController().getModel().getSpeedPowerUpPosition();
				PowerUpAnimation [] powerUpAnimation = this.getController().getView().getSpeedPowerUpArray();
				
				int iterator = 0;
				while(iterator < 10)
				{
					if(powerUpArray[iterator]==null)
						break;
					iterator++;
				}
				
				powerUpArray[iterator] = new PositionStatic(collisionVertex);
				powerUpAnimation[iterator] = speedPowerUp;
				
				this.getController().getView().updateSpeedPowerUp(powerUpAnimation);
				this.getController().getModel().updateSpeedPowerUpPosition(powerUpArray);
				this.getController().getModel().increaseSpeedPowerUp();
				
				this.getController().getView().addSpeedPowerUp(speedPowerUp);
				return;
			}
			
			case 8:
			{
				PowerUpAnimation explosionPowerUp = new PowerUpAnimation("explosionPowerUp.png");
				explosionPowerUp.setxPosition(tilePositionX);
				explosionPowerUp.setyPosition(tilePositionY);
			
				PositionStatic[] powerUpArray = this.getController().getModel().getExplosionPowerUpPosition();
				PowerUpAnimation [] powerUpAnimation = this.getController().getView().getExplosionPowerUpArray();
				
				int iterator = 0;
				while(iterator < 10)
				{
					if(powerUpArray[iterator]==null)
						break;
					iterator++;
				}
				
				powerUpArray[iterator] = new PositionStatic(collisionVertex);
				powerUpAnimation[iterator] = explosionPowerUp;
				
				this.getController().getView().updateExplosionPowerUp(powerUpAnimation);
				this.getController().getModel().updateExplosionPowerUpPosition(powerUpArray);
				this.getController().getModel().increaseExplosionPowerUp();
				
				this.getController().getView().addExplosionPowerUp(explosionPowerUp);
				return;
			}
				
			default:
				break;
		}
		
		BackgroundTileView tile = new BackgroundTileView();
		tile.setTilePositionX(tilePositionX);
		tile.setTilePositionY(tilePositionY);
		
		this.getController().getView().addBackgroundTile(tile);
		
	}
	
	/**
	 * Method used to execute explosion with player collision
	 * 
	 * @param collisionVertex is detected object vertex
 	 */
	public void executeExplosionPlayerCollision(Vertex collisionVertex)
	{
		int positionId = collisionVertex.getVertexId();
		int playerPositionX = (positionId%this.getController().getModel().getBoardDimension().getX())*40;
		int playerPositionY = positionId/this.getController().getModel().getBoardDimension().getX()*40; 
		this.getController().getView().executePlayerDie(playerPositionX, playerPositionY);
		
	}
	
	/**
	 * Method used to execute explosion with enemy collision
	 * 
	 * @param collisionVertex is detected object vertex
 	 */
	public void executeExplosionEnemyCollision(Vertex collisionVertex)
	{
		int positionId = collisionVertex.getVertexId();
		int enemyPositionX = (positionId%this.getController().getModel().getBoardDimension().getX())*40;
		int enemyPositionY = positionId/this.getController().getModel().getBoardDimension().getX()*40; 
		this.getController().getView().executeEnemyDie(enemyPositionX, enemyPositionY);
	}

	
	/**
	 * Method used to execute Player with PowerUp collision
	 * 
	 * @param playerCollision is detected collision object
	 */
	public void executePlayerPowerUpCollision( PlayerPowerUpCollision playerCollision)
	{
		switch(playerCollision.getPowerUpId())
		{
			case 1:
			{
				this.getController().getModel().increasePlayerBombNumber();
				
				PowerUpAnimation[] powerUpArray = this.getController().getView().getBombPowerUpArray();
				PositionStatic[] powerUpPosition = this.getController().getModel().getBombPowerUpPosition();
				
				if(powerUpArray[playerCollision.getPowerUpIndex()]!= null)
					powerUpArray[playerCollision.getPowerUpIndex()].setVisible(false);
				powerUpArray[playerCollision.getPowerUpIndex()] = null;
				powerUpPosition[playerCollision.getPowerUpIndex()] = null;
				
				this.getController().getView().updateBombPowerUp(powerUpArray);
				this.getController().getModel().updateBombPowerUpPosition(powerUpPosition);

				int positionId = playerCollision.getPlayerVertex().getVertexId();
				int tilePositionX = (positionId%this.getController().getModel().getBoardDimension().getX())*40;
				int tilePositionY = positionId/this.getController().getModel().getBoardDimension().getX()*40;
				
				BackgroundTileView tile = new BackgroundTileView();
				tile.setTilePositionX(tilePositionX);
				tile.setTilePositionY(tilePositionY);
				
				this.getController().getView().addBackgroundTile(tile);
				break;
			}
			
			case 2:
			{
				this.getController().getModel().increasePlayerBombNumber();
				
				PowerUpAnimation[] powerUpArray = this.getController().getView().getSpeedPowerUpArray();
				PositionStatic[] powerUpPosition = this.getController().getModel().getSpeedPowerUpPosition();
				
				if(powerUpArray[playerCollision.getPowerUpIndex()]!= null)
					powerUpArray[playerCollision.getPowerUpIndex()].setVisible(false);
				powerUpArray[playerCollision.getPowerUpIndex()] = null;
				powerUpPosition[playerCollision.getPowerUpIndex()] = null;
				
				this.getController().getView().updateSpeedPowerUp(powerUpArray);
				this.getController().getModel().updateSpeedPowerUpPosition(powerUpPosition);
				
				int positionId = playerCollision.getPlayerVertex().getVertexId();
				int tilePositionX = (positionId%this.getController().getModel().getBoardDimension().getX())*40;
				int tilePositionY = positionId/this.getController().getModel().getBoardDimension().getX()*40;
				
				BackgroundTileView tile = new BackgroundTileView();
				tile.setTilePositionX(tilePositionX);
				tile.setTilePositionY(tilePositionY);
				
				this.getController().getView().addBackgroundTile(tile);
				break;
			}
			
			case 3:
			{
				PowerUpAnimation[] powerUpArray = this.getController().getView().getExplosionPowerUpArray();
				PositionStatic[] powerUpPosition = this.getController().getModel().getExplosionPowerUpPosition();
				
				if(powerUpArray[playerCollision.getPowerUpIndex()]!= null)
					powerUpArray[playerCollision.getPowerUpIndex()].setVisible(false);
				powerUpArray[playerCollision.getPowerUpIndex()] = null;
				powerUpPosition[playerCollision.getPowerUpIndex()] = null;
				
				this.getController().getView().updateExplosionPowerUp(powerUpArray);
				this.getController().getModel().updateExplosionPowerUpPosition(powerUpPosition);
				
				int positionId = playerCollision.getPlayerVertex().getVertexId();
				int tilePositionX = (positionId%this.getController().getModel().getBoardDimension().getX())*40;
				int tilePositionY = positionId/this.getController().getModel().getBoardDimension().getX()*40;
				
				BackgroundTileView tile = new BackgroundTileView();
				tile.setTilePositionX(tilePositionX);
				tile.setTilePositionY(tilePositionY);
				
				this.getController().getView().addBackgroundTile(tile);
				break;
			}
		}
		
	}
		
	/**
	 * Method used to execute Enemy with PowerUp collision
	 * 
	 * @param enemyCollision is detected collision object
	 */
	public void executeEnemyPowerUpCollision( EnemyPowerUpCollision enemyCollision)
	{
		switch(enemyCollision.getPowerUpId())
		{
			case 1:
			{
				this.getController().getModel().increaseEnemyBombNumber();
				
				PowerUpAnimation[] powerUpArray = this.getController().getView().getBombPowerUpArray();
				PositionStatic[] powerUpPosition = this.getController().getModel().getBombPowerUpPosition();
				
				if(powerUpArray[enemyCollision.getPowerUpIndex()]!= null)
					powerUpArray[enemyCollision.getPowerUpIndex()].setVisible(false);
				powerUpArray[enemyCollision.getPowerUpIndex()] = null;
				powerUpPosition[enemyCollision.getPowerUpIndex()] = null;
				
				this.getController().getView().updateBombPowerUp(powerUpArray);
				this.getController().getModel().updateBombPowerUpPosition(powerUpPosition);

				int positionId = enemyCollision.getEnemyVertex().getVertexId();
				int tilePositionX = (positionId%this.getController().getModel().getBoardDimension().getX())*40;
				int tilePositionY = positionId/this.getController().getModel().getBoardDimension().getX()*40;
				
				BackgroundTileView tile = new BackgroundTileView();
				tile.setTilePositionX(tilePositionX);
				tile.setTilePositionY(tilePositionY);
				
				this.getController().getView().addBackgroundTile(tile);
				break;
			}
			
			case 2:
			{
				this.getController().getModel().increaseEnemyBombNumber();
				
				PowerUpAnimation[] powerUpArray = this.getController().getView().getSpeedPowerUpArray();
				PositionStatic[] powerUpPosition = this.getController().getModel().getSpeedPowerUpPosition();
				
				if(powerUpArray[enemyCollision.getPowerUpIndex()]!= null)
					powerUpArray[enemyCollision.getPowerUpIndex()].setVisible(false);
				powerUpArray[enemyCollision.getPowerUpIndex()] = null;
				powerUpPosition[enemyCollision.getPowerUpIndex()] = null;
				
				this.getController().getView().updateSpeedPowerUp(powerUpArray);
				this.getController().getModel().updateSpeedPowerUpPosition(powerUpPosition);
				
				int positionId = enemyCollision.getEnemyVertex().getVertexId();
				int tilePositionX = (positionId%this.getController().getModel().getBoardDimension().getX())*40;
				int tilePositionY = positionId/this.getController().getModel().getBoardDimension().getX()*40;
				
				BackgroundTileView tile = new BackgroundTileView();
				tile.setTilePositionX(tilePositionX);
				tile.setTilePositionY(tilePositionY);
				
				this.getController().getView().addBackgroundTile(tile);
				break;
			}
			
			case 3:
			{
				PowerUpAnimation[] powerUpArray = this.getController().getView().getExplosionPowerUpArray();
				PositionStatic[] powerUpPosition = this.getController().getModel().getExplosionPowerUpPosition();
				
				if(powerUpArray[enemyCollision.getPowerUpIndex()]!= null)
					powerUpArray[enemyCollision.getPowerUpIndex()].setVisible(false);
				powerUpArray[enemyCollision.getPowerUpIndex()] = null;
				powerUpPosition[enemyCollision.getPowerUpIndex()] = null;
				
				this.getController().getView().updateExplosionPowerUp(powerUpArray);
				this.getController().getModel().updateExplosionPowerUpPosition(powerUpPosition);
				
				int positionId = enemyCollision.getEnemyVertex().getVertexId();
				int tilePositionX = (positionId%this.getController().getModel().getBoardDimension().getX())*40;
				int tilePositionY = positionId/this.getController().getModel().getBoardDimension().getX()*40;
				
				BackgroundTileView tile = new BackgroundTileView();
				tile.setTilePositionX(tilePositionX);
				tile.setTilePositionY(tilePositionY);
				
				this.getController().getView().addBackgroundTile(tile);
				break;
			}
		}
	}
	
	/**
	 * @param timer the timer to set
	 */
	public void setTimer(Timer timer)
	{
		this.timer = timer;
	}

	/**
	 * @return the timer
	 */
	public Timer getTimer()
	{
		return timer;
	}

	/**
	 * @param controller the controller to set
	 */
	public void setController(Controller controller)
	{
		this.controller = controller;
	}

	/**
	 * @return the controller
	 */
	public Controller getController()
	{
		return controller;
	}
	
}
