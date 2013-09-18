package pl.edu.pw.elka.home.sjablon1.model;

/**
 * Class represents Game Space Graph - on which other objects like Player, Enemy, Bomb etc.
 * can stay and move on.
 * @author Szymon Jablonski
 * @version 1.0
 */

public class GameGraph
{
	/** Number of Vertex of GameGraph */
	private int vertexNumber;
	/** Number of Edge of GameGraph */
	private int edgeNumber;
	/** Array of Edge */
	private Edge[] edgeArray;
	/** Array of Vertex */
	private Vertex[] vertexArray;
	/** Array of graph adjancencyArray */
	private Vertex[][] graphAdjancencyArray;
	
	/**
	 * Constructor of Graph represents space on witch objects can move.
	 * 
	 * @param gameArena object having information about GameBoard structure
	 */
	public GameGraph(final GameBoard gameArena)
	{
		/**
		 * We can easy calculate maximum amount of Vertexes and Edges. Also it is 
		 * quite simple to build adjancencyAray because each Vertex can have max. 4
		 * neighbors.
		 */
		vertexNumber = 0;
		edgeNumber = 0;
		vertexArray = new Vertex[gameArena.getDimensionX()*gameArena.getDimensionY()];
		edgeArray = new Edge[4*vertexArray.length];

		/**
		 * Building graph from GameBoard Object information. 
		 */
		createVertexArray(gameArena);
		createEdgeArray(gameArena);
	}
	
	/**
	 * Method that creates vertexArray. One of three methods that we can use in
	 * Graph class constructor. 
	 * 
	 * @param gameArena is GameBoard logic structure
	 */
	private void createVertexArray(final GameBoard gameArena)
	{
		Tile[][] arenaStructure = gameArena.getBoardStructure();
		
		for(int j = 0; j<gameArena.getDimensionY(); j++)
		{
			for(int i = 0; i<gameArena.getDimensionX(); i++)
			{
				if(arenaStructure[i][j] instanceof BackgroundTile)
				{
					vertexArray[this.vertexNumber] = new Vertex(this.vertexNumber,true);
					vertexNumber++;
				}
				else if(arenaStructure[i][j] instanceof BrickTile)
				{
					vertexArray[this.vertexNumber] = new Vertex(this.vertexNumber,false);
					vertexNumber++;
				}
				else
					vertexNumber++;
			}
		}	
	}
	
	/**
	 * Method that creates edgeArray. One of three methods that we can use in
	 * Graph class constructor. 
	 * 
	 * @param gameArena is GameBoard logic structure
	 */
	private void createEdgeArray(final GameBoard gameArena)
	{
		for(int i = 0; i<this.vertexNumber; i++)
		{
			int edgeCounter = 0;
			if(vertexArray[i]!=null)
			{
				vertexArray[i].setUpDestination(vertexArray[i-gameArena.getDimensionX()]);
				if(vertexArray[i-gameArena.getDimensionX()]!=null)
					edgeArray[edgeCounter++]= new Edge(vertexArray[i],vertexArray[i-17]);
				
				vertexArray[i].setDownDestination(vertexArray[i+gameArena.getDimensionX()]);
				if(vertexArray[i+gameArena.getDimensionX()]!=null)
					edgeArray[edgeCounter++]= new Edge(vertexArray[i],vertexArray[i+gameArena.getDimensionX()]);
				
				vertexArray[i].setLeftDestination(vertexArray[i-1]);
				if(vertexArray[i-1]!=null)
					edgeArray[edgeCounter++]= new Edge(vertexArray[i],vertexArray[i-1]);
				
				vertexArray[i].setRightDestination(vertexArray[i+1]);
				if(vertexArray[i+1]!=null)
					edgeArray[edgeCounter++]= new Edge(vertexArray[i],vertexArray[i+1]);
			}
		}
	}
	
	/**
	 * Method that creates graphAdjancencyAray. One of three methods that we can use in
	 * Graph class constructor. 
	 */
	public void createGraphAdjancencyArray()
	{
		for(int i=0; i<this.vertexNumber; i++)
			graphAdjancencyArray[i][0] = vertexArray[i];
		
		for(int i = 0; i<this.vertexNumber; i++)
		{
			int j = 0;
			if(vertexArray[i].getDownDestination()!=null)
				graphAdjancencyArray[i][j++] = vertexArray[i].getDownDestination();
			if(vertexArray[i].getUpDestination()!=null)
				graphAdjancencyArray[i][j++] = vertexArray[i].getUpDestination();
			if(vertexArray[i].getLeftDestination()!=null)
				graphAdjancencyArray[i][j++] = vertexArray[i].getLeftDestination();
			if(vertexArray[i].getRightDestination()!=null)
				graphAdjancencyArray[i][j++] = vertexArray[i].getRightDestination();	
		}
		
	}
	
	/**
	 * Method that finds and return Edge contains two specified Vertexes.
	 * 
	 * @param vertexFirst is first vertex of searching Edge.
	 * @param vertexSecond is second vertex of searching Edge.
	 * @return searched Edge.
	 */
	public Edge findEdge(final Vertex vertexFirst,final Vertex vertexSecond)
	{
		for(int i = 0; i<this.edgeNumber; i++)
		{
			if(this.edgeArray[i].getVertexFirst().getVertexId() == vertexFirst.getVertexId()
				&& this.edgeArray[i].getVertexSecond().getVertexId() == vertexSecond.getVertexId())
				return edgeArray[i];
		}
		return null;
	}
	
	/**
	 * @param vertexNumber the vertexNumber to set
	 */
	public void setVertexNumber(final int vertexNumber)
	{
		this.vertexNumber = vertexNumber;
	}
	
	/**
	 * @return the vertexNumber
	 */
	public int getVertexNumber()
	{
		return vertexNumber;
	}
	
	/**
	 * @param edgeNumber the edgeNumber to set
	 */
	public void setEdgeNumber(final int edgeNumber)
	{
		this.edgeNumber = edgeNumber;
	}
	
	/**
	 * @return the edgeNumber
	 */
	public int getEdgeNumber()
	{
		return edgeNumber;
	}
	
	/**
	 * @param edgeArray the edgeArray to set
	 */
	public void setEdgeArray(final Edge[] edgeArray)
	{
		this.edgeArray = edgeArray;
	}
	
	/**
	 * @return the edgeArray
	 */
	public Edge[] getEdgeArray()
	{
		return edgeArray;
	}
	
	/**
	 * @param vertexArray the vertexArray to set
	 */
	public void setVertexArray(final Vertex[] vertexArray)
	{
		this.vertexArray = vertexArray;
	}
	
	/**
	 * @return the vertexArray
	 */
	public Vertex[] getVertexArray()
	{
		return vertexArray;
	}
	
	/**
	 * @param graphAdjancencyArray the graphAdjancencyArray to set
	 */
	public void setGraphAdjancencyArray(final Vertex[][] graphAdjancencyArray)
	{
		this.graphAdjancencyArray = graphAdjancencyArray;
	}
	
	/**
	 * @return the graphAdjancencyArray
	 */
	public Vertex[][] getGraphAdjancencyArray()
	{
		return graphAdjancencyArray;
	}
}
