package pl.edu.pw.elka.home.sjablon1.model;

/**
 * Class represents basic part of graph class, connection between two Vertexes - the Edge.
 * @author Szymon Jablonski
 * @version 1.o
 */
public class Edge
{
	/** Object of first Vertex of Edge */
	private Vertex vertexFirst;
	/** Object of second Vertex of Edge */
	private Vertex vertexSecond;
	
	/**
	 * Constructor of typical Edge object. 
	 * 
	 * @param vertexFirst is first vertex of Edge
	 * @param vertexSecond is second Vertex of Edge
	 */
	public Edge(final Vertex vertexFirst,final Vertex vertexSecond)
	{
		this.setVertexFirst(vertexFirst);
		this.setVertexSecond(vertexSecond);
	}
	
	/**
	 * @param vertexFirst the vertexFirst to set
	 */
	public void setVertexFirst(final Vertex vertexFirst)
	{
		this.vertexFirst = vertexFirst;
	}

	/**
	 * @return the vertexFirst
	 */
	public Vertex getVertexFirst()
	{
		return vertexFirst;
	}

	/**
	 * @param vertexSecond the vertexSecond to set
	 */
	public void setVertexSecond(final Vertex vertexSecond)
	{
		this.vertexSecond = vertexSecond;
	}

	/**
	 * @return the vertexSecond
	 */
	public Vertex getVertexSecond()
	{
		return vertexSecond;
	}
}
