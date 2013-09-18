package pl.edu.pw.elka.home.sjablon1.model;

/**
 * Class represents Position of static object in GameSpace, object that only can be on Vertex
 * like PowerUp, Bomb, Explosion.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class PositionStatic extends Position
{
	/** Vertex of object position */
	private Vertex positionVertex;
	
	/**
	 * Constructor for objects like Player/Enemy, Bomb, Explosion and Upgrade
	 * 
	 * @param positionVertex reference to Vertex on witch is object
	 */
	public PositionStatic(final Vertex positionVertex)
	{
		this.setPositionVertex(positionVertex);
	}
	
	/**
	 * @param positionVertex the positionVertex to set
	 */
	public void setPositionVertex(final Vertex positionVertex)
	{
		this.positionVertex = positionVertex;
	}
	
	/**
	 * @return the positionVertex
	 */
	public Vertex getPositionVertex()
	{
		return positionVertex;
	}
}
