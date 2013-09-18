package pl.edu.pw.elka.home.sjablon1.view;

import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.MediaTracker;
import java.awt.Toolkit;

import javax.swing.JPanel;

/**
 * Class represents basic part of GameBoard - the Tile, which is base of every graphics/GUI
 * element of Game. It is something like Canvas for JBomber graphics.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class TileView extends JPanel
{
	/** Tile image height */
	private int tileHeight;
	/** Tile image width */
	private int tileWidth;
	/**Tile Image object */
	private Image tileImage;
	/**Position x of screen where paint Tile */
	private int tilePositionX;
	/**Position y of screen where paint Tile */
	private int tilePositionY;
	
	/**
	 * Default constructor of TileView object.
	 */
	public TileView()
	{
		
	}
	
	/**
	 * Constructor of TileView object that takes coordinations on witch TileView
	 * object will be painted.
	 * 
	 * @param positionX is X position of screen where TileView will be painted
	 * @param positionY is Y position of screen where TileView will be painted
	 */
	public TileView(final int positionX,final int positionY)
	{
		this.tilePositionX = positionX;
		this.tilePositionY = positionY;
	}
	
	/**
	 * Constructor of TileView object that takes Image object as parameter.
	 * 
	 * @param tileImage is TileView objects Image
	 */
	public TileView(final Image tileImage)
	{
		
		this.setTileImage(tileImage);
	}
	
	/**
	 * Constructor of TileView object that takes imageFile name as parameter.
	 * 
	 * @param imageFileName is name of file that contains TileView image.
	 */
	public TileView(final String imageFileName)
	{
		MediaTracker mediaTracker = new MediaTracker(this);
		this.setTileImage(Toolkit.getDefaultToolkit().getImage(imageFileName));	
		mediaTracker.addImage(this.getTileImage(), 0);
		
	    try
	    {
	      mediaTracker.waitForID(0);
	    }
	    catch (InterruptedException e) 
	    {
	      System.out.println(e);
	    }		
	}
	
	/**
	 * The most useful constructor of TileView object. Take all important parameters
	 * like imageFileName, positionX and positionY of painting graphics.
	 * 
	 * @param imageFileName is name of file that contains graphic
	 * @param positionX is x position where component that will be painted.
	 * @param positionY is y position where component that will be painted.
	 */
	public TileView(final String imageFileName,final int positionX,final int positionY)
	{
		MediaTracker mediaTracker = new MediaTracker(this);
		this.setTileImage(Toolkit.getDefaultToolkit().getImage(imageFileName));	
		mediaTracker.addImage(this.getTileImage(), 0);
		
	    try
	    {
	      mediaTracker.waitForID(0);
	    }
	    catch (InterruptedException e) 
	    {
	      System.out.println(e);
	    }	
	    
		this.setTilePositionX(positionX);
		this.setTilePositionY(positionY);
	}
	
	@Override
	/**
	 * Method that paint TileView component object.
	 */
	public void paintComponent(Graphics g)
	{
		super.paintComponents(g);
		Graphics2D g2D = (Graphics2D) g;
		g2D.drawImage(tileImage, tilePositionX, tilePositionY, this);
	}
	
	/**
	 * @param tileHeight the tileHeight to set
	 */
	public void setTileHeight(final int tileHeight)
	{
		this.tileHeight = tileHeight;
	}
	
	/**
	 * @return the tileHeight
	 */
	public int getTileHeight()
	{
		return tileHeight;
	}
	
	/**
	 * @param tileWidth the tileWidth to set
	 */
	public void setTileWidth(final int tileWidth)
	{
		this.tileWidth = tileWidth;
	}
	
	/**
	 * @return the tileWidth
	 */
	public int getTileWidth()
	{
		return tileWidth;
	}
	
	/**
	 * @param tileImage the tileImage to set
	 */
	public void setTileImage(final Image tileImage)
	{
		this.tileImage = tileImage;
	}
	
	/**
	 * @return the tileImage
	 */
	public Image getTileImage()
	{
		return tileImage;
	}
	
	/**
	 * @param tilePositionX the tilePositionX to set
	 */
	public void setTilePositionX(final int tilePositionX)
	{
		this.tilePositionX = tilePositionX;
	}
	
	/**
	 * @return the tilePositionX
	 */
	public int getTilePositionX()
	{
		return tilePositionX;
	}
	
	/**
	 * @param tilePositionY the tilePositionY to set
	 */
	public void setTilePositionY(final int tilePositionY)
	{
		this.tilePositionY = tilePositionY;
	}
	
	/**
	 * @return the tilePositionY
	 */
	public int getTilePositionY()
	{
		return tilePositionY;
	}
	
}
