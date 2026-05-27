#include <SFML/Graphics.hpp>
using namespace sf;
#include <stdio.h>
using namespace std;
#include <sstream>
#include <SFML/Audio.hpp>

int main() {
   VideoMode vm(300, 300);
   RenderWindow window(vm,"Hello World");
   Font font;
   font.loadFromFile("fonts/KOMIKAP_.ttf");
   Text text;
   text.setFont(font);
   text.setCharacterSize(20);
   text.setString("Hello");
   text.setFillColor(Color::Green);
   FloatRect lb= text.getLocalBounds();
   text.setOrigin((lb.width+lb.left)/2,(lb.top+lb.height)/2);
   text.setPosition(180,150);

   Text text2;
   text2.setFont(font);
   text2.setCharacterSize(20);
   text2.setString("Hello");
   text2.setFillColor(Color::Green);
   FloatRect lb2= text.getLocalBounds();
   text2.setOrigin((lb2.width+lb2.left)/2,(lb2.top+lb2.height)/2);
   text2.setPosition(10,150);

   
//    SoundBuffer sb;
//    sb.loadFromFile("Sound/chop.wav");
//    Sound s;
//    s.setBuffer(sb);

   



   View v;
   Clock c;
   bool pause=true;

   while(window.isOpen()){
        Event e;
        while(window.pollEvent(e)){
            if(e.type==Event::Closed){
                window.close();
            }
            if(e.type==Event::KeyPressed){
                if(e.key.code==Keyboard::R){
                    text.setString("Bye");
                }
                if(e.key.code==Keyboard::Enter){
                    pause=false;
                }
            }
            
        }

        if(Keyboard::isKeyPressed(Keyboard::Escape)){
            window.close();
        }
        if(!pause){
               Time dt = c.restart();
                if(text.getPosition().x>300){
                    text.setPosition (0,text.getPosition ().y);
                }
                else{
                        float position = text.getPosition ().x+(dt.asSeconds()*10);
                        text.setPosition (position,text.getPosition ().y);
                }
                if(text2.getGlobalBounds().intersects(text.getGlobalBounds())){
                    pause=true;
                    text.setString("Game Over");
                    text.setCharacterSize(30);
                    text.setPosition (150,150);
                    // s.play();
                }

        }
       
        // if(Keyboard::isKeyPressed(Keyboard::Left)){
        //     if(text.getPosition().x>300){
        //     text.setPosition (0,text.getPosition ().y);
        //     }
        //     else{
        //         float position = text.getPosition ().x+(dt.asSeconds()*100);
        //         text.setPosition (position,text.getPosition ().y);
        //     }

        // }
        // if(Keyboard::isKeyPressed(Keyboard::Up)){
        //     if(text.getPosition().y<0){
        //         text.setPosition (text.getPosition ().x,150);
        //     }
        //     else{
        //         float position = text.getPosition ().y-(dt.asSeconds()*100);
        //         text.setPosition (text.getPosition ().x,position);
        //     }

        // }
        
        
        window.clear(Color::Red);
        window.draw(text);
        window.draw(text2);
      
        window.display();
   }
   return 0;
}
