package pl.edu.pw.elka.home.sjablon1.model;

/**
 * Class represents basic part of graph class - the vertex. 
 * @author Szymon Jablonski
 * @version 1.0
 */
public class Vertex 
{
	/** Vertex unique id */
	private int vertexId;
	/** Vertex state */
	private boolean stateActive;
	/** Left neighbor of Vertex */
	private Vertex leftDestination;
	/** Right neighbor of Vertex */
	private Vertex rightDestination;
	/** Up neighbor of Vertex */
	private Vertex upDestination;
	/** Down neighbor of Vertex */
	private Vertex downDestination;
	
	/**
	 * Default constructor of Vertex object.
	 */
	public Vertex()
	{
		
	}
	
	/**
	 * Constructor of Vertex object that takes new VertexID as a parameter.
	 * 
	 * @param VertexId is new objects VertexID
	 */
	public Vertex(final int VertexId)
	{
		this.setVertexId(VertexId);
	}
	
	/**
	 * Most typical constructor of Vertex that takes two parameters
	 * 
	 * @param VertexId new objects VertexID
	 * @param state of new Vertex
	 */
	public Vertex(final int VertexId,final boolean state)
	{
		this.setVertexId(VertexId);
		this.setStateActive(state);
	}
	
	/**
	 * @param vertexId the vertexId to set
	 */
	public void setVertexId(final int vertexId)
	{
		this.vertexId = vertexId;
	}

	/**
	 * @return the vertexId
	 */
	public int getVertexId()
	{
		return vertexId;
	}
	
	/**
	 * @param stateActive the stateActive to set
	 */
	public void setStateActive(final boolean stateActive)
	{
		this.stateActive = stateActive;
	}

	/**
	 * @return the stateActive
	 */
	public boolean isStateActive()
	{
		return stateActive;
	}
	
	/**
	 * @param leftDestination the leftDestination to set
	 */
	public void setLeftDestination(final Vertex leftDestination)
	{
		this.leftDestination = leftDestination;
	}

	/**
	 * @return the leftDestination
	 */
	public Vertex getLeftDestination()
	{
		return leftDestination;
	}
	
	/**
	 * @param rightDestination the rightDestination to set
	 */
	public void setRightDestination(final Vertex rightDestination)
	{
		this.rightDestination = rightDestination;
	}

	/**
	 * @return the rightDestination
	 */
	public Vertex getRightDestination()
	{
		return rightDestination;
	}

	/**
	 * @param upDestination the upDestination to set
	 */
	public void setUpDestination(final Vertex upDestination)
	{
		this.upDestination = upDestination;
	}

	/**
	 * @return the upDestination
	 */
	public Vertex getUpDestination()
	{
		return upDestination;
	}

	/**
	 * @param downDestination the downDestination to set
	 */
	public void setDownDestination(final Vertex downDestination)
	{
		this.downDestination = downDestination;
	}

	/**
	 * @return the downDestination
	 */
	public Vertex getDownDestination()
	{
		return downDestination;
	}
}
