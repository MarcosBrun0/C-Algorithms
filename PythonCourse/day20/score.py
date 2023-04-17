from turtle import Turtle

class Score(Turtle):
    def __init__(self):
        super().__init__()
        self.color("white")
        self.penup()
        self.goto(0,250)
        self.write("Score: 0", align="center", font=["",20])
        self.ht()
        self.score = 0



    def increase_score(self):
        self.clear()
    
        self.score +=1
        self.write(f"Score:{self.score}", align="center", font=["",20])
        


    def game_over(self):
        self.goto(0,0)
        self.write("GAME OVER",align="center" ,font=["",30])