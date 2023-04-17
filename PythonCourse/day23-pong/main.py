from turtle import Screen, Turtle
from paddle import Paddle
screen = Screen()
screen.bgcolor("black")
screen.setup(600,600)


Lpaddle = Paddle((-270,0))
Rpaddle = Paddle((270,0))
screen.listen()
screen.onkey(Lpaddle.up,"w")
screen.onkey(Lpaddle.down,"s")
screen.onkey(Rpaddle.up,"Up")
screen.onkey(Rpaddle.down,"Down")










screen.exitonclick()