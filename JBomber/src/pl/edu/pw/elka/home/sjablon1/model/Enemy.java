package pl.edu.pw.elka.home.sjablon1.model;

/**
 * Class that represents second of the most important objects in GameSpace: 
 * object of Enemy Bombeman that User or computer can control.
 * @author Szymon Jablonski
 * @version 1.0
 */

public class Enemy extends Bomberman implements Playerable
{
	/** Moving state of Enemy */
	private BombermanMoveState enemyState;
	/** Destination which Enemy is directed */
	private Destination enemyDestination;
	/** If Enemy changes destination while moving on Edge*/
	private boolean changeDestination;
	/** If enemy planted Bomb and waiting for return */
	private boolean isEnemyWaitingForBomb;
	
	/**
	 * Default constructor of Player object. 
	 */
	public Enemy()
	{
		this.setBombNumber(1);
		this.setExplosionLevel(1);
		this.setSpeedLevel(1);
		this.setEnemyDestination(Destination.Down);
		this.setEnemyState(BombermanMoveState.vertex);
		this.setChangeDestination(false);
		this.setEnemyWaitingForBomb(false);
	}

	@Override
	/**
	 * Method defines what happen when Enemy plant a Bomb.
	 */
	public void plantBomb()
	{
		if(this.bombNumber!=0)
			this.bombNumber = this.bombNumber - 1;
	}

	@Override
	/**
	 * Method defines what happen when Enemy took the BombPowerUp
	 */
	public void takeBombPowerUp()
	{
		this.bombNumber = this.bombNumber + 1;
		
	}

	@Override
	/**
	 * Method defines what happen when Enemy took the ExplosionPowerUp
	 */
	public void takeExplosionPowerUp()
	{
		this.explosionLevel = this.explosionLevel + 1;
		
	}
	/**
	 * Method defines what happen when Enemy took the SpeedPowerUp
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
	 * @param enemyDestination the enemyDestination to set
	 */
	public void setEnemyDestination(final Destination enemyDestination)
	{
		this.enemyDestination = enemyDestination;
	}

	/**
	 * @return the enemyDestination
	 */
	public Destination getEnemyDestination()
	{
		return enemyDestination;
	}
	

	/**
	 * @param enemyState the enemyState to set
	 */
	public void setEnemyState(final BombermanMoveState enemyState)
	{
		this.enemyState = enemyState;
	}

	/**
	 * @return the enemyState
	 */
	public BombermanMoveState getEnemyState()
	{
		return enemyState;
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
	 * @param isEnemyWaitingForBomb the isEnemyWaitingForBomb to set
	 */
	public void setEnemyWaitingForBomb(boolean isEnemyWaitingForBomb)
	{
		this.isEnemyWaitingForBomb = isEnemyWaitingForBomb;
	}

	/**
	 * @return the isEnemyWaitingForBomb
	 */
	public boolean isEnemyWaitingForBomb()
	{
		return isEnemyWaitingForBomb;
	}
}
