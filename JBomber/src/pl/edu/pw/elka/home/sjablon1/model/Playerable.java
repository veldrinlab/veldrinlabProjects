package pl.edu.pw.elka.home.sjablon1.model;

/**
 * Interface defines functionality of Player and Enemy. 
 * @author Szymon Jablonski
 * @version 1.0
 */
public interface Playerable
{	
	/**
	 * Method defines state of planting new Bomb by Bomberman.
	 */
	abstract public void plantBomb();
	
	/**
	 * Method defines state of taking BombPowerUp by Bomberman.
	 */
	abstract public void takeBombPowerUp();

	/**
	 * Method defines state of taking SpeedPowerUp by Bomberman.
	 */
	abstract public void takeSpeedPowerUp();

	/**
	 * Method defines state of taking ExplosionPowerUp by Bomberman.
	 */
	abstract public void takeExplosionPowerUp();
}
