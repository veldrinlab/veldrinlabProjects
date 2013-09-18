package pl.edu.pw.elka.home.sjablon1.model;

/**
 * Class defines BombPowerUp object. When Bomberman takes it, it increase his bombNumber.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class BombPowerUp extends PowerUp
{
	/**
	 * Constructor for BombPowerUp object. PowerUpLevel is random. Default is 1.
	 */
	public BombPowerUp()
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
