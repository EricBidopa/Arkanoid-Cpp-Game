#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;

int main()
{
  srand(time(0));

  RenderWindow app(VideoMode(520, 450), "Arkanoid Game");
  app.setFramerateLimit(60);

  Texture t1, t2, t3, t4;
  t1.loadFromFile("images/block01.png");
  t2.loadFromFile("images/background001.jpg");
  t3.loadFromFile("images/ball.png");
  t4.loadFromFile("images/paddle.png");

  Sprite sBackground(t2), sBall(t3), sPaddle(t4);
  sPaddle.setPosition(300, 440);

  Sprite block[1000];

  int n = 0;
  for (int i = 1; i <= 10; i++)
    for (int j = 1; j <= 10; j++)
    {
      block[n].setTexture(t1);
      block[n].setPosition(i * 43, j * 20);
      n++;
    }

  float dx = 3; // to slow down horizontal movement
  float dy = 3; // to slow down vertical movement
  float x = 300;
  float y = 300;

  while (app.isOpen())
  {
    Event e;
    while (app.pollEvent(e))
    {
      if (e.type == Event::Closed)
        app.close();
    }

    x += dx;
    for (int i = 0; i < n; i++)
      if (FloatRect(x + 3, y + 3, 6, 6).intersects(block[i].getGlobalBounds()))
      {
        block[i].setPosition(-100, 0);
        dx = -dx;
      }

    y += dy;

    // For noobs, here is what the for loops below actually does.Explained in perfect words, i think :)
    /*he first "for" loop checks for collision between the ball and the blocks.
    If a collision is detected, the block is removed from the screen and the
    vertical speed of the ball is reversed (to make it bounce back).
The second "if" statement checks if the ball has hit the left or right edge
 of the screen, and if so, reverses the horizontal speed of the ball to make it bounce back.
The third and fourth "if" statements check if the ball has hit the top or bottom
edge of the screen, and if so, reverses the vertical speed of the ball to make it bounce back.
The fifth and sixth "if" statements check if the left or right arrow key is pressed,
and moves the paddle accordingly.
The seventh "if" statement checks for collision between the ball and the paddle.
 If a collision is detected, the vertical speed of the ball is randomly set to a negative value,
 making it bounce back in a different direction.
The last line sets the new position of the ball*/
    for (int i = 0; i < n; i++)
      if (FloatRect(x + 3, y + 3, 6, 6).intersects(block[i].getGlobalBounds()))
      {
        block[i].setPosition(-100, 0);
        dy = -dy;
      }

    if (x < 0 || x > 520)
      dx = -dx;
    if (y < 0 || y > 450)
      dy = -dy;

    if (Keyboard::isKeyPressed(Keyboard::Right))
      sPaddle.move(6, 0);
    if (Keyboard::isKeyPressed(Keyboard::Left))
      sPaddle.move(-6, 0);

    if (FloatRect(x, y, 12, 12).intersects(sPaddle.getGlobalBounds()))
      dy = -(rand() % 5 + 2);

    sBall.setPosition(x, y);

    app.clear();
    app.draw(sBackground);
    app.draw(sBall);
    app.draw(sPaddle);

    for (int i = 0; i < n; i++)
      app.draw(block[i]);

    app.display();
  }

  return 0;
}
