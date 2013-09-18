package pl.edu.pw.elka.home.sjablon1.view;

import java.awt.Toolkit;

/**
 * Class represents view of white and black Bomberman face image from MenuView.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class MenuBomberView extends TileView
{
	/**
	 * Constructor of MenuBombermanView object. The image of MenuBombers is read from File
	 * 
	 * @param menuBomberImageFileName is the name of MenuBomber image file
	 * @param positionX is x position where MenuBomberView object will be painted 
	 * @param positionY is y position where MenuBomberView object will be painted
	 */
	public MenuBomberView(final String menuBomberImageFileName,final int positionX,final int positionY)
	{
		this.setTilePositionX(positionX);
		this.setTilePositionY(positionY);
		this.setTileImage(Toolkit.getDefaultToolkit().getImage(menuBomberImageFileName));	
	}
	
}
