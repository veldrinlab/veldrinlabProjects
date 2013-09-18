package pl.edu.pw.elka.home.sjablon1.controller;

/**
 * Class represents an interface of an abstract class used to declare the visit operations 
 * for all the types of visitable classes.
 * @author Szymon Jablonski
 * @version 1.0
 */
public interface Visitor
{
	public void visit(ExecuteNewGame executeObject);
	public void visit(ExecuteExitGame executeObject);
	public void visit(ExecuteOptions executeObject);
	public void visit(ExecuteCredits executeObject);
	public void visit(ExecuteBackToMenu executeObject);
	public void visit(ExecutePlayerMoveUp executeObject);
	public void visit(ExecutePlayerMoveDown executeObject);
	public void visit(ExecutePlayerMoveLeft executeObject);
	public void visit(ExecutePlayerMoveRight executeObject);
	public void visit(ExecutePlayerChangeState executeObject);
	public void visit(ExecutePlayerStop executeObject);
	public void visit(ExecutePlayerPlantBomb executeObject);
	public void visit(ExecuteBombChangeState executeObject);
	public void visit(ExecuteBombBlowUp executeObject);
	public void visit(ExecuteExplosionStart executeObject);
	public void visit(ExecuteExplosionChangeState executeObject);
	public void visit(ExecuteExplosionEnd executeObject);
	public void visit(ExecuteEnemyMoveUp executeObject);
	public void visit(ExecuteEnemyMoveDown executeObject);
	public void visit(ExecuteEnemyMoveLeft executeObject);
	public void visit(ExecuteEnemyMoveRight executeObject);
	public void visit(ExecuteEnemyChangeState executeObject);
	public void visit(ExecuteEnemyStop executeObject);
	public void visit(ExecuteEnemyPlantBomb executeObject);
	
}
