package pl.edu.pw.elka.home.sjablon1.model;

/**
 * Class represents Player with PowerUp collision object. Object of class contains information
 * about collision for Controller Unit.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class PlayerPowerUpCollision
{
	/** Player actual position vertex */
	private Vertex playerVertex;
	/** PowerUp index in powerUpArray*/
	private int powerUpIndex;
	/** PowerUp id */
	private int powerUpId;
	
	/**
	 * Default constructor of PlayerPowerUpCollsion object.
	 * 
	 * @param playerVertex is player position
	 * @param powerUpIndex is powerUp index in array
	 * @param powerUpId is type of powerUp  
	 */
	public PlayerPowerUpCollision(Vertex playerVertex, int powerUpIndex, int powerUpId)
	{
		this.setPlayerVertex(playerVertex);
		this.setPowerUpId(powerUpId);
		this.setPowerUpIndex(powerUpIndex);	
	}
	
	/**
	 * @param playerVertex the playerVertex to set
	 */
	public void setPlayerVertex(Vertex playerVertex)
	{
		this.playerVertex = playerVertex;
	}
	/**
	 * @return the playerVertex
	 */
	public Vertex getPlayerVertex()
	{
		return playerVertex;
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
