package pl.edu.pw.elka.home.sjablon1.view;

import java.awt.Color;
import java.awt.Insets;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.concurrent.ArrayBlockingQueue;
import javax.swing.JFrame;
import javax.swing.JLayeredPane;

import pl.edu.pw.elka.home.sjablon1.view.event.GameEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.enemy.EnemyMoveDownEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.enemy.EnemyMoveLeftEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.enemy.EnemyMoveRightEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.enemy.EnemyMoveUpEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.enemy.EnemyPlantBombEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.enemy.EnemyStopEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.player.PlayerMoveDownEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.player.PlayerMoveLeftEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.player.PlayerMoveRightEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.player.PlayerMoveUpEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.player.PlayerPlantBombEvent;
import pl.edu.pw.elka.home.sjablon1.view.event.player.PlayerStopEvent;


/**
 * Class represents view of Game Menu from with User can start New Game, Options,Credits
 * and Exit game. It is first interactive element of Game, witch is displayed after Introduction
 * animation.
 * @author Szymon Jablonski
 * @version 1.0
 */
public class GameView extends JFrame implements KeyListener
{
	/** Object of GameBoardView - background, once painted part of GameView object */
	private GameBoardView gameBoardView;
	/** Object of Player in GameView */
	private PlayerMoveAnimation playerAnimation;
	/** Object of Enemy in GameView */
	private EnemyMoveAnimation enemyAnimation;
	/** Array of BombAnimation objects */
	private BombAnimation[] bombAnimationArray;
	/** Array of ExplosionAnimation objects */
	private ExplosionAnimation[] explosionAnimationArray;
	/** Array of Bomb PowerUp animation */
	private PowerUpAnimation[] bombPowerUp;
	/** Array of Speed PowerUp animation */
	private PowerUpAnimation[] speedPowerUp;
	/** Array of Explosion PowerUp animation */
	private PowerUpAnimation[] explosionPowerUp; 
	/** Object of JLayeredPane used to display game in few layers */
	private JLayeredPane gameViewLayer;
	/** Blocking queue used to add occurred Events to communicate with Controller Unit */
	private ArrayBlockingQueue<GameEvent> blockingEventQueue;
	
	
	/**
	 * Constructor of GameView object. Initialize inner game main frame.
	 * 
	 * @param blockingEventQueue is queue for event communications between, Model, View and
	 * 		  Controller Unit.
	 */
	public GameView(ArrayBlockingQueue<GameEvent> blockingEventQueue)
	{
		super("JBomber::Game");
		gameViewLayer = new JLayeredPane();
		
		this.setBombAnimationArray(new BombAnimation[10]);
		this.setExplosionAnimationArray(new ExplosionAnimation[10]);
		this.setSpeedPowerUp(new PowerUpAnimation[20]);
		this.setBombPowerUp(new PowerUpAnimation[20]);
		this.setExplosionPowerUp(new PowerUpAnimation[20]);
		
		this.setArrayBlockingEventQueue(blockingEventQueue);
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
	
	/**
	 * @param gameBoardView the gameBoardView to set
	 */
	public void setGameBoardView(final GameBoardView gameBoardView)
	{
		this.gameBoardView = gameBoardView;
		this.getGameViewLayer().add(this.gameBoardView,new Integer(0));
		this.getContentPane().add(this.getGameViewLayer());
	}

	/**
	 * @return the gameBoardView
	 */
	public GameBoardView getGameBoardView()
	{
		return gameBoardView;
	}

	
	/**
	 * @param gameViewLayer the gameViewLayer to set
	 */
	public void setGameViewLayer(final JLayeredPane gameViewLayer)
	{
		this.gameViewLayer = gameViewLayer;
	}

	/**
	 * @return the gameViewLayer
	 */
	public JLayeredPane getGameViewLayer()
	{
		return gameViewLayer;
	}
	
	/**
	 * @param playerAnimation the playerAnimation to set
	 */
	public void setPlayerAnimation(final PlayerMoveAnimation playerAnimation)
	{
		this.playerAnimation = playerAnimation;
		this.getGameViewLayer().add(this.playerAnimation,new Integer(3));				
		this.addKeyListener(this);
		this.setFocusable(true);
		this.getContentPane().add(this.getGameViewLayer());
	}

	/**
	 * @return the playerAnimation
	 */
	public PlayerMoveAnimation getPlayerAnimation()
	{
		return playerAnimation;
	}
	
	/**
	 * @param enemyAnimation the enemyAnimation to set
	 */
	public void setEnemyAnimation(final EnemyMoveAnimation enemyAnimation)
	{
		this.enemyAnimation = enemyAnimation;
		this.getGameViewLayer().add(this.enemyAnimation,new Integer(3));				
		this.getContentPane().add(this.getGameViewLayer());
	}

	/**
	 * @return the enemyAnimation
	 */
	public EnemyMoveAnimation getEnemyAnimation()
	{
		return enemyAnimation;
	}

	@Override
	/**
	 * Method that serving occurred KeyEvents of GameView. It defines what will happen
	 * when some Key is Pressed. It fires another Event like
	 * PlayerMoveLeft and put it in BlockingQueuee to communicate with Controller unit. 
	 * 
	 * @param event is caught event by KeyListener added to GameView.
	 */
	public void keyPressed(final KeyEvent event)
	{

		switch(event.getKeyCode())
		{
			case KeyEvent.VK_W:
				this.getPlayerAnimation().firePlayerMoveUpEvent(new PlayerMoveUpEvent(this), blockingEventQueue);
				break;
			case KeyEvent.VK_S:
				this.getPlayerAnimation().firePlayerMoveDownEvent(new PlayerMoveDownEvent(this), blockingEventQueue);
				break;
			case KeyEvent.VK_A:
				this.getPlayerAnimation().firePlayerMoveLeftEvent(new PlayerMoveLeftEvent(this), blockingEventQueue);
				break;
			case KeyEvent.VK_D:	
				this.getPlayerAnimation().firePlayerMoveRightEvent(new PlayerMoveRightEvent(this), blockingEventQueue);
				break;
			case KeyEvent.VK_K:
				this.getPlayerAnimation().firePlayerPlantBombEvent(new PlayerPlantBombEvent(this), blockingEventQueue);
				break;
				
			case KeyEvent.VK_ESCAPE:
				System.exit(0);
				break;
				
			case KeyEvent.VK_UP:
				this.getEnemyAnimation().fireEnemyMoveUpEvent(new EnemyMoveUpEvent(this), blockingEventQueue);
				break;
			case KeyEvent.VK_DOWN:
				this.getEnemyAnimation().fireEnemyMoveDownEvent(new EnemyMoveDownEvent(this), blockingEventQueue);
				break;
			case KeyEvent.VK_LEFT:
				this.getEnemyAnimation().fireEnemyMoveLeftEvent(new EnemyMoveLeftEvent(this), blockingEventQueue);
				break;
			case KeyEvent.VK_RIGHT:	
				this.getEnemyAnimation().fireEnemyMoveRightEvent(new EnemyMoveRightEvent(this), blockingEventQueue);
				break;
			case KeyEvent.VK_SPACE:
				this.getEnemyAnimation().fireEnemyPlantBombEvent(new EnemyPlantBombEvent(this), blockingEventQueue);
				break;
				
		}
	}

	@Override
	/**
	 * Method that serving occurred KeyEvents of GameView. It defines what will happen
	 * when some Key is Released. It fires another Event like
	 * PlayerMoveLeft and put it in BlockingQueuee to communicate with Controller unit. 
	 * 
	 * @param event is caught event by KeyListener added to GameView.
	 */
	public void keyReleased(final KeyEvent event)
	{
		if (event.getKeyCode() == KeyEvent.VK_S || event.getKeyCode() ==  KeyEvent.VK_W
			||event.getKeyCode() == KeyEvent.VK_A || event.getKeyCode() == KeyEvent.VK_D)
		{
			this.getPlayerAnimation().firePlayerStopEvent(new PlayerStopEvent(this), blockingEventQueue);
		}
		
		if (event.getKeyCode() == KeyEvent.VK_UP || event.getKeyCode() ==  KeyEvent.VK_DOWN
				||event.getKeyCode() == KeyEvent.VK_LEFT || event.getKeyCode() == KeyEvent.VK_RIGHT)
		{
			this.getEnemyAnimation().fireEnemyStopEvent(new EnemyStopEvent(this), blockingEventQueue);
		}	
	}

	@Override
	/**
	 * Method that serving occurred KeyEvents of GameView. It defines what will happen
	 * when some Key is Typed. It fires another Event like
	 * PlayerMoveLeft and put it in BlockingQueuee to communicate with Controller unit. 
	 * 
	 * @param event is caught event by KeyListener added to GameView.
	 */
	public void keyTyped(final KeyEvent event)
	{
		

	}
	
	/**
	 * @param bombAnimationArray the bombAnimationArray to set
	 */
	public void setBombAnimationArray(final BombAnimation[] bombAnimationArray)
	{
		this.bombAnimationArray = bombAnimationArray;
	}

	/**
	 * @return the bombAnimationArray
	 */
	public BombAnimation[] getBombAnimationArray()
	{
		return bombAnimationArray;
	}

	/**
	 * @param explosionAnimationArray the explosionAnimationArray to set
	 */
	public void setExplosionAnimationArray(final ExplosionAnimation[] explosionAnimationArray)
	{
		this.explosionAnimationArray = explosionAnimationArray;
	}

	/**
	 * @return the explosionAnimationArray
	 */
	public ExplosionAnimation[] getExplosionAnimationArray()
	{
		return explosionAnimationArray;
	}

	/**
	 * @param bombPowerUp the bombPowerUp to set
	 */
	public void setBombPowerUp(final PowerUpAnimation[] bombPowerUp)
	{
		this.bombPowerUp = bombPowerUp;
	}

	/**
	 * @return the bombPowerUp
	 */
	public PowerUpAnimation[] getBombPowerUp()
	{
		return bombPowerUp;
	}

	/**
	 * @param speedPowerUp the speedPowerUp to set
	 */
	public void setSpeedPowerUp(final PowerUpAnimation[] speedPowerUp)
	{
		this.speedPowerUp = speedPowerUp;
	}

	/**
	 * @return the speedPowerUp
	 */
	public PowerUpAnimation[] getSpeedPowerUp()
	{
		return speedPowerUp;
	}

	/**
	 * @param explosionPowerUp the explosionPowerUp to set
	 */
	public void setExplosionPowerUp(final PowerUpAnimation[] explosionPowerUp)
	{
		this.explosionPowerUp = explosionPowerUp;
	}

	/**
	 * @return the explosionPowerUp
	 */
	public PowerUpAnimation[] getExplosionPowerUp()
	{
		return explosionPowerUp;
	}
	
}
