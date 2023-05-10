#include<iostream>
#include<time.h>
#include<conio.h>
#include<stddef.h>

using namespace std;

enum eDir {STOP = 0 , LEFT =  1 , UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6}; // Yon bilgileri

class cBall

{

    private:

    int x;
    int y;

    int originalX;
    int originalY;

    eDir direction; // Yon bilgileri
    
    public:

    cBall(int posX, int posY) // Topun konum bilgileri

    {
        originalX = posX;
        originalY = posY;
        x = posX;
        y = posY;
        direction = STOP;

    }

    void Reset() // Topun konum bilgilerini sıfırlama

    {

        x = originalX;
        y = originalY;
        direction = STOP;

    }

    void changeDirection(eDir d) // Yön bilgilerini değiştirme

    {

        direction = d;

    }

    void randomDirection() // Rastgele yön bilgisi oluşturma

    {

        direction = (eDir)((rand() % 6) + 1);

    }

    inline int getX() { return x; } // Topun x koordinatını döndürme
    inline int getY() { return y; } // Topun y koordinatını döndürme
    inline eDir getDirection() { return direction; } // Topun yön bilgisini döndürme

   
    void Move() // Topun hareket etmesi

    {

        switch (direction)

        {

        case STOP:

            break;

        case LEFT:

            x--;

            break;

        case RIGHT:

            x++;

            break;

        case UPLEFT:

            x--;

            y--;

            break;

        case DOWNLEFT:

            x--;

            y++;

            break;

        case UPRIGHT:

            x++;

            y--;

            break;

        case DOWNRIGHT:

            x++;

            y++;

            break;

        default:

            break;

        }

    }

    friend ostream & operator<<(ostream & o, cBall c) // Topun konum bilgilerini ekrana yazdırma

