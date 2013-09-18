package pl.edu.pw.elka.home.sjablon1.view;	

import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import javax.swing.JPanel;


/**
 * Class represent the View of the biggest part of GameSpace, GameBoardView the arena on
 * which the game/fight took place. GameBoardView is made by three types of Tile:
 * WallTile, BackgroundTile and BrickTile.  
 * @author Szymon Jablonski
 * @version 1.0
 */
public class GameBoardView extends JPanel
{
	/**Object that store BackgroundTile image.*/
	private BackgroundTileView backgroundTile;
	/**Object that store BrickTile image.*/
	private BrickTileView brickTile;
	/**Object that store WallTile image.*/
	private WallTileView  wallTile;
	/**Number represents GameBoard Model x dimension*/
	private int dimensionX;
	/**Number represents GameBoard Model x dimension*/
	private int dimensionY;
	/**Array represents GameBoardView logical structure */
	private char[][] boardLogicalStructure;
	
	/**
	 * Default constructor of GameBoardView object.
	 */
	public GameBoardView()
	{
		super();
		this.setSize(680, 520);
		this.setOpaque(false);
		backgroundTile = new BackgroundTileView();
		brickTile = new BrickTileView();
		wallTile = new WallTileView();
	}
	
	@Override
	/**
	 * Override method that paints Component.
	 * 
	 * @param g is Graphics context. 
	 */
	public void paintComponent(Graphics g)
	{
		super.paintComponents(g);
		
		Graphics g2D = (Graphics2D) g;
		Image wallImg = wallTile.getTileImage();
		Image brickImg = brickTile.getTileImage();
		Image backgroundImg = backgroundTile.getTileImage();
		
		
		for(int i = 0; i<dimensionX; i++)
		{
			for(int j = 0; j < dimensionY; j++)
			{
				if(boardLogicalStructure[i][j] == '#')
					g2D.drawImage(wallImg,40*i,40*j,this);
				
				if(boardLogicalStructure[i][j] == '*')
					g2D.drawImage(backgroundImg,40*i,40*j,this);
				
				if(boardLogicalStructure[i][j] == '?')
					g2D.drawImage(brickImg,40*i,40*j,this);	
			}
		}
	}
	

	/**
	 * @param backgroundTile the backgroundTile to set
	 */
	public void setBackgroundTile(final BackgroundTileView backgroundTile)
	{
		this.backgroundTile = backgroundTile;
	}
	
	/**
	 * @return the backgroundTile
	 */
	public BackgroundTileView getBackgroundTile()
	{
		return backgroundTile;
	}
	
	/**
	 * @param brickTile the brickTile to set
	 */
	public void setBrickTile(final BrickTileView brickTile)
	{
		this.brickTile = brickTile;
	}
	
	/**
	 * @return the brickTile
	 */
	public BrickTileView getBrickTile()
	{
		return brickTile;
	}
	
	/**
	 * @param wallTile the wallTile to set
	 */
	public void setWallTile(final WallTileView wallTile)
	{
		this.wallTile = wallTile;
	}
	
	/**
	 * @return the wallTile
	 */
	public WallTileView getWallTile()
	{
		return wallTile;
	}

	/**
	 * @param dimensionX the dimensioX to set
	 */
	public void setDimensionX(final int dimensionX)
	{
		this.dimensionX = dimensionX;
	}

	/**
	 * @return the dimensioX
	 */
	public int getDimensionX()
	{
		return dimensionX;
	}

	/**
	 * @param dimensionY the dimensionY to set
	 */
	public void setDimensionY(final int dimensionY)
	{
		this.dimensionY = dimensionY;
	}

	/**
	 * @return the dimensionY
	 */
	public int getDimensionY()
	{
		return dimensionY;
	}

	/**
	 * @param boardLogicalStructure the boardLogicalStructure to set
	 */
	public void setBoardLogicalStructure(final char[][] boardLogicalStructure)
	{
		this.boardLogicalStructure = boardLogicalStructure;
	}

	/**
	 * @return the boardLogicalStructure
	 */
	public char[][] getBoardLogicalStructure()
	{
		return boardLogicalStructure;
	}
	
}
