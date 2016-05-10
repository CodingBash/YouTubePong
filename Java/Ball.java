import java.awt.Point;
import java.awt.Rectangle;

public class Ball {
	private int x;
	private int y;
	private int width;
	private int height;
	private Point velocity;
	private Rectangle circle;

	public Ball(int x, int y, int width, int height) {
		this.x = x;
		this.y = y;
		this.width = width;
		this.height = height;
		circle = new Rectangle(this.x, this.y, this.width, this.height);
		velocity = new Point(0,0);
	}

	public void setX(int x){
		this.x = x;
	}
	public int getX(){
		return this.x;
	}
	public void getY(int y){
		this.y = y;
	}
	public int setY(){
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
	public void setCircle(Rectangle circle){
		this.circle = circle;
	}
	public void setCircle(int x, int y, int width, int height){
		this.circle = new Rectangle(x, y, width, height);
	}
	public Rectangle getCircle(){
		return this.circle;
	}
	public void setVelocity(Point velocity){
		this.velocity = velocity;
	}
	public Point getVelocity(){
		return this.velocity;
	}
}
