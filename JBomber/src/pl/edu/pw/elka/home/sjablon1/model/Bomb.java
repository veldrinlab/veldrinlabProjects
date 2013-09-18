package pl.edu.pw.elka.home.sjablon1.model;

/**
 * Class represents the only weapon that can use Bomberman - the Bomb. Bomb can
 * be Plant by Bomberman, they can be plant only on Vertexes so information about
 * current Bomb position contains PositionStatic class.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class Bomb
{
	/** Power of Bomb explosion level */
	private int bombExplosionPower;
	/** State in witch is Bomb before explosion */
	private BombExploadingState bombState;
	
	/**
	 * Bomb is simple object. It can only blow. It creates explosion depends on
	 * power of bomb.
	 * 
	 * @param bombPower is Bomb Explosion power level
	 * @param bombState is first BombExlopadingState
	 */
	public Bomb(final int bombPower,final BombExploadingState bombState)
	{
		this.bombExplosionPower = bombPower;
		this.bombState = bombState;
		
	}
	
	/**
	 * @param bombExplosionPower the bombExplosionPower to set
	 */
	public void setBombExplosionPower(final int bombExplosionPower)
	{
		this.bombExplosionPower = bombExplosionPower;
	}

	/**
	 * @return the bombExplosionPower
	 */
	public int getBombExplosionPower()
	{
		return bombExplosionPower;
	}

	/**
	 * @param bombState the bombState to set
	 */
	public void setBombState(final BombExploadingState bombState)
	{
		this.bombState = bombState;
	}

	/**
	 * @return the bombState
	 */
	public BombExploadingState getBombState()
	{
		return bombState;
	}
}
