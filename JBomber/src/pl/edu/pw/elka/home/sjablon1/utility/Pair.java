package pl.edu.pw.elka.home.sjablon1.utility;

/**
 * Class represents pair of two integers to represent (x,y) position on screen
 * @author Szymon Jablonski
 * @version 1.0
 */
public class Pair
{
	/** First integer */
	private int x;
	/** Second integer */
	private int y;
	
	/** Default constructor of Pair object
	 * 
	 * @param x is x
	 * @param y is y
	 */
	public Pair(final int x, final int y)
	{
		this.x = x;
		this.y = y;	
	}

	/**
	 * @param x the x to set
	 */
	public void setX(final int x)
	{
		this.x = x;
	}

	/**
	 * @return the x
	 */
	public int getX()
	{
		return x;
	}

	/**
	 * @param y the y to set
	 */
	public void setY(final int y)
	{
		this.y = y;
	}

	/**
	 * @return the y
	 */
	public int getY()
	{
		return y;
	}
}