    {

        o << "Ball [" << c.x << "," << c.y << "][" << c.direction << "]";

        return o;

    }


};
  
  class cOrta

  {

    private:

    int x;
    int y;

    int originalX;
    int originalY;

    public:

    cOrta()

    {
       
        x = 0;
        y = 0;
       
    }

    cOrta(int posX, int posY) : cOrta() // Topun konum bilgileri

    {
        originalX = posX;
        originalY = posY;
        x = posX;
        y = posY;
        

    }

    inline void Reset() // Topun konum bilgilerini sıfırlama

    {

        x = originalX;
        y = originalY;
        

    }

    inline int getX() { return x; } // Topun x koordinatını döndürme
    int getY() { return y; } // Topun y koordinatını döndürme

    inline void MoveUp() // Topun hareket etmesi

    {

        y--;

    }

    inline void MoveDown() // Topun hareket etmesi

    {

        y++;

    }
  
     friend ostream & operator<<(ostream & o, cOrta c) // Topun konum bilgilerini ekrana yazdırma

    {

        o << "Orta [" << c.x << "," << c.y << "]";

        return o;

    
    }



  };

 class cGameManger // Oyun Yöneticisi

 {
    
    private:
    int width; // Oyun alanı genişliği
    int height; // Oyun alanı yüksekliği
    int score1; // Oyuncu 1 skoru
    int score2; // Oyuncu 2 skoru

    char up1; // Oyuncu 1 için tuş bilgileri
    char down1; // Oyuncu 1 için tuş bilgileri
    char up2;   
    char down2;

    bool quit; // Oyunu bitirmek için kullanılacak değişken

    cBall * ball; // Top nesnesi
    cOrta * player1; // Oyuncu 1 nesnesi
    cOrta * player2; // Oyuncu 2 nesnesi

    public:

    cGameManger(int w , int h)

    {
       
       srand(time(NULL)); // Rastgele sayı üretmek için
       quit = false; // Oyunu bitirmek için kullanılacak değişken
       up1='w'; // Oyuncu 1 için tuş bilgileri
       up2='d'; // Oyuncu 2 için tuş bilgileri
       down1='s'; // Oyuncu 1 için tuş bilgileri
       down2='a'; // Oyuncu 2 için tuş bilgileri
       width = w; // Oyun alanı genişliği
       height = h; // Oyun alanı yüksekliği
       ball = new cBall(w/2, h/2); // Top nesnesi
       player1 = new cOrta(1, h/2 - 3); // Oyuncu 1 nesnesi
       player2 = new cOrta(w - 2, h/2 - 3); // Oyuncu 2 nesnesi

    }

    ~cGameManger()

    {
        delete ball, player1, player2;

    }

    void ScoreUp(cOrta * player) // Skor arttırma

    {

        if (player == player1)

            score1++;

        else if (player == player2)

            score2++;

        ball->Reset(); // Topu sıfırla
        player1->Reset(); // Oyuncu 1'i sıfırla
        player2->Reset(); // Oyuncu 2'yi sıfırla

    }

    void Draw()

    {

        system("cls"); // Ekrani temizle
     
        for (int i = 0; i < width + 2; i++)

            cout << "\xB2";
            cout<<endl;

        for(int i = 0 ; i < height ; i++)

        {

            for (int j = 0; j < width; j++)

            {

                int ballx = ball->getX();
                int bally = ball->getY();

                int player1x = player1->getX();
                int player2x = player2->getX();
                int player1y = player1->getY();
                int player2y = player2->getY();

                if (j == 0)

                    cout << "\xB2";
                
                if (ballx == j && bally == i)

                    cout << "O"; // Topu ekrana yazdır
                else if (player1x == j && player1y == i)

                    cout << "\xDB"; // Oyuncu 1'i ekrana yazdır
                else if (player2x == j && player2y == i)

                    cout << "\xDB"; // Oyuncu 2'yi ekrana yazdır

                  
                else if(player1x == j && player1y + 1 == i)
                    cout<<"\xDB";

                else if(player1x == j && player1y + 2 == i)
                    cout<<"\xDB";

                else if(player1x == j && player1y + 3 == i)
                    cout<<"\xDB";


                else if(player2x == j && player2y + 1 == 1)
                    cout<<"\xDB";

                else if(player2x == j && player2y + 2 == i)
                    cout<<"\xDB";

                else if(player2x == j && player2y + 3 == i)
                    cout<<"\xDB";

        
                else

                    cout << " ";

               if( j==width -1 )

                  cout<<"\xB2";   
            }

            cout << endl;
        }

        for (int  i = 0; i < width + 2; i++)

            cout << "\xB2";
            cout<<endl;
 
        cout<<"Oyuncu 1: "<<score1<<endl<<"Oyuncu 2: "<<score2<<endl;

    }

    void Input() // Bilgi alalım

    {

        ball->Move(); // Topu hareket ettir

        int ballx = ball->getX();
        int bally = ball->getY();
        int player1x = player1->getX();
        int player2x = player2->getX();
        int player1y = player1->getY();
        int player2y = player2->getY();

        if(_kbhit())

        {
            char current = _getch();
            
            if (current == up1)

            
                if (player1y > 0)

                    player1->MoveUp();

            

             if (current == up2)

            
                if (player2y > 0)

                    player2->MoveUp();

        
            if (current == down1)

            
                if (player1y + 4 < height)

                    player1->MoveDown();

            

             if (current == down2)

            
                if (player2y + 4 < height)

                    player2->MoveDown();

                
            

            if(ball->getDirection() == STOP)

                ball->randomDirection();

            if (current == 'q')

                quit = true;


        }

    }

    void Logic() // Giriş Fonksiyonu

    {

        int ballx = ball->getX();
        int bally = ball->getY();
        int player1x = player1->getX();
        int player2x = player2->getX();
        int player1y = player1->getY();
        int player2y = player2->getY();


        //SOL cORTA
        for(int i = 0 ; i < 4 ; i++)

            if(ballx == player1x + 1)

            
                if(bally == player1y + i)
                    ball->changeDirection((eDir)((rand() % 3) + 4));
            

        // SAĞ cORTA

          for(int i = 0 ; i < 4 ; i++)

        
            if(ballx == player2x - 1)

        
                if(bally == player2y + i)
                    ball->changeDirection((eDir)((rand() % 3) + 1));
            


            // alt duvar
            if (bally == height - 1)

                ball->changeDirection(ball->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);

            // üst duvar
            if (bally == 0)

                ball->changeDirection(ball->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);
                  
            // sag duvar
            
            if (ballx == width - 1)

                ScoreUp(player1);

            // sol duvar

            if (ballx == 0)

                ScoreUp(player2);
                
                     
        }

        void Run()

        {

            while(!quit)

            {

                Draw();
                Input();
                Logic();

            }   
        }

 };

int main()

{

    cGameManger c(40, 20); // Oyun alanı genişliği ve yüksekliği
    c.Run();
    return 0;

}
