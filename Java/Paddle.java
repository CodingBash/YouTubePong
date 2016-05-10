import java.awt.Point;
import java.awt.Rectangle;

public class Paddle {
	private int x;
	private int y;
	private int width;
	private int height;
	private boolean goingUp;
	private int speed;
	private Rectangle pad;

	public Paddle(int x, int y, int height, int width, int speed) {
		this.x = x;
		this.y = y;
		this.width = width;
		this.height = height;
		this.speed = speed;
		pad = new Rectangle(this.x, this.y, this.height, this.width);
		
	}
	
	public void setX(int x){
		this.x = x;
	}
	public int getX(){
		return this.x;
	}
	public void setY(int y){
		this.y = y;
	}
	public int getY(){
		return this.y;
	}
	public void setWidth(int width){
		this.width = width;
	}
	public int getWidth(){
		return this.width;
	}
	public void setHeight(int height){
		this.height = height;
	}
	public int getHeight(){
		return this.height;
	}
	public void setPad(Rectangle pad){
		this.pad = pad;
	}
	public void setPad(int x, int y, int width, int height){
		this.pad = new Rectangle(x, y, width, height);
	}
	public Rectangle getPad(){
		return this.pad;
	}
	public void setUp(boolean goingUp){
		this.goingUp = goingUp;
	}
	public boolean getUp(){
		return this.goingUp;
	}
	public void setSpeed(int speed){
		this.speed = speed;
	}
	public int getSpeed(){
		return this.speed;
	}
}
