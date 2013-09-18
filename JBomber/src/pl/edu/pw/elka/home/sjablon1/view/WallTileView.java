package pl.edu.pw.elka.home.sjablon1.view;

import java.awt.MediaTracker;
import java.awt.Toolkit;
import java.io.IOException;

/**
 * Class represents part of GameBoardView graphics the WallTileView graphic.
 * It defines what graphic type of image WallTile is and paint it. 
 * @author Szymon Jablonski
 * @version 1.0
 */
public class WallTileView extends TileView
{
	/**
	 * Default constructor of WallTileView object.
	 * 
	 * @throws IOException when occurred error while loading image from File. 
	 */
	public WallTileView()
	{
		this.setTileHeight(40);
		this.setTileWidth(40);
		
		MediaTracker mediaTracker = new MediaTracker(this);
		this.setTileImage(Toolkit.getDefaultToolkit().getImage("wallTile.png"));	
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
	 * Constructor of WallTileView class. Each Tile have 40 pixel height and width.
	 * The image of Tile is read from File
	 * 
	 * @param wallTileName is the name of wallTile image file
	 * @throws IOException when occurred error while loading image from File. 
	 */
	public WallTileView(final String wallTileName)
	{
		this.setTileHeight(40);
		this.setTileWidth(40);
		
		MediaTracker mediaTracker = new MediaTracker(this);
		this.setTileImage(Toolkit.getDefaultToolkit().getImage(wallTileName));	
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
