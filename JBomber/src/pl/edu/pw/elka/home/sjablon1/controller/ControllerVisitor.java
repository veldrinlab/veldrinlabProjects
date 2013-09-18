package pl.edu.pw.elka.home.sjablon1.controller;

import java.util.concurrent.ArrayBlockingQueue;

import pl.edu.pw.elka.home.sjablon1.model.*;
import pl.edu.pw.elka.home.sjablon1.view.event.GameEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.enemy.EnemyStopEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.player.PlayerStopEvent;


/**
 * Controller visitor class.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class ControllerVisitor implements Visitor
{
	/**Blocking Queue to take occurred Event and execute them, by communicating with
	 * Model and View object */
	private ArrayBlockingQueue<GameEvent> blockingEventQueue;
	
	/**
	 * Default constructor of Controller Visitor object.
	 * 
	 * @param blockingEventQueue is queue for event communications between, Model, View and
	 * 		  Controller Unit.
	 */
	public ControllerVisitor(ArrayBlockingQueue<GameEvent> blockingEventQueue)
	{
		this.setBlockingEventQueue(blockingEventQueue);		
	}
	
	@Override
	/**
	 * Method that starts Player Animation moving Up on GameBoard
	 * 
	 * @param executeObject is ExecutePlayerMoveUp object
	 */
	public void visit(ExecutePlayerMoveUp executeObject)
	{
		executeObject.getPlayerData();
		
		if(executeObject.checkForbiddenDestination())
			return;
		
		executeObject.changeDestination();
		executeObject.updateAnimationSpriteData();
		
		if(executeObject.checkIsPlayerMoving() && executeObject.getActualDestination()!= Destination.Up)
			this.getBlockingEventQueue().add(new PlayerStopEvent(this));
		
		executeObject.executePlayerMoving();
				
	}

	@Override
	/**
	 * Method that starts Player Animation moving Down on GameBoard
	 * 
	 * @param executeObject is ExecutePlayerMoveDown object
	 */
	public void visit(ExecutePlayerMoveDown executeObject)
	{
		executeObject.getPlayerData();
		
		if(executeObject.checkForbiddenDestination())
			return;
		
		executeObject.changeDestination();
		executeObject.updateAnimationSpriteData();
		
		if(executeObject.checkIsPlayerMoving() && executeObject.getActualDestination()!= Destination.Down)
			this.getBlockingEventQueue().add(new PlayerStopEvent(this));
		
		executeObject.executePlayerMoving();
	}

	@Override
	/**
	 * Method that starts Player Animation moving Left on GameBoard
	 * 
	 * @param executeObject is ExecutePlayerMoveLeft object
	 */
	public void visit(ExecutePlayerMoveLeft executeObject)
	{
		executeObject.getPlayerData();
		
		if(executeObject.checkForbiddenDestination())
			return;
		
		executeObject.changeDestination();
		executeObject.updateAnimationSpriteData();
		
		if(executeObject.checkIsPlayerMoving() && executeObject.getActualDestination()!= Destination.Left)
			this.getBlockingEventQueue().add(new PlayerStopEvent(this));
		
		executeObject.executePlayerMoving();
	}

	@Override
	/**
	 * Method that starts Player Animation moving Right on GameBoard
	 * 
	 * @param executeObject is ExecutePlayerMoveRight object
	 */
	public void visit(ExecutePlayerMoveRight executeObject)
	{
		executeObject.getPlayerData();
		
		if(executeObject.checkForbiddenDestination())
			return;
		
		executeObject.changeDestination();
		executeObject.updateAnimationSpriteData();
		
		if(executeObject.checkIsPlayerMoving() && executeObject.getActualDestination()!= Destination.Right)
			this.getBlockingEventQueue().add(new PlayerStopEvent(this));
		
		executeObject.executePlayerMoving();
	}
	
	@Override
	/**
	 * Method that Updates Player Model position and states.
	 * 
	 * @param executeObject is ExecutePlayerChangeState object
	 */
	public void visit(ExecutePlayerChangeState executeObject)
	{
		executeObject.getPlayerData();
		executeObject.updatePlayerState();
		
		if(!executeObject.updatePlayerDestination())
			this.getBlockingEventQueue().add(new PlayerStopEvent(this));
		
		executeObject.updateGameModel();
		
	}
	
	@Override
	/**
	 * Method that stop Player animation.
	 * 
	 * @param executeObject is ExecutePlayerStop object
	 */
	public void visit(ExecutePlayerStop executeObject)
	{
		executeObject.executeStop();
	}
	
	@Override
	/**
	 * Method that set Bomb in Position where Player planted it in Model and View Unit
	 * and start Bomb blowing animation.
	 * 
	 * @param executeObject is ExecutePlayerPlantBomb object
	 */
	public void visit(ExecutePlayerPlantBomb executeObject)
	{		
		if(executeObject.checkBombToPlant())
			return;
		executeObject.updateBombNumber();
		executeObject.getModelData();
		executeObject.setBombData();
		executeObject.updateModelViewData();
		
	}
	
	@Override
	/**
	 * Method that starts Enemy Animation moving Up on GameBoard
	 * 
	 * @param executeObject is ExecuteEnemyMoveUp object
	 */
	public void visit(ExecuteEnemyMoveUp executeObject)
	{
		executeObject.getEnemyData();
		
		if(executeObject.checkForbiddenDestination())
			return;
		
		executeObject.changeDestination();
		executeObject.updateAnimationSpriteData();
		
		if(executeObject.checkIsEnemyMoving() && executeObject.getActualDestination()!= Destination.Up)
			this.getBlockingEventQueue().add(new EnemyStopEvent(this));
		
		executeObject.executeEnemyMoving();
				
	}

	@Override
	/**
	 * Method that starts Enemy Animation moving Down on GameBoard
	 * 
	 * @param executeObject is ExecuteEnemyMoveDown object
	 */
	public void visit(ExecuteEnemyMoveDown executeObject)
	{
		executeObject.getEnemyData();
		
		if(executeObject.checkForbiddenDestination())
			return;
		
		executeObject.changeDestination();
		executeObject.updateAnimationSpriteData();
		
		if(executeObject.checkIsEnemyMoving() && executeObject.getActualDestination()!= Destination.Down)
			this.getBlockingEventQueue().add(new EnemyStopEvent(this));
		
		executeObject.executeEnemyMoving();
	}

	@Override
	/**
	 * Method that starts Enemy Animation moving Left on GameBoard
	 * 
	 * @param executeObject is ExecuteEnemyMoveLeft object
	 */
	public void visit(ExecuteEnemyMoveLeft executeObject)
	{
		executeObject.getEnemyData();
		
		if(executeObject.checkForbiddenDestination())
			return;
		
		executeObject.changeDestination();
		executeObject.updateAnimationSpriteData();
		
		if(executeObject.checkIsEnemyMoving() && executeObject.getActualDestination()!= Destination.Left)
			this.getBlockingEventQueue().add(new EnemyStopEvent(this));
		
		executeObject.executeEnemyMoving();
		
	}

	@Override
	/**
	 * Method that starts Enemy Animation moving Right on GameBoard
	 * 
	 * @param executeObject is ExecuteEnemyMoveRight object
	 */
	public void visit(ExecuteEnemyMoveRight executeObject)
	{
		executeObject.getEnemyData();
		
		if(executeObject.checkForbiddenDestination())
			return;
		
		executeObject.changeDestination();
		executeObject.updateAnimationSpriteData();
		
		if(executeObject.checkIsEnemyMoving() && executeObject.getActualDestination()!= Destination.Right)
			this.getBlockingEventQueue().add(new EnemyStopEvent(this));
		
		executeObject.executeEnemyMoving();
	}
	
	@Override
	/**
	 * Method that Updates Enemy Model position and states.
	 * 
	 * @param executeObject is ExecuteEnemyChangeState object
	 */
	public void visit(ExecuteEnemyChangeState executeObject)
	{		
		executeObject.getEnemyData();
		executeObject.updateEnemyState();
		
		if(!executeObject.updateEnemyDestination())
			this.getBlockingEventQueue().add(new EnemyStopEvent(this));
		
		executeObject.updateGameModel();		
				
	}
	
	@Override
	/**
	 * Method that stop Enemy animation.
	 * 
	 * @param executeObject is ExecuteEnemyStop object
	 */
	public void visit(ExecuteEnemyStop executeObject)
	{
		executeObject.executeStop();
	}
	
	@Override
	/**
	 * Method that set Bomb in Position where Enemy planted it in Model and View Unit
	 * and start Bomb blowing animation.
	 * 
	 * @param executeObject is ExecuteEnemyPlantBomb object
	 */
	public void visit(ExecuteEnemyPlantBomb executeObject)
	{			
		if(executeObject.checkBombToPlant())
			return;
		executeObject.updateBombNumber();
		executeObject.getModelData();
		executeObject.setBombData();
		executeObject.updateModelViewData();
		
	}
	
	@Override
	/**
	 * Method that updates Bomb State.
	 * 
	 * @param executeObject is ExecuteBombChangeState object.
	 */
	public void visit(ExecuteBombChangeState executeObject)
	{
		executeObject.getBombData();
		executeObject.updateBombState();
	}
	
	@Override
	/**
	 * Method that Blow up Bomb object.
	 * 
	 * @param executeObject is ExecuteBombBlowUp object.
	 */
	public void visit(ExecuteBombBlowUp executeObject)
	{
		executeObject.getBombData();
		executeObject.executeBombBlow();
	}
	
	@Override
	/**
	 * Method that creates and paints Explosion object and start CheckCollision thread.
	 * 
	 * @param executeObject is ExecuteExplosionStart object.
	 */
	public void visit(ExecuteExplosionStart executeObject)
	{
		executeObject.getExplosionData();
		executeObject.executeExplosionStart();
		
	}
	
	@Override
	/**
	 * Method that updates Explosion State.
	 * 
	 * @param executeObject is ExecuteExplosionChangeState object.
	 */
	public void visit(ExecuteExplosionChangeState executeObject)
	{
		executeObject.getExplosionData();
		executeObject.updateExplosionState();
	}
	
	@Override
	/**
	 * Method that ends Explosion animation.
	 * 
	 * @param executeObject is ExecuteExplosionEnd object.
	 */
	public void visit(ExecuteExplosionEnd executeObject)
	{
		executeObject.getExplosionData();
		executeObject.executeExplosionEnd();

	}
	
	@Override
	/**
	 * Method creates and display New Game: GameBoardView with Player/Enemy
	 * objects and starts game.
	 * 
	 * @param executeObject is ExecuteNewGame object
	 */
	public void visit( ExecuteNewGame executeObject ) 
	{
		executeObject.getModelData();
		executeObject.executeNewGame();	
	}
	
	@Override
	/**
	 * Method that display OptionsView object, set MenuView visible false.
	 * 
	 * @param executeObjecte is ExecuteOptions object
	 */
	public void visit(ExecuteOptions executeObject)
	{
		executeObject.executeDisplayOptions();
	}
	
	@Override
	/**
	 * Method that display CreditsView object, set MenuView visible false.
	 * 
	 * @param executeObject is ExecuteCredits object.
	 */
	public void visit(ExecuteCredits executeObject)
	{
		executeObject.executeDisplayCredits();
	}
	
	@Override
	/**
	 * Method that shutdown Credits/OptionsView and set MenuView visible true.
	 * 
	 * @param executeObject is ExecuteBackToMenu object.
	 */
	public void visit(ExecuteBackToMenu executeObject)
	{
		executeObject.executeBackToMenu();
	}
	
	@Override
	/**
	 * Method that end game and shut down whole application.
	 * 
	 * @param executeObject is ExecuteExitGame object
	 */
	public void visit(ExecuteExitGame executeObject)
	{
		executeObject.executeExit();
	}

	/**
	 * @param blockingEventQueue the blockingEventQueue to set
	 */
	private void setBlockingEventQueue(ArrayBlockingQueue<GameEvent> blockingEventQueue)
	{
		this.blockingEventQueue = blockingEventQueue;
	}

	/**
	 * @return the blockingEventQueue
	 */
	private ArrayBlockingQueue<GameEvent> getBlockingEventQueue()
	{
		return blockingEventQueue;
	}

}
