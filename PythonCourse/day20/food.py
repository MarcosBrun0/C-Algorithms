from turtle import Turtle
import random

class Food(Turtle):
   
   
   
 def __init__(self):
        super().__init__()
        self.shape("square")
        self.color("red")
        self.penup()
        self.shapesize(1,1)
        self.speed(0)
        self.update()

  

 def update(self):
    correctpos = False
    while correctpos == False:
        random_y = random.randint(-280,260)
        random_x = random.randint(-280,280)
        if random_x%20 == 0 and random_y%20 == 0:
            self.goto(random_x,random_y)
            correctpos = True