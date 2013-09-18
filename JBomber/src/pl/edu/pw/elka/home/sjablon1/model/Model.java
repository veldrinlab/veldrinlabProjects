package pl.edu.pw.elka.home.sjablon1.model;

import java.util.LinkedList;

import pl.edu.pw.elka.home.sjablon1.utility.Pair;

/**
 * Class represents one of main class of Game MVC architecture - Model. It contains all object
 * off game Model: GameSpace which all objects, and other GameCore objects like audio, 
 * Configuration game pad connection, enemy AI structure etc.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class Model
{
	/**Main object of Main Unit - store all information game logic*/
	private GameSpace gameSpace;
	/** Inner Game collision detector object*/
	private CollisionDetector collisionDetector;
	
	
	/**
	 * Default constructor of Model object.
	 */
	public Model()
	{
		gameSpace = new GameSpace();
	}
	
	
	/** GameBoard API */
	
	/**
	 * Method that return GameBoard dimension data.
	 * @return Pair object
	 */
	public Pair getBoardDimension()
	{
		int dimensionX = this.getGameSpace().getGameBoard().getDimensionX();
		int dimensionY = this.getGameSpace().getGameBoard().getDimensionY();
		
		return new Pair(dimensionX,dimensionY);
	}
	
	/**
	 * Method that return GameBoard Logical structure.
	 * 
	 * @param dimensionX is GameBoard x dimension
	 * @param dimensionY is GameBoard y dimension
	 * @return GameBoard structure
	 */
	public char[][] getBoardStructure(final int dimensionX,final int dimensionY)
	{
		char[][] boardStructure = new char[dimensionX][dimensionY];
		Tile[][] boardAbstractStructure = this.getGameSpace().getGameBoard().getBoardStructure();
		
		for(int i = 0; i<dimensionX; i++)
		{
			for(int j =0; j<dimensionY; j++)
			{
				if(boardAbstractStructure[i][j] instanceof WallTile)
					boardStructure[i][j] = '#';
				else if(boardAbstractStructure[i][j] instanceof BrickTile)
					boardStructure[i][j] = '?';
				else if(boardAbstractStructure[i][j] instanceof BackgroundTile)
					boardStructure[i][j] = '*';
			}
		}
		
		return boardStructure;
		
	}
	
	/** Player and Enemy API */
	
	/**
	 * Method use to get Player actual destination
	 * 
	 * @return player actual destination.
	 */
	public Destination getPlayerActualDestination()
	{
		return this.getGameSpace().getPlayerBomberman().getPlayerDestination();
	}
	
	/**
	 * Method use to get Enemy actual destination
	 * 
	 * @return enemy actual destination.
	 */
	public Destination getEnemyActualDestination()
	{
		return this.getGameSpace().getEnemyBomberman().getEnemyDestination();
	}
	
	/**
	 * Method used to get Player actual Position vertex.
	 * 
	 * @return actual player position vertex
	 */
	public Vertex getPlayerActualPosition()
	{
		if(this.getGameSpace().getPlayerPosition().getPositionVertex()!=null)
			return this.getGameSpace().getPlayerPosition().getPositionVertex();
		return null;
	}
	
	/**
	 * Method used to get Player actual Destination vertex.
	 * 
	 * @return actual player destination vertex
	 */
	public Vertex getPlayerActualDestinationVertex()
	{
		return this.getGameSpace().getPlayerPosition().getDestinationVertex();
	}
	
	/**
	 * Method used to get Enemy actual Position vertex.
	 * @return actual enemy position vertex
	 */
	public Vertex getEnemyActualPosition()
	{
		if(this.getGameSpace().getEnemyPosition().getPositionVertex()!=null)
			return this.getGameSpace().getEnemyPosition().getPositionVertex();
		return null;
	}	
	
	/**
	 * Method used to get Enemy actual Destination vertex.
	 * 
	 * @return actual enemy destination vertex
	 */
	public Vertex getEnemyActualDestinationVertex()
	{
		return this.getGameSpace().getEnemyPosition().getDestinationVertex();
	}
	
	
	/**
	 * Method used to set Player actual destination.
	 * 
	 * @param destination is new player destination
	 */
	public void setPlayerActualDestination(final Destination destination)
	{
		this.getGameSpace().getPlayerBomberman().setPlayerDestination(destination);
	}
	
	/**
	 * Method used to set actual Player Position Vertex.
	 * 
	 * @param positionVertex is new Player position vertex
	 */
	public void setPlayerActualPosition(final Vertex positionVertex)
	{
		this.getGameSpace().getPlayerPosition().setPositionVertex(positionVertex);
	}
	
	/**
	 * Method used to set actual Player destination vertex.
	 * 
	 * @param destinationVertex is new Player destination vertex
	 */
	public void setPlayerActualDestinationVertex(final Vertex destinationVertex)
	{	
		this.getGameSpace().getPlayerPosition().setDestinationVertex(destinationVertex);
	}
	
	/**
	 * Method used to set Enemy actual destination.
	 * 
	 * @param destination is new player destination
	 */
	public void setEnemyActualDestination(final Destination destination)
	{
		this.getGameSpace().getEnemyBomberman().setEnemyDestination(destination);
	}
	
	/**
	 * Method used to set actual Enemy Position Vertex.
	 * 
	 * @param positionVertex is new Enemy position vertex
	 */
	public void setEnemyActualPosition(final Vertex positionVertex)
	{
		this.getGameSpace().getEnemyPosition().setPositionVertex(positionVertex);
	}
	
	/**
	 * Method used to set actual Enemy destination vertex.
	 * 
	 * @param destinationVertex is new Enemy destination vertex
	 */
	public void setEnemyActualDestinationVertex(final Vertex destinationVertex)
	{
		this.getGameSpace().getEnemyPosition().setDestinationVertex(destinationVertex);
	}
	
	/**
	 * Method used to check if Player changed destination.
	 * 
	 * @return true if player changed
	 */
	public boolean isPlayerChangedDestination()
	{
		return this.getGameSpace().getPlayerBomberman().isChangeDestination();
	}
	
	/**
	 * Method used to set Player change destination
	 * 
	 * @param changeDestination is changeDestination value
	 */
	public void setPlayerChangeDestination(final boolean changeDestination)
	{
		this.getGameSpace().getPlayerBomberman().setChangeDestination(changeDestination);
		
	}
	
	/**
	 * Method used to check if Enemy changed destination.
	 * 
	 * @return true if enemy changed
	 */
	public boolean isEnemyChangedDestination()
	{
		return this.getGameSpace().getEnemyBomberman().isChangeDestination();
	}
	
	/**
	 * Method used to set Enemy change destination
	 * 
	 * @param changeDestination is changeDestination value
	 */
	public void setEnemyChangeDestination(final boolean changeDestination)
	{
		this.getGameSpace().getEnemyBomberman().setChangeDestination(changeDestination);
		
	}
	
	/**
	 * Method used to get Player Data
	 * 
	 * @return player data
	 */
	public Player getPlayerData()
	{
		return this.getGameSpace().getPlayerBomberman();
	}
	
	/**
	 * Method used to get Enemy Data
	 * 
	 * @return enemy data
	 */
	public Enemy getEnemyData()
	{
		return this.getGameSpace().getEnemyBomberman();
	}
	
	/**
	 * Method used to get Player position
	 * 
	 * @return player position
	 */
	public PositionDynamic getPlayerPosition()
	{
		return this.getGameSpace().getPlayerPosition();
	}
	
	/**
	 * Method used to get Enemy position
	 * 
	 * @return enemy position
	 */
	public PositionDynamic getEnemyPosition()
	{
		return this.getGameSpace().getEnemyPosition();
	}
	
	/**
	 * Method used to get Player position Edge
	 * 
	 * @param first vertex of Edge
	 * @param second vertex of Edge
	 * @return Edge
	 */
	public Edge getPlayerPositionEdge(final Vertex first, final Vertex second)
	{
		return this.getGameSpace().getMoveGraph().findEdge(first,second);
	}
	
	/**
	 * Method used to get Enemy position Edge
	 * 
	 * @param first vertex of Edge
	 * @param second vertex of Edge
	 * @return Edge
	 */
	public Edge getEnemyPositionEdge(final Vertex first,final Vertex second)
	{
		return this.getGameSpace().getMoveGraph().findEdge(first,second);
	}
	
	/**
	 * Method used to update Player data.
	 * 
	 * @param player is new player data
	 * @param playerPosition is new player position
	 */
	public void updatePlayerData(final Player player,final PositionDynamic playerPosition)
	{
		this.getGameSpace().setPlayerBomberman(player);
		this.getGameSpace().setPlayerPosition(playerPosition);
	}
	
	/**
	 * Method used to update Enemy data.
	 * 
	 * @param enemy is new enemy data
	 * @param enemyPosition is new enemy position
	 */
	public void updateEnemyData(final Enemy enemy,final PositionDynamic enemyPosition)
	{
		this.getGameSpace().setEnemyBomberman(enemy);
		this.getGameSpace().setEnemyPosition(enemyPosition);
	}
	
	/** Bomb and Explosion API */
	
	/**
	 * Method used to check if Player has bomb to plant
	 * 
	 * @return true if it has.
	 */
	public boolean isPlayerBombToPlant()
	{
		return this.getGameSpace().getPlayerBomberman().getBombNumber()!=0;

	}
	
	/**
	 * Method used to check if Enemy has bomb to plant
	 * 
	 * @return true if it has.
	 */
	public boolean isEnemyBombToPlant()
	{
		return this.getGameSpace().getEnemyBomberman().getBombNumber()!=0;

	}
	
	/**
	 * Method used to check if Player is waiting for Bomb return.
	 * 
	 * @return true it is
	 */
	public boolean isPlayerWaitig()
	{
		return this.getGameSpace().getPlayerBomberman().isPlayerWaitingForBomb();
	}
	
	/**
	 * Method used to check if Enemy is waiting for Bomb return.
	 * 
	 * @return true it is
	 */
	public boolean isEnemyWaitig()
	{
		return this.getGameSpace().getEnemyBomberman().isEnemyWaitingForBomb();
	}
	
	/**
	 * Method used to set that Player is waiting for Bomb return.
	 * 
	 * @param waiting or not 
	 */
	public void setPlayerWaiting(boolean waiting)
	{
		this.getGameSpace().getPlayerBomberman().setPlayerWaitingForBomb(waiting);
	}
	
	/**
	 * Method used to set that Enemy is waiting for Bomb return.
	 * 
	 * @param waiting or not 
	 */
	public void setEnemyWaiting(boolean waiting)
	{
		this.getGameSpace().getEnemyBomberman().setEnemyWaitingForBomb(waiting);
	}
	
	/**
	 * Method used to increase Player Bomb Number.
	 */
	public void increasePlayerBombNumber()
	{
		this.getGameSpace().getPlayerBomberman().takeBombPowerUp();
	}
	
	/**
	 * Method used to increase Enemy Bomb Number.
	 */
	public void increaseEnemyBombNumber()
	{
		this.getGameSpace().getEnemyBomberman().takeBombPowerUp();
	}
	
	/**
	 * Method used to decrease Player Bomb Number.
	 */
	public void decreasePlayerBombNumber()
	{
		this.getGameSpace().getPlayerBomberman().plantBomb();
	}
	
	
	/**
	 * Method used to decrease Enemy Bomb Number.
	 */
	public void decreaseEnemyBombNumber()
	{
		this.getGameSpace().getEnemyBomberman().plantBomb();
	}
	
	/**
	 * Method used to increase GameBoard Bomb Number.
	 */
	public void increaseGameSpaceBombNumber()
	{
		int i = this.getGameSpace().getBombNumber();
		this.getGameSpace().setBombNumber(i+1);
		
	}
	
	/**
	 * Method used to decrease GameBoard Bomb Number.
	 */
	public void decreaseGameSpaceBombNumber()
	{
		int i = this.getGameSpace().getBombNumber();
		this.getGameSpace().setBombNumber(i-1);
	}
	
	/**
	 * Method used to activate Vertex.
	 * 
	 * @param vertex is Vertex to activate.
	 */
	public void activateVertexState(final Vertex vertex)
	{
		this.getGameSpace().getMoveGraph().getVertexArray()[vertex.getVertexId()].setStateActive(true);
	}
	
	/**
	 * Method used to !activate Vertex.
	 * 
	 * @param vertex is Vertex to activate.
	 */
	public void disactivateVertexState(final Vertex vertex)
	{
		this.getGameSpace().getMoveGraph().getVertexArray()[vertex.getVertexId()].setStateActive(false);
	}
	
	/**
	 * Method used to get Bomb Position Array
	 * 
	 * @return bomb position array
	 */
	public PositionStatic[] getBombPositionArray()
	{
		return this.getGameSpace().getBombsPositions();
	}
	
	/**
	 * Method used to Bomb Array
	 * 
	 * @return bomb array
	 */
	public Bomb[] getBombArray()
	{
		return this.getGameSpace().getBombsOnBoard();
	}
	
	/**
	 * Method used to get Player Bomb Explosion Level 
	 * 	 
	 * @return player bomb explosion level
	 */
	public int getPlayerBombExplosionLevel()
	{
		return this.getGameSpace().getPlayerBomberman().getExplosionLevel();
	}
	
	/**
	 * Method used to get Enemy Bomb Explosion Level 	
	 *  
	 * @return enemy bomb explosion level
	 */
	public int getEnemyBombExplosionLevel()
	{
		return this.getGameSpace().getEnemyBomberman().getExplosionLevel();
	}
	
	/**
	 * Method used to update Bomb Data
	 * 
	 * @param bombPositionArray new bomb position array
	 * @param bombArray new bomb array
	 */
	public void updateBombData(final PositionStatic[] bombPositionArray,final Bomb[] bombArray)
	{
		this.getGameSpace().setBombsPositions(bombPositionArray);
		this.getGameSpace().setBombsOnBoard(bombArray);
	}
	
	/**
	 * Method used to get Explosion position array
	 * 
	 * @return explosion position array
	 */
	public PositionStatic[] getExplosionPositionArray()
	{
		return this.getGameSpace().getExplosionsPositions();
	}
	
	/**
	 * Method used to get Explosion Array
	 * 
	 * @return explosion array
	 */
	public Explosion[] getExplosionArray()
	{
		return this.getGameSpace().getExplosionOnBoard();
	}
	
	/**
	 * Method used to update Explosion Data.
	 * 
	 * @param explosionPositionArray is new explosion position array
	 * @param explosionArray is new explosion array.
	 */
	public void updateExplosionData(final PositionStatic[] explosionPositionArray, final Explosion[] explosionArray)
	{
		this.getGameSpace().setExplosionsPositions(explosionPositionArray);
		this.getGameSpace().setExplosionOnBoard(explosionArray);
		
	}
	
	/**
	 * Method used to update explosion range data.
	 * 
	 * @param i is index of explosion
	 * @param explosionVertex is explosion range vertex list
	 */
	public void updateExplosionRangeData(final int i,final LinkedList<Vertex> explosionVertex)
	{
		this.getGameSpace().getExplosionOnBoard()[i].setExplosionVertex(explosionVertex);
		
	}
	
	/**
	 * Method used to increase explosion number.
	 */
	public void increaseExposionNumber()
	{
		int i = this.getGameSpace().getExplosionNumber();
		this.getGameSpace().setExplosionNumber(i+1);
	}
	
	/**
	 * Method used to decrease explosion number.
	 */
	public void decreaseExplosionNumber()
	{
		int i = this.getGameSpace().getExplosionNumber();
		this.getGameSpace().setExplosionNumber(i-1);
		
	}
	
	/**
	 * Method used to get Explosion number.
	 * 
	 * @return explosion number.
	 */
	public int getExplosionNumber()
	{
		return this.getGameSpace().getExplosionNumber();
	}
	
	/** Power Up API */
	
	/**
	 * Method used to get Bomb power up position array.
	 * 
	 * @return Bomb power up position array.
	 */
	public PositionStatic[] getBombPowerUpPosition()
	{
		return this.getGameSpace().getBombPowerUpPositions();
	}
	
	/**
	 * Method used to get Speed power up position array.
	 * 
	 * @return Speed power up position array.
	 */
	public PositionStatic[] getSpeedPowerUpPosition()
	{
		return this.getGameSpace().getSpeedPowerUpPositions();
	}
	
	/**
	 * Method used to get Explosion power up position array.
	 * 
	 * @return Explosion power up position array.
	 */
	public PositionStatic[] getExplosionPowerUpPosition()
	{
		return this.getGameSpace().getExplosionPowerUpPositions();
	}
	
	/**
	 * Method used to update Bomb power up position array.
	 */
	public void updateBombPowerUpPosition(final PositionStatic[] powerUpArray)
	{
		this.getGameSpace().setBombPowerUpPositions(powerUpArray);
	}
	
	/**
	 * Method used to update Speed power up position array.
	 */
	public void updateSpeedPowerUpPosition(final PositionStatic[] powerUpArray)
	{
		this.getGameSpace().setSpeedPowerUpPositions(powerUpArray);
	}
	
	/**
	 * Method used to update Explosion power up position array.

	 */
	public void updateExplosionPowerUpPosition(final PositionStatic[] powerUpArray)
	{
		this.getGameSpace().setExplosionPowerUpPositions(powerUpArray);
	}
	
	/**
	 * Method used to get bomb power up number.
	 * 
	 * @return bomb power up number.
	 */
	public int getBombPowerUpNumber()
	{
		return this.getGameSpace().getBombPowerUpNumber();
	}
	
	/**
	 * Method used to get speed power up number.
	 * 
	 * @return speed power up number.
	 */
	public int getSpeedPowerUpNumber()
	{
		return this.getGameSpace().getSpeedPowerUpNumber();
	
	}
	
	/**
	 * Method used to get explosion power up number.
	 * 
	 * @return explosion power up number.
	 */
	public int getExplosionPowerUpNumber()
	{
		return this.getGameSpace().getExplosionPowerUpNumber();
	}
	
	/**
	 * Method used to increase Bomb power Up number
	 */
	public void increaseBombPowerUp()
	{
		int i = this.getGameSpace().getBombPowerUpNumber();
		this.getGameSpace().setBombPowerUpNumber(i+1);
	}
	
	/**
	 * Method used to increase Speed power Up number
	 */
	public void increaseSpeedPowerUp()
	{
		int i = this.getGameSpace().getSpeedPowerUpNumber();
		this.getGameSpace().setSpeedPowerUpNumber(i+1);
	}
	
	/**
	 * Method used to increase Explosion power Up number
	 */
	public void increaseExplosionPowerUp()
	{
		int i = this.getGameSpace().getExplosionPowerUpNumber();
		this.getGameSpace().setExplosionPowerUpNumber(i+1);
	}
	
	/**
	 * Method used to decrease Bomb power Up number
	 */
	public void decreaseBombPowerUp()
	{
		int i = this.getGameSpace().getBombPowerUpNumber();
		this.getGameSpace().setBombPowerUpNumber(i-1);
	}
	
	/**
	 * Method used to decrease Speed power Up number
	 */
	public void decreaseSpeedPowerUp()
	{
		int i = this.getGameSpace().getSpeedPowerUpNumber();
		this.getGameSpace().setSpeedPowerUpNumber(i-1);
	}
	
	/**
	 * Method used to decrease Explosion power Up number
	 */
	public void decreaseExplosionPowerUp()
	{
		int i = this.getGameSpace().getExplosionPowerUpNumber();
		this.getGameSpace().setExplosionPowerUpNumber(i-1);
	}

	/**
	 * @return the gameCore
	 */
	private GameSpace getGameSpace()
	{
		return gameSpace;
	}

	/**
	 * @param collisionDetector the collisionDetector to set
	 */
	public void setCollisionDetector(CollisionDetector collisionDetector)
	{
		this.collisionDetector = collisionDetector;
	}

	/**
	 * @return the collisionDetector
	 */
	public CollisionDetector getCollisionDetector()
	{
		return collisionDetector;
	}	
}
