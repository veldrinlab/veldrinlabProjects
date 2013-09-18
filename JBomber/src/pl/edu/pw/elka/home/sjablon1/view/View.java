package pl.edu.pw.elka.home.sjablon1.view;

import java.util.LinkedList;
import java.util.concurrent.ArrayBlockingQueue;

import javax.swing.JOptionPane;

import pl.edu.pw.elka.home.sjablon1.utility.Pair;
import pl.edu.pw.elka.home.sjablon1.view.event.GameEvent;




/**
 * Class represents one of main class of Game MVC architecture - View. It contains all object
 * off game View/GUI: all visible graphics in game like Player/Enemy animation, GameBoard
 * and all other explosions etc. View object give communication API for Controller object.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class View
{
	/**View of GameBoard object.*/
	private GameView gameView;
	/**View of Game Menu object*/
	private MenuView menuView;	
	/**View of Game Options object*/
	private OptionsView optionsView;
	/**View of Game Credits object*/
	private CreditsView creditsView;
	/**Blocking queue used to add occurred Events to communicate with Controller Unit */
	private ArrayBlockingQueue<GameEvent> blockingEventQueue;
	
	/**
	 * Constructor of View object. Initialize all Game GUI.
	 * 
	 * @param blockingEventQueue is queue for event communications between, Model, View and
	 * 		  Controller Unit.
	 */
	public View(ArrayBlockingQueue<GameEvent> blockingEventQueue)
	{
		this.setArrayBlockingEventQueue(blockingEventQueue);
		this.menuView = new MenuView(blockingEventQueue);	
	}
	
	
	/** Section of View Unit API for use by Controller Units */
	
	/**
	 * Method that initialize and display new game.
	 * 
	 * @param dimensionX is GameBoard x dimension
	 * @param dimensionY is GameBoard y dimension
	 * @param boardStructure is GameBoard logical structure
	 */
	public void displayNewGame(final int dimensionX,final int dimensionY,final char[][] boardStructure)
	{
		this.getMenuView().setVisible(false);
		this.getMenuView().dispose();
		
		GameBoardView gameBoardView = new GameBoardView();
		gameBoardView.setDimensionX(dimensionX);
		gameBoardView.setDimensionY(dimensionY);
		gameBoardView.setBoardLogicalStructure(boardStructure);
		this.setGameView(new GameView(blockingEventQueue));	
		this.getGameView().setGameBoardView(gameBoardView);

		PlayerMoveAnimation playerAnimation = new PlayerMoveAnimation("playerSprite.png",blockingEventQueue);
		this.getGameView().setPlayerAnimation(playerAnimation);
		EnemyMoveAnimation enemyAnimation = new EnemyMoveAnimation("enemySprite.png",blockingEventQueue);
		this.getGameView().setEnemyAnimation(enemyAnimation);
		
	}
	
	/**
	 * Method used to display OptionsView from Game Menu.
	 */
	public void displayOptionsView()
	{
		this.getMenuView().setVisible(false);
		this.setOptionsView(new OptionsView(blockingEventQueue));
	}
	
	/**
	 * Method used to display CreditsView from Game Menu.
	 */
	public void displayCreditsView()
	{
		this.getMenuView().setVisible(false);
		this.setCreditsView(new CreditsView(blockingEventQueue));
	}
	
	/**
	 * Method that close Options/Credits View and display Game Menu.
	 */
	public void displayMenuView()
	{
		if(this.getCreditsView()!=null)
		{
			this.getCreditsView().setVisible(false);
			this.getCreditsView().dispose();
		}
		else if(this.getOptionsView()!=null)
		{
			this.getOptionsView().setVisible(false);
			this.getOptionsView().dispose();	
		}
		this.getMenuView().setVisible(true);
	}
	
	/**
	 * Method used to set Player Animation Destination. 
	 */
	public void setPlayerAnimationDestination(final int horizontal, final int vertical)
	{
		this.getGameView().getPlayerAnimation().setMoveHorizontalValue(horizontal);
		this.getGameView().getPlayerAnimation().setMoveVerticalValue(vertical);
	}
	
	/**
	 * Method used to set Enemy Animation Destination. 
	 */
	public void setEnemyAnimationDestination(final int horizontal, final int vertical)
	{
		this.getGameView().getEnemyAnimation().setMoveHorizontalValue(horizontal);
		this.getGameView().getEnemyAnimation().setMoveVerticalValue(vertical);
	}
	
	/**
	 * Method used to check is Player moving.
	 */
	public boolean isPlayerMoving()
	{
		return this.getGameView().getPlayerAnimation().isAnimationRolling();
	}
	
	/**
	 * Method used to check is Enemy moving.
	 */
	public boolean isEnemyMoving()
	{
		return this.getGameView().getEnemyAnimation().isAnimationRolling();
	}
	
	/**
	 * Method used to start Player animation.
	 */
	public void startPlayerAnimation()
	{
		this.getGameView().getPlayerAnimation().startAnimation();
	}
	
	/**
	 * Method used to stop Player animation.
	 */
	public void stopPlayerAnimation()
	{
		this.getGameView().getPlayerAnimation().stopAnimation();
	}
	
	/**
	 * Method used to start Enemy animation.
	 */
	public void startEnemyAnimation()
	{
		this.getGameView().getEnemyAnimation().startAnimation();
	}
	
	/**
	 * Method used to stop Enemy animation.
	 */
	public void stopEnemyAnimation()
	{
		this.getGameView().getEnemyAnimation().stopAnimation();
	}
	
	
	/**
	 * Method used to get Bomb Animation Array.
	 */
	public BombAnimation[] getBombAnimationArray()
	{
		if(this.getGameView()!=null)
			return this.getGameView().getBombAnimationArray();
		else
			return null;
	}
	
	/**
	 * Method used to update Bomb Data.
	 * 
	 * @param bombAnimation is new Bomb Animation.
	 * @param bombAnimationArray is new Bomb Animation Array
	 */
	public void udpateBombViewData(final BombAnimation bombAnimation,final BombAnimation[] bombAnimationArray)
	{
		this.getGameView().getGameViewLayer().add(bombAnimation, new Integer(2));
		this.getGameView().getContentPane().add(this.getGameView().getGameViewLayer());
		this.getGameView().setBombAnimationArray(bombAnimationArray);
		bombAnimation.startAnimation();
		
	}
	
	/**
	 * Method used to get Explosion Animation Array.
	 */
	public ExplosionAnimation[] getExposionAnimationArray()
	{
		if(this.getGameView()!=null)
			return this.getGameView().getExplosionAnimationArray();
		else
			return null;
	}
	
	/**
	 * Method used to update Explosion Data.
	 * 
	 * @param explosionAnimation is new Explosion Animation.
	 * @param explosionAnimationArray is new Explosion Animation Array
	 */
	
	public void udpateExplosionViewData(final ExplosionAnimation explosionAnimation,final ExplosionAnimation[] explosionAnimationArray)
	{
		this.getGameView().getGameViewLayer().add(explosionAnimation, new Integer(2));
		this.getGameView().getContentPane().add(this.getGameView().getGameViewLayer());
		this.getGameView().setExplosionAnimationArray(explosionAnimationArray);
	}
	
	/**
	 * Method used to get Player Animation dimension. 
	 */
	public Pair getPlayerAnimationDimension()
	{
		int dimensionX = this.getGameView().getPlayerAnimation().getxPosition();
		int dimensionY = this.getGameView().getPlayerAnimation().getyPosition();
		
		return new Pair(dimensionX,dimensionY);
	}
	
	/**
	 * Method used to get Enemy Animation dimension. 
	 */
	public Pair getEnemyAnimationDimension()
	{
		int dimensionX = this.getGameView().getEnemyAnimation().getxPosition();
		int dimensionY = this.getGameView().getEnemyAnimation().getyPosition();
		
		return new Pair(dimensionX,dimensionY);
	}
	
	/**
	 * Method used to start Explosion animation
	 * 
	 * @param i is index of Explosion
	 * @param explosionRange is LinkedList of explosion range
	 */
	public void startExplosionAnimation(final int i,final LinkedList<Pair> explosionRange)
	{
		this.getExposionAnimationArray()[i].setExplosionRange(explosionRange);
		this.getGameView().getExplosionAnimationArray()[i].setVisible(true);
		this.getGameView().getExplosionAnimationArray()[i].startAnimation();
	}
	
	/**
	 * Method used to execute Player die animation.
	 * 
	 * @param playerPositionX
	 * @param playerPositionY
	 */
	public void executePlayerDie(final int playerPositionX,final int playerPositionY)
	{
		this.getGameView().getPlayerAnimation().setVisible(false);
		PlayerDieAnimation playerDie = new PlayerDieAnimation("playerSprite.png");	
		playerDie.setxPosition(playerPositionX);
		playerDie.setyPosition(playerPositionY);
		this.getGameView().getGameViewLayer().add(playerDie, new Integer(2));
		this.getGameView().getContentPane().add(this.getGameView().getGameViewLayer());
		
		JOptionPane.showMessageDialog(null, "Game Over! Enemy Wins!");

	}	
	
	/**
	 * Method used to execute Enemy die animation.
	 * 
	 * @param enemyPositionX
	 * @param enemyPositionY
	 */
	public void executeEnemyDie(final int enemyPositionX,final int enemyPositionY)
	{
		this.getGameView().getEnemyAnimation().setVisible(false);
		EnemyDieAnimation enemyDie = new EnemyDieAnimation("enemySprite.png");	
		enemyDie.setxPosition(enemyPositionX);
		enemyDie.setyPosition(enemyPositionY);
		this.getGameView().getGameViewLayer().add(enemyDie, new Integer(2));
		this.getGameView().getContentPane().add(this.getGameView().getGameViewLayer());
		
		JOptionPane.showMessageDialog(null, "Game Over! Player Wins!");
	}
	
	/**
	 * Method used to add Bomb Power Up to GameView.
	 * 
	 * @param bombPowerUp new PowerUp
	 */
	public void addBombPowerUp(final PowerUpAnimation bombPowerUp)
	{
		this.getGameView().getGameViewLayer().add(bombPowerUp, new Integer(1));
		this.getGameView().getContentPane().add(this.getGameView().getGameViewLayer());	
	}
	
	/**
	 * Method used to add Speed Power Up to GameView.
	 * 
	 * @param speedPowerUp new PowerUp
	 */
	public void addSpeedPowerUp(final PowerUpAnimation speedPowerUp)
	{
		this.getGameView().getGameViewLayer().add(speedPowerUp, new Integer(1));
		this.getGameView().getContentPane().add(this.getGameView().getGameViewLayer());
	}
	
	/**
	 * Method used to add Explosion Power Up to GameView.
	 * 
	 * @param explosionPowerUp new PowerUp
	 */
	public void addExplosionPowerUp(final PowerUpAnimation explosionPowerUp)
	{
		this.getGameView().getGameViewLayer().add(explosionPowerUp, new Integer(1));
		this.getGameView().getContentPane().add(this.getGameView().getGameViewLayer());
	}
	
	/**
	 * Method used to add BackgroundTile to GameView
	 * 
	 * @param tile is new tile
	 */
	public void addBackgroundTile(final BackgroundTileView tile)
	{
		this.getGameView().getGameViewLayer().add(tile, new Integer(1));
		this.getGameView().getContentPane().add(this.getGameView().getGameViewLayer());
	}
	
	
	/**
	 * Method used to get bomb power up array
	 * 
	 * @return bomb power up array
	 */
	public PowerUpAnimation[] getBombPowerUpArray()
	{
		if(this.getGameView()!=null)
			return this.getGameView().getBombPowerUp();
		else
			return null;
	}
	
	/**
	 * Method used to get speed power up array
	 * 
	 * @return speed power up array
	 */
	public PowerUpAnimation[] getSpeedPowerUpArray()
	{
		if(this.getGameView()!=null)
			return this.getGameView().getSpeedPowerUp();
		else
			return null;
	}
	
	/**
	 * Method used to get explosion power up array
	 * 
	 * @return explosion power up array
	 */
	public PowerUpAnimation[] getExplosionPowerUpArray()
	{
		if(this.getGameView()!=null)
			return this.getGameView().getExplosionPowerUp();
		else
			return null;
	}
	
	/**
	 * Method used to update bomb power up data.
	 * 
	 * @param powerUpArray is new array
	 */
	public void updateBombPowerUp(final PowerUpAnimation[] powerUpArray)
	{
		this.getGameView().setBombPowerUp(powerUpArray);
	}
	
	/**
	 * Method used to update speed power up data.
	 * 
	 * @param powerUpArray is new array
	 */
	public void updateSpeedPowerUp(final PowerUpAnimation[] powerUpArray)
	{
		this.getGameView().setSpeedPowerUp(powerUpArray);
	}
	
	/**
	 * Method used to update explosion power up data. 
	 * 
	 * @param powerUpArray is new array
	 */
	public void updateExplosionPowerUp(final PowerUpAnimation[] powerUpArray)
	{
		this.getGameView().setExplosionPowerUp(powerUpArray);
	}
	
	/**
	 * @param menuView the menuView to set
	 */
	@SuppressWarnings("unused")
	private void setMenuView(MenuView menuView)
	{
		this.menuView = menuView;
	}

	/**
	 * @return the menuView
	 */
	private MenuView getMenuView()
	{
		return menuView;
	}

	/**
	 * @param blockingEventQueue the blockingEventQueue to set
	 */
	private void setArrayBlockingEventQueue(ArrayBlockingQueue<GameEvent> blockingEventQueue)
	{
		this.blockingEventQueue = blockingEventQueue;
	}
	
	/**
	 * @param optionsView the optionsView to set
	 */
	private void setOptionsView(OptionsView optionsView)
	{
		this.optionsView = optionsView;
	}

	/**
	 * @return the optionsView
	 */
	private OptionsView getOptionsView()
	{
		return optionsView;
	}

	/**
	 * @param creditsView the creditsView to set
	 */
	private void setCreditsView(CreditsView creditsView)
	{
		this.creditsView = creditsView;
	}

	/**
	 * @return the creditsView
	 */
	private CreditsView getCreditsView()
	{
		return creditsView;
	}

	/**
	 * @param gameView the gameView to set
	 */
	private void setGameView(GameView gameView)
	{
		this.gameView = gameView;
	}

	/**
	 * @return the gameView
	 */
	private GameView getGameView()
	{
		return gameView;
	}
}
