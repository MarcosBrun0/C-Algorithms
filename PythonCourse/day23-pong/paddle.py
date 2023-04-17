from turtle import Turtle

class Paddle(Turtle):
    def __init__(self, position):
        super().__init__()
    
        self.shape("square") 
        self.penup()
        self.shapesize(0.5,3)
        self.color("white")
        self.setheading(90)
        self.goto(position)
       

    def up(self):
       
        self.forward(20)

    def down(self):
    
        self.backward(20)
