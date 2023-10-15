import javax.swing.*;
import javax.swing.plaf.ColorUIResource;
import java.awt.*;
public class graph extends JFrame{
    public graph(){
        super("Exemple de dessin dans un Jframe"); 
        setSize(800,800); 
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
        setLocationRelativeTo(null);
    } 

    public void dessin ( Graphics g){
      
          
    }
            
    public void paint(Graphics g){
        super.paint(g);
        dessin(g);           
    }    
     public static void main(String[] args) {
        new graph().setVisible(true);  
    };
        
}
    

    
