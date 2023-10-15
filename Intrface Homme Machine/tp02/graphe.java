import javax.swing.*;
import javax.swing.colorchooser.ColorSelectionModel;
import javax.swing.plaf.ColorUIResource;
import javax.swing.text.AttributeSet.ColorAttribute;
import java.awt.*;
import java.awt.geom.*;
import java.util.Random;

public class graphe extends JFrame implements Runnable {
  Thread anime;
  int x=10;
  int y; 
  int dt=100; 
    public graphe(){
        super("exo 01 ");
        setSize(700,600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
       anime = new Thread(this);
       anime.start();
    } 
    public void dessin(Graphics g){
        /*g.setFont(new Font ( "Arial", Font.BOLD , 16));
        g.drawString("chaine",50 ,50);*/

     /* g.setFont(new Font ( "Arial", Font.BOLD , 16));
        int careé;
        double racine; 
        int j=0;
        for(int i=0;i<=30;i++){
         g.setColor(new ColorUIResource(50+(3*i),0,0));
          careé=i*i; 
          racine=Math.sqrt(i);
          g.drawString("nombre :="+i+"    carrée = "+careé+"   la racine ="+racine+"" , 50 , 100+j);
          j=j+15;
        }*/
        
      Graphics2D g2d = (Graphics2D)g;
      g2d.setFont(new Font ("Arial",Font.BOLD,16));
      g2d.rotate (x+10, 300, 500);
      g2d.drawString("Bienvenu ",300,500);

      /*Graphics2D g2=(Graphics2D)g;
      Rectangle2D  monRect= new Rectangle2D.Double(100,100,150,150);
      String str = String.valueOf(monRect.getBounds().x);
      String stry= String.valueOf(monRect.getBounds().y);
      g2.drawString("x"+str+ " y "+stry+"");
      g2.draw(monRect);
      g2.scale(3, 1.5);
      g2.draw(monRect);
      Ellipse2D  monElipse= new Ellipse2D.Double(70,80,100,100);
      g2.draw(monElipse);*/
      
      



    }

    
    public void run () { // corps du thread d'animation
    for (int i=10; i<5000; i++) {
      /*x=new Random().nextInt(200);
      y=new Random().nextInt(200); */
      x++; 

      try { Thread.sleep (dt);}
      catch (InterruptedException e) {}
      repaint () ; 
    }
}

    public void paint(Graphics g) {
        super.paint(g); // paint existe dans JFrame
        dessin(g); 
    }
    
     public static void main(String[] args) {
        new graphe().setVisible(true);
        
    };
}
