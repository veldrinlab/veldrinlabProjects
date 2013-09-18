package pl.edu.pw.elka.home.sjablon1.model;

/**
 * Class represents Enemy with PowerUp collision object. Object of class contains information
 * about collision for Controller Unit.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class EnemyPowerUpCollision
{
	/** Enemy actual position vertex */
	private Vertex EnemyVertex;
	/** PowerUp index in powerUpArray*/
	private int powerUpIndex;
	/** PowerUp id */
	private int powerUpId;
	
	/**
	 * Default constructor of EnemyPowerUpCollsion object.
	 * 
	 * @param EnemyVertex is Enemy position
	 * @param powerUpIndex is powerUp index in array
	 * @param powerUpId is type of powerUp  
	 */
	public EnemyPowerUpCollision(Vertex EnemyVertex, int powerUpIndex, int powerUpId)
	{
		this.setEnemyVertex(EnemyVertex);
		this.setPowerUpId(powerUpId);
		this.setPowerUpIndex(powerUpIndex);	
	}
	
	/**
	 * @param EnemyVertex the EnemyVertex to set
	 */
	public void setEnemyVertex(Vertex EnemyVertex)
	{
		this.EnemyVertex = EnemyVertex;
	}
	/**
	 * @return the EnemyVertex
	 */
	public Vertex getEnemyVertex()
	{
		return EnemyVertex;
	}
	/**
	 * @param powerUpIndex the powerUpIndex to set
	 */
	public void setPowerUpIndex(int powerUpIndex)
	{
		this.powerUpIndex = powerUpIndex;
	}
	/**
	 * @return the powerUpIndex
	 */
	public int getPowerUpIndex()
	{
		return powerUpIndex;
	}
	/**
	 * @param powerUpId the powerUpId to set
	 */
	public void setPowerUpId(int powerUpId)
	{
		this.powerUpId = powerUpId;
	}
	/**
	 * @return the powerUpId
	 */
	public int getPowerUpId()
	{
		return powerUpId;
	}
}