package pl.edu.pw.elka.home.sjablon1.model;

/**
 * Class represents Explosion with Brick collision object. Object of class contains information
 * about collision for Controller Unit.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class ExplosionBrickCollision
{
	/** Vertex of Brick*/
	private Vertex collisionVertex;
	
	/**
	 * Default constructor of ExplosionBrickCollision object
	 * 
	 * @param collisonVertex is brick vertex
	 */
	public ExplosionBrickCollision(Vertex collisonVertex)
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
