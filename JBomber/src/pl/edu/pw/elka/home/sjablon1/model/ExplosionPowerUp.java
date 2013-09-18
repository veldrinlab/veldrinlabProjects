package pl.edu.pw.elka.home.sjablon1.model;

/**
 * Class defines SpeedPowerUp object. When Bomberman takes it, it randomly increase
 * or decrease his explosionLevel.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class ExplosionPowerUp extends PowerUp
{
	/**
	 * Constructor for SpeddPowerUp object. PowerUpLevel is random. Default and 
	 * minimum amount is 1.
	 */
	public ExplosionPowerUp()
	{
		int randomPowerUpLevel = 1;
		this.setPowerUpLevel(randomPowerUpLevel);
		
	}
	
	/**
	 * @param powerUpLevel the powerUpLevel to set
	 */
	public void setPowerUpLevel(final int powerUpLevel)
	{
		this.powerUpLevel = powerUpLevel;
	}
	
	/**
	 * @return the powerUpLevel
	 */
	public int getPowerUpLevel()
	{
		return powerUpLevel;
	}

}