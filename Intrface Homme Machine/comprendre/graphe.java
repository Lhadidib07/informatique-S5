import javax.swing.*;
import javax.swing.plaf.ColorUIResource;
import javax.swing.text.AttributeSet.ColorAttribute;

import java.awt.*;
import java.lang.ProcessBuilder.Redirect;
public class graphe extends JFrame {
    public graphe(){
        super("dessin d'un rectangle dans un JFrame ");
        setSize(900,900);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
    } 
    public void dessin(Graphics g){
        
         g.setColor(Color.red);
         g.fillRect(100 ,75, 70, 70);
         g.setColor(Color.blue);
         g.drawRect(100 ,75, 70, 70);

         g.setColor(Color.green);
         g.fillRect(200 ,75, 70, 70);
         g.setColor(Color.green);
         g.drawRect(200, 75, 70, 70);

         g.setColor(Color.blue);
         g.fillRect(300 ,75, 70, 70);
         g.setColor(Color.blue);
         g.drawRect(300, 75, 70, 70);

         g.setColor(Color.red);
         g.fillOval(100 ,160, 70, 70);
         g.setColor(Color.red);
         g.drawOval(100 ,160, 70, 70);

         g.setColor(Color.green);
         g.fillOval(200 ,160, 70, 70);
         g.setColor(Color.green);
         g.drawOval(200 ,160, 70, 70); 

         g.setColor(Color.blue);
         g.fillOval(300 ,160, 70, 70);
         g.setColor(Color.blue);
         g.drawOval(300 ,160, 70, 70);
        int i,j=2;
        for(i=0;i<=200;i++){
            g.drawRect(350, 250, j, j);
            j=j+2;
        } 
        
        for (i=0; i<200; i=i+2){
        g.setColor(new ColorUIResource(255-i, i+i, i+(i+2)));
        g.drawLine (400, i, 250, i); 
        }
        int x3[]={100,120,120,100,80,60,60,80};
        int y3[]={400,380,360,340,340,360,380,400};
        g.setColor(Color.black);
        g.drawPolygon(x3,y3,8);

        int x[]={100,200,100}; 
        int y[]={700,700,550}; 
        g.setColor(Color.red);
        g.drawPolygon(x,y,3);
        int x1[]={110,180,110};
        int y1[]={695,695,580};
        g.setColor(Color.orange);
        g.drawPolygon(x1,y1,3);
        int x2[]={117,160,117};
        int y2[]={690,690,600};
        g.setColor(Color.blue);
        g.drawPolygon(x2,y2,3);
    }
    public void paint(Graphics g) {
        super.paint(g); // paint existe dans JFrame
        dessin (g); }
     public static void main(String[] args) {
        new graphe().setVisible(true);
    };
}
   

