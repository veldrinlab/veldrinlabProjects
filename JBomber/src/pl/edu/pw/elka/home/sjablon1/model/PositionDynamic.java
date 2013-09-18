package pl.edu.pw.elka.home.sjablon1.model;

/**
 * Class represents Position of dynamic object in GameSpace, object that can be on Vertex
 * or Edge like Player and Enemy.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class PositionDynamic extends Position
{
	/**The Edge on witch actually is object*/
	private Edge positionEdge;
	/**The Vertex on witch actually is object*/
	private Vertex positionVertex;
	/** The Vertex that is actual destination of object in Edge */
	private Vertex destinationVertex;
	
	/**
	 * Constructor for dynamic object Player and Enemy.
	 * 
	 * @param positionEdge is Edge on witch Bomberman is moving.
	 * @param positionVertex is Vertex on witch Bomberman is staying.
	 * @param destinationVertex is destination Vertex Bombeman is reaching.
	 */
	public PositionDynamic(final Edge positionEdge,final Vertex positionVertex,final Vertex destinationVertex)
	{
		this.setPositionEdge(positionEdge);
		this.setPositionVertex(positionVertex);
		this.setDestinationVertex(destinationVertex);
	}
	
	/**
	 * @param positionEdge the positionEdge to set
	 */
	public void setPositionEdge(final Edge positionEdge)
	{
		this.positionEdge = positionEdge;
	}
	
	/**
	 * @return the positionEdge
	 */
	public Edge getPositionEdge()
	{
		return positionEdge;
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

	/**
	 * @param destinationVertex the destinationVertex to set
	 */
	public void setDestinationVertex(final Vertex destinationVertex)
	{
		this.destinationVertex = destinationVertex;
	}

	/**
	 * @return the destinationVertex
	 */
	public Vertex getDestinationVertex()
	{
		return destinationVertex;
	}

}
