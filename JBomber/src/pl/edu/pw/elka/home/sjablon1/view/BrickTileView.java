package pl.edu.pw.elka.home.sjablon1.view;

import java.awt.MediaTracker;
import java.awt.Toolkit;
import java.io.IOException;

/**
 * Class represents part of GameBoardView graphics the BrickTileView graphics.
 * It defines what graphics type of image BrickTile is and paint it. 
 * @author Szymon Jablonski
 * @version 1.0
 */
public class BrickTileView extends TileView
{
	/**
	 * Default constructor of BrickTileView object.
	 * 
	 * @throws IOException when occurred error while loading image from File
	 */
	public BrickTileView()
	{
		this.setTileHeight(40);
		this.setTileWidth(40);
		
		MediaTracker mediaTracker = new MediaTracker(this);
		this.setTileImage(Toolkit.getDefaultToolkit().getImage("brickTile.png"));	
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
	 * Constructor of BrickTileView class. Each Tile have 40 pixel height and width.
	 * The image of Tile is read from File
	 * 
	 * @param brickTileFileName is the name of brickTile image file
	 * @throws IOException when occurred error while loading image from File
	 */
	public BrickTileView(final String brickTileFileName)
	{
		this.setTileHeight(40);
		this.setTileWidth(40);
		
		MediaTracker mediaTracker = new MediaTracker(this);
		this.setTileImage(Toolkit.getDefaultToolkit().getImage(brickTileFileName));	
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

}
