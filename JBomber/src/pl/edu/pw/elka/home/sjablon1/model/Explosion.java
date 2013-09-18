package pl.edu.pw.elka.home.sjablon1.model;

import java.util.LinkedList;

/**
 * Class defines object of Explosion witch is generate by blowing Bomb. Explosion
 * is very import object because it cause Collision with BrickTile, Bombeman and PowerUp
 * objects.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class Explosion
{
	/** Explosion power level */
	private int explosionPower;
	/** State in witch is Explosion object */
	private ExplosionState explosionState;
	/** Vector of explosionRange Vertex, without Explosion center */
	private LinkedList<Vertex> explosionVertex;

	
	/**
	 * Default constructor of Explosion object.
	 * 
	 * @param explosionPower is Explosion power level
	 * @param explosionState is first ExplosionState
	 */
	public Explosion(final int explosionPower,final ExplosionState explosionState)
	{
		this.explosionPower = explosionPower;
		this.explosionState = explosionState;
		this.explosionVertex = null;
		
	}

	/**
	 * @param explosionState the explosionState to set
	 */
	public void setExplosionState(final ExplosionState explosionState)
	{
		this.explosionState = explosionState;
	}

	/**
	 * @return the explosionState
	 */
	public ExplosionState getExplosionState()
	{
		return explosionState;
	}

	/**
	 * @param explosionPower the explosionPower to set
	 */
	public void setExplosionPower(final int explosionPower)
	{
		this.explosionPower = explosionPower;
	}

	/**
	 * @return the explosionPower
	 */
	public int getExplosionPower()
	{
		return explosionPower;
	}

	/**
	 * @param explosionVertex the explosionVertex to set
	 */
	public void setExplosionVertex(final LinkedList<Vertex> explosionVertex)
	{
		this.explosionVertex = explosionVertex;
	}

	/**
	 * @return the explosionVertex
	 */
	public LinkedList<Vertex> getExplosionVertex()
	{
		return explosionVertex;
	}
}
