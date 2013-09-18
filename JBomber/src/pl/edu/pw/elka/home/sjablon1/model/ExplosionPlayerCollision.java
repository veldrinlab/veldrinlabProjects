package pl.edu.pw.elka.home.sjablon1.model;

/**
 * Class represents Explosion with Player collision object. Object of class contains information
 * about collision for Controller Unit.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class ExplosionPlayerCollision
{
	/** Vertex of Player*/
	private Vertex collisionVertex;
	
	/**
	 * Default constructor of ExplosionPlayerCollision object
	 * 
	 * @param collisonVertex is Player vertex
	 */
	public ExplosionPlayerCollision(Vertex collisonVertex)
	{
		this.setCollisionVertex(collisonVertex);
	}

	/**
	 * @param collisionVertex the collisionVertex to set
	 */
	public void setCollisionVertex(Vertex collisionVertex)
	{
		this.collisionVertex = collisionVertex;
	}

	/**
	 * @return the collisionVertex
	 */
	public Vertex getCollisionVertex()
	{
		return collisionVertex;
	}
	
}