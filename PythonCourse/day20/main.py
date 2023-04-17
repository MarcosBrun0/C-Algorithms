from turtle import Screen, Turtle
from snake import Snake
from food import Food
from score import Score
import time

screen = Screen()
screen.setup(600,600)
screen.bgcolor("black")
screen.tracer(0)
screen.title("Snake Game")
\

snake = Snake()
food = Food()
score = Score()


#binding keys

screen.listen()
screen.onkey(snake.up,"Up")
screen.onkey(snake.down,"Down")
screen.onkey(snake.left,"Left")
screen.onkey(snake.right,"Right")

game_is_on = True
while game_is_on:
    screen.update()
    time.sleep(0.1)
    snake.move()
    screen.update()

    #detect colission with food
    if snake.head.distance(food)<1:
        food.update()
        score.increase_score()
        snake.extend()


    #detect colission with wall
    if snake.head.xcor() > 281 or snake.head.xcor() < -281 or snake.head.ycor() > 281 or snake.head.ycor()< -281 :
        game_is_on = False
        score.game_over()

    for segment in snake.segments:
        if segment == snake.head:
            pass
        elif snake.head.distance(segment)<10:
            score.game_over()
            game_is_on = False
screen.exitonclick()