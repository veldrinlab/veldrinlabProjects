package pl.edu.pw.elka.home.sjablon1.model;

/**
 * Class represents the most important object in GameSpace: object of Player Bombeman
 * that user can control.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class Player extends Bomberman implements Playerable
{
	/** Moving state of Player */
	private BombermanMoveState playerState;
	/** Destination which Player is directed */
	private Destination playerDestination;
	/** If Player changes destination while moving on Edge*/
	private boolean changeDestination;
	/** If player planted Bomb and waiting for return */
	private boolean isPlayerWaitingForBomb;
	
	
	
	/**
	 * Default constructor of Player object. 
	 */
	public Player()
	{
		this.setBombNumber(1);
		this.setExplosionLevel(1);
		this.setSpeedLevel(1);
		this.setPlayerState(BombermanMoveState.vertex);
		this.setPlayerDestination(Destination.Down);
		this.setChangeDestination(false);
		this.setPlayerWaitingForBomb(false);
	}

	@Override
	/**
	 * Method defines what happen when Player plant a Bomb.
	 */
	public void plantBomb()
	{
		if(this.bombNumber!=0)
			this.bombNumber = this.bombNumber - 1;
	}

	@Override
	/**
	 * Method defines what happen when Player took the BombPowerUp
	 */
	public void takeBombPowerUp()
	{
		this.bombNumber = this.bombNumber + 1;
		
	}

	@Override
	/**
	 * Method defines what happen when Player took the ExplosionPowerUp
	 */
	public void takeExplosionPowerUp()
	{
		this.explosionLevel = this.explosionLevel + 1;
		
	}
	/**
	 * Method defines what happen when Player took the SpeedPowerUp
	 */
	@Override
	public void takeSpeedPowerUp()
	{
		this.speedLevel = this.speedLevel + 1;
		
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
	 * @param speedLevel the speedLevel to set
	 */
	public void setSpeedLevel(final int speedLevel)
	{
		this.speedLevel = speedLevel;
	}

	/**
	 * @return the speedLevel
	 */
	public int getSpeedLevel()
	{
		return speedLevel;
	}
	/**
	 * @param explosionLevel the explosionLevel to set
	 */
	public void setExplosionLevel(final int explosionLevel)
	{
		this.explosionLevel = explosionLevel;
	}

	/**
	 * @return the explosionLevel
	 */
	public int getExplosionLevel()
	{
		return explosionLevel;
	}
	
	/**
	 * @param playerState the playerState to set
	 */
	public void setPlayerState(final BombermanMoveState playerState)
	{
		this.playerState = playerState;
	}

	/**
	 * @return the playerState
	 */
	public BombermanMoveState getPlayerState()
	{
		return playerState;
	}

	/**
	 * @param playerDestination the playerDestination to set
	 */
	public void setPlayerDestination(final Destination playerDestination)
	{
		this.playerDestination = playerDestination;
	}

	/**
	 * @return the playerDestination
	 */
	public Destination getPlayerDestination()
	{
		return playerDestination;
	}

	/**
	 * @param changeDestination the changeDestination to set
	 */
	public void setChangeDestination(final boolean changeDestination)
	{
		this.changeDestination = changeDestination;
	}

	/**
	 * @return the changeDestination
	 */
	public boolean isChangeDestination()
	{
		return changeDestination;
	}

	/**
	 * @param isPlayerWaitingForBomb the isPlayerWaitingForBomb to set
	 */
	public void setPlayerWaitingForBomb(boolean isPlayerWaitingForBomb)
	{
		this.isPlayerWaitingForBomb = isPlayerWaitingForBomb;
	}

	/**
	 * @return the isPlayerWaitingForBomb
	 */
	public boolean isPlayerWaitingForBomb()
	{
		return isPlayerWaitingForBomb;
	}
}
