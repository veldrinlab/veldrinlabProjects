package pl.edu.pw.elka.home.sjablon1.view;

import java.awt.Color;
import java.awt.Insets;
import java.util.concurrent.ArrayBlockingQueue;
import javax.swing.JFrame;
import javax.swing.JLayeredPane;

import pl.edu.pw.elka.home.sjablon1.view.event.GameEvent;


/**
 * Class represents view of Game Menu from with User can start New Game, Options,Credits
 * and Exit game. It is first interactive element of Game, which is displayed after Intro
 * object.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class MenuView extends JFrame
{
	
	/**Object of Game Logo*/
	private LogoView jBomberLogo;
	/**Object White Bomberman Image from Menu object */
	private MenuBomberView whiteBomberImage;
	/**Object Black Bomberman Image from Menu object */
	private MenuBomberView blackBomberImage;
	/**Object of Menu Buttons panel*/
	private MenuButtonPanel menuButtonPanel;
	/**Blocking queue used to add occurred Events to communicate with Controller Unit */
	private ArrayBlockingQueue<GameEvent> blockingEventQueue;

	
	/**
	 * Constructor of MenuView object. Initialize first Frame of Game with Menu.
	 * 
	 * @param blockingEventQueue is queue for event communications between, Model, View and
	 * 		  Controller Unit.
	 */
	public MenuView(ArrayBlockingQueue<GameEvent> blockingEventQueue)
	{
		super("JBomber::Menu");
		JLayeredPane menuLayeredPane = new JLayeredPane();
		this.jBomberLogo = new LogoView("logo.png",145,20);
		this.whiteBomberImage = new MenuBomberView("whiteBomber.png",30,210);
		this.blackBomberImage = new MenuBomberView("blackBomber.png",545,210);
		this.menuButtonPanel = new MenuButtonPanel(blockingEventQueue);
		this.setIconImage(whiteBomberImage.getTileImage());
		
		this.jBomberLogo.setSize(680, 520);
		this.jBomberLogo.setOpaque(false);
		this.whiteBomberImage.setSize(680,520);
		this.whiteBomberImage.setOpaque(false);
		this.blackBomberImage.setSize(680,520);
		this.blackBomberImage.setOpaque(false);
		this.menuButtonPanel.setSize(680, 520);
		this.menuButtonPanel.setOpaque(false);
		
		
		menuLayeredPane.add(menuButtonPanel,new Integer(1));
		menuLayeredPane.add(jBomberLogo, new Integer(2));
		menuLayeredPane.add(whiteBomberImage, new Integer(3));
		menuLayeredPane.add(blackBomberImage, new Integer(4));
		this.getContentPane().add(menuLayeredPane);
		
	
		this.getContentPane().setBackground(Color.white);
		this.setSize(680,520);
		this.setLocationRelativeTo(null);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setResizable(false);
		this.setVisible(true);
		Insets insets = getInsets();
		this.setSize(680+insets.left+insets.right, 520+insets.top+insets.bottom);
		
	}
	
	
	/**
	 * @return the jBomberLogo
	 */
	public LogoView getjBomberLogo()
	{
		return jBomberLogo;
	}
	
	/**
	 * @param jBomberLogo the jBomberLogo to set
	 */
	public void setjBomberLogo(final LogoView jBomberLogo)
	{
		this.jBomberLogo = jBomberLogo;
	}
	
	/**
	 * @return the whiteBomberImgae
	 */
	public MenuBomberView getWhiteBomberImgae()
	{
		return whiteBomberImage;
	}
	
	/**
	 * @param whiteBomberImgae the whiteBomberImgae to set
	 */
	public void setWhiteBomberImgae(final MenuBomberView whiteBomberImgae)
	{
		this.whiteBomberImage = whiteBomberImgae;
	}
	
	/**
	 * @return the blackBomberImage
	 */
	public MenuBomberView getBlackBomberImage()
	{
		return blackBomberImage;
	}
	
	/**
	 * @param blackBomberImage the blackBomberImage to set
	 */
	public void setBlackBomberImage(final MenuBomberView blackBomberImage)
	{
		this.blackBomberImage = blackBomberImage;
	}
	
	/**
	 * @param menuButtonPanel the menuButtonPanel to set
	 */
	public void setMenuButtonPanel(final MenuButtonPanel menuButtonPanel)
	{
		this.menuButtonPanel = menuButtonPanel;
	}

	/**
	 * @return the menuButtonPanel
	 */
	public MenuButtonPanel getMenuButtonPanel()
	{
		return menuButtonPanel;
	}

	/**
	 * @param blockingEventQueue the blockingEventQueue to set
	 */
	public void setArrayBlockingEventQueue(ArrayBlockingQueue<GameEvent> blockingEventQueue)
	{
		this.blockingEventQueue = blockingEventQueue;
	}

	/**
	 * @return the blockingEventQueue
	 */
	public ArrayBlockingQueue<GameEvent> getBlockingEventQueue()
	{
		return blockingEventQueue;
	}

}
