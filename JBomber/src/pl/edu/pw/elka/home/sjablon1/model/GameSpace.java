package pl.edu.pw.elka.home.sjablon1.model;

import pl.edu.pw.elka.home.sjablon1.utility.Configuration;

/**
 * Class represents the space in witch Game is located. GameSpace defines all objects
 * in game world like Player/Enemy, GameBoard, Graph, Bombs, PowerUps etc.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class GameSpace
{
	/**Object of GameBoard on witch Bombermans is fighting*/
	private GameBoard gameBoard;
	/**Object of GameGrapch - the space on witch all object can move and stand.*/
	private GameGraph moveGraph;
	/**Object of Player*/
	private Player playerBomberman;
	/**Object of Enemy/Enemies in game */
	private Enemy enemyBomberman;
	/**Object of dynamic position of Player Object.*/
	private PositionDynamic playerPosition;
	/**Object of dynamic position of Enemy Object.*/
	private PositionDynamic enemyPosition;
	/**Object of static position of active Bombs.*/
	private PositionStatic[] bombsPositions;
	/**Object of static position of active Bomb PowerUps.*/
	private PositionStatic[] bombPowerUpPositions;
	/**Object of static position of active Speed PowerUps.*/
	private PositionStatic[] speedPowerUpPositions;
	/**Object of static position of active Explosion PowerUps.*/
	private PositionStatic[] explosionPowerUpPositions;
	/**Object of static position of active Explosions.*/
	private PositionStatic[] explosionsPositions;
	/** Array of Bomb objects in GameSpace */
	private Bomb[] bombsOnBoard;
	/** Array of Explosion objects in GameSpace */
	private Explosion[] explosionOnBoard;
	/**Number of players in GameSpace.*/
	private int playerNumber;
	/**Number of enemies in GameSpace.*/
	private int enemyNumber;
	/**Number of bombs in GameSpace.*/
	private int bombNumber;
	/**Number of bombPowerUps in GameSpace.*/
	private int bombPowerUpNumber;
	/**Number of speedPowerUps in GameSpace.*/
	private int speedPowerUpNumber;
	/**Number of bombPowerUps in GameSpace.*/
	private int explosionPowerUpNumber;
	/**Number of explosions in GameSpace.*/
	private int explosionNumber;
	
	/**
	 * Default constructor of GameSpace object.
	 */
	public GameSpace()
	{
		/**
		 * All information about Player/Enemy start Position or number of Player/Enemy
		 * will be read from Configuration file.
		 */
		this.setGameArena( new GameBoard(Configuration.getInstance().getBoardStructureFileName()));
		this.setMoveGraph(new GameGraph(this.getGameBoard()));
		this.setPlayerBomberman(new Player());
		this.setPlayerPosition(new PositionDynamic(null,moveGraph.getVertexArray()[18],moveGraph.getVertexArray()[18].getDownDestination()));
		this.setPlayerNumber(Configuration.getInstance().getPlayerNumber());
		this.setEnemyBomberman(new Enemy());
		this.setEnemyPosition(new PositionDynamic(null,moveGraph.getVertexArray()[202],moveGraph.getVertexArray()[202].getDownDestination()));
		this.setEnemyNumber(Configuration.getInstance().getEnemyNumber());
		
		this.setBombNumber(0);
		this.setExplosionNumber(0);
		this.setBombPowerUpNumber(0);
		this.setExplosionPowerUpNumber(0);
		this.setSpeedPowerUpNumber(0);
		this.setBombsPositions(new PositionStatic[10]);
		this.setExplosionsPositions(new PositionStatic[10]);
		this.setBombsOnBoard(new Bomb[10]);
		this.setExplosionOnBoard(new Explosion[10]);
		this.setBombPowerUpPositions(new PositionStatic[10]);
		this.setExplosionPowerUpPositions(new PositionStatic[10]);
		this.setSpeedPowerUpPositions(new PositionStatic[10]);
	}
	
	/**
	 * @param gameBoard the gameArena to set
	 */
	public void setGameArena(final GameBoard gameBoard)
	{
		this.gameBoard = gameBoard;
	}
	
	/**
	 * @return the gameArena
	 */
	public GameBoard getGameBoard()
	{
		return gameBoard;
	}
	
	/**
	 * @param moveGraph the moveGraph to set
	 */
	public void setMoveGraph(final GameGraph moveGraph)
	{
		this.moveGraph = moveGraph;
	}
	
	/**
	 * @return the moveGraph
	 */
	public GameGraph getMoveGraph()
	{
		return moveGraph;
	}
	
	/**
	 * @param playerBomberman the playerBomberman to set
	 */
	public void setPlayerBomberman(final Player playerBomberman)
	{
		this.playerBomberman = playerBomberman;
	}
	
	/**
	 * @return the playerBomberman
	 */
	public Player getPlayerBomberman()
	{
		return playerBomberman;
	}
	
	/**
	 * @param enemyBomberman the enemyBomberman to set
	 */
	public void setEnemyBomberman(final Enemy enemyBomberman)
	{
		this.enemyBomberman = enemyBomberman;
	}
	
	/**
	 * @return the enemyBomberman
	 */
	public Enemy getEnemyBomberman()
	{
		return enemyBomberman;
	}
	
	/**
	 * @param playerPosition the playerPosition to set
	 */
	public void setPlayerPosition(final PositionDynamic playerPosition)
	{
		this.playerPosition = playerPosition;
	}
	
	/**
	 * @return the playerPosition
	 */
	public PositionDynamic getPlayerPosition()
	{
		return playerPosition;
	}
	
	/**
	 * @param enemyPosition the enemyPosition to set
	 */
	public void setEnemyPosition(final PositionDynamic enemyPosition)
	{
		this.enemyPosition = enemyPosition;
	}
	
	/**
	 * @return the enemyPosition
	 */
	public PositionDynamic getEnemyPosition()
	{
		return enemyPosition;
	}
	
	/**
	 * @param bombsPositions the bombsPositions to set
	 */
	public void setBombsPositions(final PositionStatic[] bombsPositions)
	{
		this.bombsPositions = bombsPositions;
	}
	
	/**
	 * @return the bombsPositions
	 */
	public PositionStatic[] getBombsPositions()
	{
		return bombsPositions;
	}
	
	
	/**
	 * @param explosionsPositions the explosionsPositions to set
	 */
	public void setExplosionsPositions(final PositionStatic[] explosionsPositions)
	{
		this.explosionsPositions = explosionsPositions;
	}
	
	/**
	 * @return the explosionsPositions
	 */
	public PositionStatic[] getExplosionsPositions()
	{
		return explosionsPositions;
	}
	
	/**
	 * @param playerNumber the playerNumber to set
	 */
	public void setPlayerNumber(final int playerNumber)
	{
		this.playerNumber = playerNumber;
	}

	/**
	 * @return the playerNumber
	 */
	public int getPlayerNumber()
	{
		return playerNumber;
	}

	/**
	 * @param enemyNumber the enemyNumber to set
	 */
	public void setEnemyNumber(final int enemyNumber)
	{
		this.enemyNumber = enemyNumber;
	}

	/**
	 * @return the enemyNumber
	 */
	public int getEnemyNumber()
	{
		return enemyNumber;
	}

	/**
	 * @param bombNumber the bombNumber to set
	 */
	public void setBombNumber(final int bombNumber)
	{
		this.bombNumber = bombNumber;
	}

	/**
	 * @return the bombNumber
	 */
	public int getBombNumber()
	{
		return bombNumber;
	}

	/**
	 * @param explosionNumber the explosionNumber to set
	 */
	public void setExplosionNumber(final int explosionNumber)
	{
		this.explosionNumber = explosionNumber;
	}

	/**
	 * @return the explosionNumber
	 */
	public int getExplosionNumber()
	{
		return explosionNumber;
	}
	
	/**
	 * @param bombsOnBoard the bombsOnBoard to set
	 */
	public void setBombsOnBoard(final Bomb[] bombsOnBoard)
	{
		this.bombsOnBoard = bombsOnBoard;
	}

	/**
	 * @return the bombsOnBoard
	 */
	public Bomb[] getBombsOnBoard()
	{
		return bombsOnBoard;
	}

	/**
	 * @param explosionOnBoard the explosionOnBoard to set
	 */
	public void setExplosionOnBoard(final Explosion[] explosionOnBoard)
	{
		this.explosionOnBoard = explosionOnBoard;
	}

	/**
	 * @return the explosionOnBoard
	 */
	public Explosion[] getExplosionOnBoard()
	{
		return explosionOnBoard;
	}

	/**
	 * @param bombPowerUpPositions the bombPowerUpPositions to set
	 */
	public void setBombPowerUpPositions(final PositionStatic[] bombPowerUpPositions)
	{
		this.bombPowerUpPositions = bombPowerUpPositions;
	}

	/**
	 * @return the bombPowerUpPositions
	 */
	public PositionStatic[] getBombPowerUpPositions()
	{
		return bombPowerUpPositions;
	}

	/**
	 * @param speedPowerUpPositions the speedPowerUpPositions to set
	 */
	public void setSpeedPowerUpPositions(final PositionStatic[] speedPowerUpPositions)
	{
		this.speedPowerUpPositions = speedPowerUpPositions;
	}

	/**
	 * @return the speedPowerUpPositions
	 */
	public PositionStatic[] getSpeedPowerUpPositions()
	{
		return speedPowerUpPositions;
	}

	/**
	 * @param explosionPowerUpPositions the explosionPowerUpPositions to set
	 */
	public void setExplosionPowerUpPositions(final PositionStatic[] explosionPowerUpPositions)
	{
		this.explosionPowerUpPositions = explosionPowerUpPositions;
	}

	/**
	 * @return the explosionPowerUpPositions
	 */
	public PositionStatic[] getExplosionPowerUpPositions()
	{
		return explosionPowerUpPositions;
	}

	/**
	 * @param bombPowerUpNumber the bombPowerUpNumber to set
	 */
	public void setBombPowerUpNumber(final int bombPowerUpNumber)
	{
		this.bombPowerUpNumber = bombPowerUpNumber;
	}

	/**
	 * @return the bombPowerUpNumber
	 */
	public int getBombPowerUpNumber()
	{
		return bombPowerUpNumber;
	}

	/**
	 * @param speedPowerUpNumber the speedPowerUpNumber to set
	 */
	public void setSpeedPowerUpNumber(final int speedPowerUpNumber)
	{
		this.speedPowerUpNumber = speedPowerUpNumber;
	}

	/**
	 * @return the speedPowerUpNumber
	 */
	public int getSpeedPowerUpNumber()
	{
		return speedPowerUpNumber;
	}

	/**
	 * @param explosionPowerUpNumber the explosionPowerUpNumber to set
	 */
	public void setExplosionPowerUpNumber(final int explosionPowerUpNumber)
	{
		this.explosionPowerUpNumber = explosionPowerUpNumber;
	}

	/**
	 * @return the explosionPowerUpNumber
	 */
	public int getExplosionPowerUpNumber()
	{
		return explosionPowerUpNumber;
	}
}
